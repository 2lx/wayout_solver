#ifndef WAYOUT_SOLVING_ALGORITHM_H
#define WAYOUT_SOLVING_ALGORITHM_H

#include "wayout_common.h"
#include "wayout_arena.h"

#include <memory>
#include <vector>
#include <utility>
#include <optional>
#include <functional>
#include <list>

namespace WayOut {

class SolvingAlgorithm {
private:
    std::unique_ptr<Arena> m_arena;
    std::vector<uint> m_result;
    std::vector<uint> to_global, to_compressed;
    uint compressed_count{0};

    void calculate_compression_indexes();
    WayOut::bitmatrix compress_toggle_matrix() const;
    WayOut::bitvector compress_puzzle_vector(bool dbldot_state) const;
    std::vector<std::pair<bool, std::list<uint>>> compress_and_solve_toggle_matrix();

    void toggle_filtered_indexes(std::list<uint> & matrix_indexes,
                                 std::vector<uint> & final_indexes,
                                 std::function<bool(uint)> pred) const;
    std::optional<uint> find_dbldot_index(bool dbldot_state,
                const std::list<uint> & matrix_indexes) const;
    std::vector<std::pair<uint, uint>> get_yellows_neighbors_with_priorities(
                std::list<uint> & matrix_indexes) const;
    void toggle_yellow_tiles(std::list<uint> & matrix_indexes,
                             std::vector<uint> & final_indexes) const;

    std::optional<std::vector<uint>> complete_solution(bool dbldot_state,
                                                       std::list<uint> && matrix_indexes);

public:
    SolvingAlgorithm() = default;
    SolvingAlgorithm(const SolvingAlgorithm &) = delete;
    SolvingAlgorithm& operator=(const SolvingAlgorithm &) = delete;

    std::unique_ptr<Arena> solve(std::unique_ptr<Arena> arena);
    const std::vector<uint> & result() const { return m_result; }
};

}

#endif
