// Gaussian elimination implementation for matrices with elements in GF2.
// Implemented class finds all solutions for the given system of linear
// equations (in GF2) and returns them within the standard container.
// System of linear equations is presented as matrix of unknowns' coefficients
// and vector of free coefficients.
// In terms of "Lights out" game, the input matrix is a table of trigger
// dependencies and the vector is puzzle (indexes of activated lights).
// Each solution provides a set of "ones" that turns off all the puzzle lights,
// if you toggle all corresponding lights.

#ifndef GAUSSIAN_ELIMINATION_GF2_H
#define GAUSSIAN_ELIMINATION_GF2_H

#include <array>
#include <bitset>
#include <vector>
#include <optional>

template<unsigned COUNT>
class GaussianEliminationGF2 {
private:
    using bitvector = std::bitset<COUNT>;
    using bitmatrix = std::array<std::bitset<COUNT>, COUNT>;

    bitmatrix m_matrix;
    bitvector m_puzzle;
    unsigned m_count{0};

    void log_current_state() const;
    std::optional<unsigned> find_pivot_row(unsigned pivot_col, unsigned start_row = 0) const;
    std::optional<unsigned> find_pivot_col(unsigned pivot_row, unsigned start_col = 0) const;

    void forward_elimination();
    void back_substitute(bitvector & result, unsigned pivot_row) const;
    std::vector<unsigned> find_free_indexes() const;

public:
    GaussianEliminationGF2() = default;
    GaussianEliminationGF2(const GaussianEliminationGF2 &) = delete;
    GaussianEliminationGF2& operator=(const GaussianEliminationGF2 &) = delete;

    std::vector<bitvector> solve(const bitmatrix & matrix, const bitvector & puzzle,
                                 const unsigned count);
};

#include "gaussian_elimination_gf2_impl.h"

#endif
