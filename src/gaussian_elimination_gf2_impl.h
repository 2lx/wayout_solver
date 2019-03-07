#ifndef GAUSSIAN_ELIMINATION_GF2_IMPL_H
#define GAUSSIAN_ELIMINATION_GF2_IMPL_H

#include "logging.h"

using namespace std;

template<unsigned COUNT>
void GaussianEliminationGF2<COUNT>::log_current_state() const {
    LOG("### | Toggles");
    LOG(string(max(0, static_cast<int>(m_count) - 7), ' '));
    LOG(" | Puzzle" << '\n');

    for (unsigned i = 0; i < m_count; i++) {
        LOG(setw(3) << i << " | ");
        for (unsigned j = 0; j < m_count; j++) {
            LOG(m_toggle[i].test(j));
        }
        LOG(string(max(0, 7 - static_cast<int>(m_count)), ' '));
        LOG(" | " << m_puzzle[i] << '\n');
    }
    LOG(endl);
}

// returns the index of the first row (starting from the "start_row") for which the toggle
// matrix contains one in given column
template<unsigned COUNT>
optional<unsigned> GaussianEliminationGF2<COUNT>::find_pivot_row(unsigned pivot_col,
                                                                 unsigned start_row) const {
    for (unsigned row = start_row; row < m_count; row++) {
        if (m_toggle[row][pivot_col]) { return row; }
    }

    return nullopt;
}

// returns the index of the first column (starting from the "start_col") for which the toggle
// matrix contains one in given row
template<unsigned COUNT>
optional<unsigned> GaussianEliminationGF2<COUNT>::find_pivot_col(unsigned pivot_row,
                                                                 unsigned start_col) const {
    for (unsigned col = start_col; col < m_count; col++) {
        if (m_toggle[pivot_row][col]) { return col; }
    }

    return nullopt;
}

// reduces given system to row echelon form according to Gaussian algorithm
template<unsigned COUNT>
void GaussianEliminationGF2<COUNT>::forward_elimination() {
    LOG("Before forward elimination\n");
    LOG_FN(log_current_state());

    // swaps the puzzle bit values puzzle at given positions
    auto puzzle_swap = [this](unsigned i, unsigned j) {
        const bool old_val = m_puzzle[i];
        m_puzzle[i] = m_puzzle[j];
        m_puzzle[j] = old_val;
    };

    unsigned next_free_row = 0;
    for (unsigned col = 0; col < m_count; col++) {
        auto fresult = find_pivot_row(col, next_free_row);
        if (!fresult.has_value()) continue;

        const unsigned pivot_row = fresult.value();
        if (pivot_row != next_free_row) {
            swap(m_toggle[pivot_row], m_toggle[next_free_row]);
            puzzle_swap(pivot_row, next_free_row);
        }

        for (unsigned row = pivot_row + 1; row < m_count; row++) {
            if (m_toggle[row][col]) {
                m_toggle[row] = m_toggle[row] ^ m_toggle[next_free_row];
                m_puzzle[row] = m_puzzle[row] ^ m_puzzle[next_free_row];
            }
        }

        next_free_row++;
    }
    LOG("After forward elimination\n");
    LOG_FN(log_current_state());
}

// puts the matrix into reduced row echelon form and calculates the result bits
// according to Gaussian algorithm
template<unsigned COUNT>
void GaussianEliminationGF2<COUNT>::back_substitute(bitvector & result,
                                                    unsigned pivot_row) const {
    for (unsigned row = pivot_row + 1; row-- != 0;) {
        const auto fresult = find_pivot_col(row);
        if (!fresult.has_value()) { continue; }
        const unsigned pivot_col = fresult.value();

        result[pivot_col] = m_puzzle[row];
        for (unsigned col = pivot_col + 1; col < m_count; col++) {
            result[pivot_col] = result[pivot_col] ^ (m_toggle[row][col] && result[col]);
        }
    }
}

// finds all the result bits indixes that will not change if we perform the
// reverse substitution
template<unsigned COUNT>
vector<unsigned> GaussianEliminationGF2<COUNT>::find_free_indexes() const {
    vector<unsigned> free_indexes;

    for (unsigned row = 0, prev_col = 0; row < m_count; row++) {
        if (const auto fresult = find_pivot_col(row, prev_col); fresult.has_value()) {
            for (unsigned c = prev_col + 1; c < fresult.value(); c++) {
                free_indexes.push_back(c);
            }
            prev_col = fresult.value();
        } else {
            for (unsigned c = prev_col + 1; c < m_count; c++) {
                free_indexes.push_back(c);
            }
            break;
        }
    }
    return move(free_indexes);
}

template<unsigned COUNT>
vector<typename GaussianEliminationGF2<COUNT>::bitvector>
GaussianEliminationGF2<COUNT>::solve(const bitmatrix & neighbors, const bitvector & puzzle,
                                     const unsigned count) {
    m_toggle = neighbors;
    m_count  = count;
    m_puzzle = puzzle;

    // Reduce the given system to row echelon form.
    forward_elimination();

    // Now we can check if solution does not exist. If the whole row consists of zeros
    // and the corresponding puzzle value is one, return empty container
    unsigned pivot_row = m_count - 1;
    for (; pivot_row != 0; pivot_row--) {
        const auto fresult = find_pivot_col(pivot_row);
        if (!fresult.has_value() && m_puzzle.test(pivot_row)) { return {}; }
        if ( fresult.has_value()) { break; }
    }

    // We got that at least one solution exists. Let's find all of them: we must
    // find all the result bits indixes that will not change if we perform the
    // back substitution. Each bit of the result in these indexes may contain one
    // or zero, and it will give us different solutions.
    // If we substitute all possible values in the positions of free indexes, this
    // will give us all posible solutions of this puzzle.
    const auto free_indexes{find_free_indexes()};

    /* bitvector best_result; */
    /* unsigned best_count = m_count + 1; */
    vector<bitvector> results;
    const unsigned ubound = 1 << free_indexes.size();
    for (unsigned cur = 0; cur < ubound; cur++) {
        bitvector result;

        // Substitute the next set of ones and zeros in the free positions of
        // result and perform the back substitution.
        for (unsigned i = 0; i < free_indexes.size(); i++) {
            result[free_indexes[i]] = cur & (1 << i);
        }

        back_substitute(result, pivot_row);
        results.push_back(move(result));
    }

    return move(results);
}

#endif
