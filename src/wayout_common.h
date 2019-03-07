#ifndef WAYOUT_COMMON_H
#define WAYOUT_COMMON_H

#include <array>
#include <bitset>

namespace WayOut {

using uint = unsigned int;
constexpr uint MAX_COUNT = 512;

enum class Tile {
    None,   Normal, HArrow, VArrow, DArrow,
    OneDot, Yellow, Plus,   DblDot,
};

enum class State {
    Down, Up
};

using bitvector = std::bitset<MAX_COUNT>;
using bitmatrix = std::array<std::bitset<MAX_COUNT>, MAX_COUNT>;
}

#endif
