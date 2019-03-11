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

// Unlike the Lights Out game, WayOut levels contain many empty places.
// For the more effective solution of the toggle matrix, we need to compress
// the base level layout. It means re-index each tile and skip all indexes
// of the missed ones. To do this we need at first to calculate two arrays
// of indexes, that convert indexes from global to compressed, and vise versa.
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

// Compresses the toggle matrix to the matrix without missed tiles.
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

// Compresses the puzzle to the puzzle without missed tiles.
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

// Compresses the toggle matrix and puzzle, decides the resulting system of
// linear equations in GF2 by the Gaussian Elimination method, decompress and
// returns the results. Since the level includes double dot tiles that can
// be initially in the different states simultaneously, the method finds the
// sulutions for each initial state of that tiles. For the yellow tiles we suppose
// they became normal ones (but in the opposite state).
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

// For each matrix_indexes's index that gives pred(index) is true, does:
// 1. toggles the level tiles at that index.
// 2. deletes it from matrix_indexes.
// 3. adds it to the vector of final indexes.
// These toggles can add new tiles, that satisfies the condition, so the algorithm
// repeats these steps until there are no new indexes throughout the iteration.
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

// The double dot tiles in the puzzle may be in different states simultaneously
// until the first toggle. This method resolves that problem and finds the right tile,
// that toggles them in the right state.
// Also, if there are several double dot tiles surround the one and they are in
// the different states (for instance WayOut 1 set 6 level 9) it might be a problem.
// The toggle of that tile gives the ambiguity of double dot tiles triggering.
// The method checks for that option too.
std::optional<uint> SolvingAlgorithm::find_dbldot_index(bool dbldot_state,
                    const std::list<uint> & matrix_indexes) const {

    auto is_right_dbldot_found = [&](auto index) {
                return m_arena->tile(index)  == Tile::DblDot
                    && m_arena->state(index) == dbldot_state; };
    auto is_wrong_dbldot_found = [&](auto index) {
                return m_arena->tile(index)  == Tile::DblDot
                    && m_arena->state(index) != dbldot_state; };

    for (const auto ind: matrix_indexes) {
        if (m_arena->tile(ind) == Tile::Yellow)  { continue; }
        if (is_right_dbldot_found(ind)) { return ind; }

        bool correct_flag = false;
        bool error_flag = is_wrong_dbldot_found(ind);

        for (const auto nbi: m_arena->neighbors(ind)) {
            if (is_right_dbldot_found(nbi)) { correct_flag = true; }
            if (is_wrong_dbldot_found(nbi)) { error_flag = true; }
        }
        if (correct_flag && !error_flag) { return ind; }
    }
    return nullopt;
}

// Returns the vector of indexes of each yellow tile's neighbors.
// For each neighbor calculates its priority.
// The more yellow tiles surround the tile, the higher priority it has.
// Further more, if the tile index is included to the matrix_indexes,
// it gets +2 to priority (due to a decrease of the number of toggles).
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

// Gets the vector of indexes and priorities of the tiles that surround
// the yellow tiles. On each iteration the method toggles the tile at
// the maximal priority and reconstructs the vector. Repeats until there are
// no yellow tiles in the puzzle.
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

// Processes the results of the gaussian algorithm. Takes the initial state of the
// double dot tiles (for which the results were calculated) and list of tile indexes.
// Finds the close to optimal vector of indexes that solves the puzzle.
// Toggles these indexes on the virtual gaming arena and checks the result.
std::optional<vector<uint>> SolvingAlgorithm::complete_solution(
        bool dbldot_state, list<uint> && matrix_indexes) {

    vector<uint> final_indexes;
    auto [has_dddown, has_ddup] = m_arena->dbldot_states();
    LOG("\nhas dbldot tiles with different states: {");
    LOG(boolalpha << has_dddown << ", " << has_ddup << "}");

    auto is_not_yellow      = [&](uint index) { return  m_arena->tile(index) != Tile::Yellow; };
    auto has_no_ddneighbors = [&](uint index) { return !m_arena->has_dbldots_neighbors(index); };

    // If the puzzle has double dot tiles:
    // 1. toggle all possible tiles, that do not trigger double dot tiles
    // (more yellow tiles become normal and can trigger double dot tiles to the right).
    // 2. Tries to find the right tile for the first toggling of double dot tiles.
    // If there is no such tile, there is no solution.
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

    // Toggle the rest not yellow tiles
    LOG("\ntoggle all tiles except for yellow: ");
    toggle_filtered_indexes(matrix_indexes, final_indexes, is_not_yellow);

    LOG("\ntoggle yellow tiles: ");
    LOG_FN(for (const auto ind: matrix_indexes) {
        LOG(ind << ", ");
    });

    // process the yellow tiles
    toggle_yellow_tiles(matrix_indexes, final_indexes);

    // if matrix_indexes still not empty, just toggle all its indexes
    LOG("\nremaining matrix indexes: ");
    for (auto ind: matrix_indexes) {
        LOG(ind << ", ");

        m_arena->toggle(ind);
        final_indexes.push_back(ind);
    }

    // check the results. It is an additional option, and if we are at this point
    // the puzzle must be completed in any case
    if (!m_arena->is_complete()) {
        LOG("\n!An algorithm error has occured" << endl);
        throw;
        return nullopt;
    }

    return move(final_indexes);
}

// the main method that solves the wayout puzzle
unique_ptr<Arena> SolvingAlgorithm::solve(unique_ptr<Arena> arena) {
    m_arena = move(arena);

    // aggregate all posible solutions for the different double dot tiles states
    auto toggles_pairs = compress_and_solve_toggle_matrix();
    uint min_count = 2 * m_arena->count();

    // for each solution find the close to minimal number of toggles that it takes
    // and remember the smallest one. If the number of toggles is not less than
    // the minimal found skip this pair
    for (auto & [dbldot_state, indexes]: toggles_pairs) {
        if (indexes.size() >= min_count) { continue; }

        LOG("Process solution {" << setw(5) << boolalpha << dbldot_state << ", [");
        LOG_FN(for (auto it = begin(indexes); it != prev(end(indexes)); ++it) {
            LOG(*it << ", ");
        });
        LOG(*prev(end(indexes)) << "]}");

        m_arena->restore_initial_states();
        auto result = complete_solution(dbldot_state, move(indexes));

        if (result.has_value() && !result->empty() && result->size() < min_count) {
            LOG("\nwe've got the new minimal solution with " << result->size() << " moves!");

            min_count = result->size();
            m_result = move(result.value());
        }
        LOG('\n' << endl);
    }

    return move(m_arena);
}
