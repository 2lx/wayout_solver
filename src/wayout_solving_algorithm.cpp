#include "wayout_solving_algorithm.h"
#include "gaussian_elimination_gf2.h"
#include "num_range.h"

#include <algorithm>
#include <functional>

#include "logging.h"

using namespace std;
using namespace std::placeholders;
using namespace WayOut;

using numit = num_iterator<uint>;
using numrange = num_range<uint>;

void SolvingAlgorithm::calculate_compression_indexes() {
    to_global.clear();
    to_compressed.clear();

    copy_if(numit{0}, numit{m_arena->count()},
            back_inserter(to_global),
            [this](auto n) { return m_arena->tile(n) != Tile::None; });

    transform(numit{0}, numit{m_arena->count()},
              back_inserter(to_compressed),
              [this, diff{0u}](auto n) mutable {
                    if (m_arena->tile(n) == Tile::None) { diff++; };
                    return n - diff;
              });

    compressed_count = static_cast<uint>(to_global.size());
}

bitmatrix SolvingAlgorithm::compress_toggle_matrix() const {
    bitmatrix compressed_toggles;

    for (const auto n: numrange(0u, compressed_count)) {
        bool trigger_dbldots = false;

        for (const auto nbgi: m_arena->neighbors(to_global[n])) {
            trigger_dbldots |= m_arena->tile(nbgi) == Tile::DblDot;
            compressed_toggles[to_compressed[nbgi]][n] = true;
        }

        if (trigger_dbldots || m_arena->tile(to_global[n]) == Tile::DblDot) {
            for (const auto ddgi: m_arena->dbldots()) {
                compressed_toggles[to_compressed[ddgi]][n] = true;
            }
        }

        compressed_toggles[n][n] = true;
    }

    return move(compressed_toggles);
}

bitvector SolvingAlgorithm::compress_puzzle_vector(bool dbldot_state) const {
    bitvector compressed_puzzle{m_arena->states()};

    for (const auto n: numrange(0u, compressed_count)) {
        const uint global_n = to_global[n];
        const Tile tile = m_arena->tile(global_n);
        const bool state = compressed_puzzle[global_n];

        switch (tile) {
            case Tile::DblDot: compressed_puzzle[n] =  dbldot_state; break;
            case Tile::Yellow: compressed_puzzle[n] = !state;        break;
            default:           compressed_puzzle[n] =  state;        break;
        }
    }

    return move(compressed_puzzle);
}

vector<pair<bool, list<uint>>> SolvingAlgorithm::compress_and_solve_toggle_matrix() {
    calculate_compression_indexes();

    vector<pair<bool, list<uint>>> results;
    bitmatrix toggles{compress_toggle_matrix()};

    auto fn_process_geresults = [&](bool dbldot_state) {
        GaussianEliminationGF2<WayOut::MAX_COUNT> ge;

        bitvector puzzle{compress_puzzle_vector(dbldot_state)};
        auto result = ge.solve(toggles, puzzle, compressed_count);

        for (const auto & bs: result) {
            list<uint> indexes;
            for (auto n: numrange(0u, compressed_count)) {
                if (bs[n]) { indexes.push_back(to_global[n]); }
            }
            results.push_back({dbldot_state, move(indexes)});
        }
    };

    auto [has_dddown, has_ddup] = m_arena->dbldot_states();
    const bool arena_has_dbldots = has_ddup || has_dddown;
    if (has_ddup || !arena_has_dbldots) { fn_process_geresults(true ); }
    if (has_dddown) {
        LOG("Set all doubledot tiles down:" << endl);
        fn_process_geresults(false);
    }

    return move(results);
}

void SolvingAlgorithm::toggle_filtered_indexes(std::list<uint> & matrix_indexes,
                                               std::vector<uint> & final_indexes,
                                               std::function<bool(uint)> pred) const {
    while (!matrix_indexes.empty()) {
        auto it = find_if(begin(matrix_indexes), end(matrix_indexes), pred);
        if (it == end(matrix_indexes)) { break; }

        LOG(*it << ", ");
        m_arena->toggle(*it);
        final_indexes.push_back(*it);
        matrix_indexes.erase(it);
    }
}

std::optional<uint> SolvingAlgorithm::find_dbldot_index(bool dbldot_state,
                    const std::list<uint> & matrix_indexes) const {

    auto is_not_yellow   = [&](uint index) { return  m_arena->tile(index) != Tile::Yellow; };
    auto is_dbldot_found = [&](auto index) {
                return m_arena->tile(index)  == Tile::DblDot
                    && m_arena->state(index) == dbldot_state; };
    auto is_error_found = [&](auto index) {
                return m_arena->tile(index)  == Tile::DblDot
                    && m_arena->state(index) != dbldot_state; };

    for (const auto ind: matrix_indexes) {
        if (!is_not_yellow(ind))  { continue; }
        if (is_dbldot_found(ind)) { return ind; }

        bool correct_flag = false;
        bool error_flag = is_error_found(ind);
        for (const auto nbi: m_arena->neighbors(ind)) {
            if (is_dbldot_found(nbi)) { correct_flag = true; }
            if (is_error_found(nbi))  { error_flag = true; }
        }
        if (correct_flag && !error_flag) { return ind; }
    }
    return nullopt;
}

vector<pair<uint, uint>> SolvingAlgorithm::get_yellows_neighbors_with_priorities(
            list<uint> & matrix_indexes) const {
    vector<pair<uint, uint>> result;

    for (uint index = 0; index < m_arena->count(); index++) {
        if (m_arena->tile(index) != Tile::Yellow) { continue; }

        for (const auto rnbi: m_arena->rev_neighbors(index)) {
            auto it = find_if(begin(result), end(result),
                              [rnbi](auto nbp){ return nbp.first == rnbi; });

            if (it != end(result)) { it->second++; }
            else { result.push_back({rnbi, 1}); }
        }
    }

    for (const auto index: matrix_indexes) {
        if (m_arena->tile(index) == Tile::Yellow) { continue; }

        auto it = find_if(begin(result), end(result),
                          [index](auto ri){ return ri.first == index; });
        if (it != end(result)) {
            it->second += 2;
        }
    }

    return move(result);
}

void SolvingAlgorithm::toggle_yellow_tiles(list<uint> & matrix_indexes,
                                           vector<uint> & final_indexes) const {
    LOG("\ntoggle yellow tiles in order of priority: ");
    vector<pair<uint, uint>> yellows_neighbors{
            get_yellows_neighbors_with_priorities(matrix_indexes)};

    auto compare_by_priority = [](auto l, auto r){
        return (l.second < r.second)
            || (l.second == r.second && l.first > r.first);
    };

    while (!yellows_neighbors.empty()) {
        const auto [index, cnt] = *max_element(begin(yellows_neighbors),
                    end(yellows_neighbors),
                    compare_by_priority);

        LOG(index);
        m_arena->toggle(index);
        final_indexes.push_back(index);

        if (auto it = find(begin(matrix_indexes), end(matrix_indexes), index);
            it != end(matrix_indexes)) {
            matrix_indexes.erase(it);
            LOG("(matrix toggles), ");
        } else {
            m_arena->toggle(index);
            final_indexes.push_back(index);
            LOG("(twice), ");
        }

        // For simplicity we do not update indexes/priorities of the current structure.
        // We just calculate it again
        yellows_neighbors = get_yellows_neighbors_with_priorities(matrix_indexes);
    }
}

std::optional<vector<uint>> SolvingAlgorithm::complete_solution(
        bool dbldot_state, list<uint> && matrix_indexes) {

    vector<uint> final_indexes;
    auto [has_dddown, has_ddup] = m_arena->dbldot_states();
    LOG("\nhas dbldot tiles in different states: {");
    LOG(boolalpha << has_dddown << ", " << has_ddup << "}");

    auto is_not_yellow      = [&](uint index) { return  m_arena->tile(index) != Tile::Yellow; };
    auto has_no_ddneighbors = [&](uint index) { return !m_arena->has_dbldots_neighbors(index); };

    if (has_dddown || has_ddup) {
        // process all not yellow not dbldots neighbors indexes
        LOG("\ntoggle except for yellow, doubledot tiles and doubledot's neigbors: ");
        toggle_filtered_indexes(matrix_indexes, final_indexes,
                                bind(logical_and<>{}, bind(is_not_yellow, _1),
                                                      bind(has_no_ddneighbors, _1)));

        auto index = find_dbldot_index(dbldot_state, matrix_indexes);
        if (!index.has_value()) {
            LOG("\nthe tile toggling doubledot tiles to the right state was not found");
            return nullopt;
        }

        if (auto it = find(begin(matrix_indexes), end(matrix_indexes), index.value());
            it != end(matrix_indexes)) {
            LOG("\nindex of the first toggling a doubledot tile: " << *it);

            m_arena->toggle(*it);
            final_indexes.push_back(*it);
            matrix_indexes.erase(it);
        }
    }

    // process the rest not yellow indexes
    LOG("\ntoggle tiles except for yellow: ");
    toggle_filtered_indexes(matrix_indexes, final_indexes, is_not_yellow);

    LOG("\nremainig tiles (all of them are yellow): ");
    LOG_FN(for (const auto ind: matrix_indexes) {
        clog << ind << ", ";
    });

    toggle_yellow_tiles(matrix_indexes, final_indexes);

    // if matrix_indexes still not empty, just toggle all rest indexes
    LOG("\nremaining matrix indexes: ");
    for (auto ind: matrix_indexes) {
        LOG(ind << ", ");

        m_arena->toggle(ind);
        final_indexes.push_back(ind);
    }

    if (!m_arena->is_complete()) {
        LOG("\n!An algorithm error has occured" << endl);
        throw;
        return nullopt;
    }

    return move(final_indexes);
}

unique_ptr<Arena> SolvingAlgorithm::solve(unique_ptr<Arena> arena) {
    m_arena = move(arena);

    auto toggles_pairs = compress_and_solve_toggle_matrix();
    uint min_count = 2 * m_arena->count();

    for (auto & [dbldot_state, indexes]: toggles_pairs) {
        LOG("Process solution {" << setw(5) << boolalpha << dbldot_state << ", [");
        LOG_FN(for (auto it = begin(indexes); it != prev(end(indexes)); ++it) {
            LOG(*it << ", ");
        });
        LOG(*prev(end(indexes)) << "]}");

        if (indexes.size() >= min_count) {
            LOG("\nskip\n" << endl);
            continue;
        }

        m_arena->restore_initial_states();
        auto result = complete_solution(dbldot_state, move(indexes));

        if (result.has_value() && !result->empty() && result->size() < min_count) {
            LOG("\nwe got the new minimal solution with " << result->size() << " moves!");

            min_count = result->size();
            m_result = move(result.value());
        }
        LOG('\n' << endl);
    }

    return move(m_arena);
}
