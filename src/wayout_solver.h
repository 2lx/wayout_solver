#ifndef WAYOUT_SOLVER_H
#define WAYOUT_SOLVER_H

#include "wayout_arena.h"

#include <iosfwd>
#include <vector>
#include <utility>
#include <memory>

namespace WayOut
{
class Solver {
private:
    std::unique_ptr<Arena> m_arena;
    std::vector<uint> m_result;

public:
    Solver();

    bool read_level_data(std::istream & stream, const char iformat[] = "_X.HhVvNnOoYyPpDd");
    std::pair<bool, uint> solve();
    void print_solution(std::ostream & stream, const char oformat[] = "_X.",
                        bool print_numbers = true) const;
};
}

#endif
