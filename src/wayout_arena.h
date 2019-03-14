// Emulates the WayOut game mechanics. Represents the table of tiles and provides
// methods for the level structure access and toggling algorithms.

#ifndef WAYOUT_ARENA_H
#define WAYOUT_ARENA_H

#include "wayout_common.h"

#include <vector>
#include <bitset>
#include <set>
#include <utility>

namespace WayOut
{

class Arena {
    uint m_width{0}, m_height{0};
    std::bitset<MAX_COUNT> m_states{0}, m_init_states{0};
    std::vector<Tile> m_tiles, m_init_tiles;
    std::vector<std::vector<uint>> m_neighbors;
    std::vector<uint> m_dbldots;
    std::vector<std::vector<uint>> m_rev_neighbors;
    std::bitset<MAX_COUNT> m_has_dbldots_neighbors{0};
    bool m_dbldots_were_flipped{false};
    std::pair<bool, bool> m_dbldot_states{false, false};

    void flip(const uint index);
    void flip_neighbor(const uint index);
    void flip_dbldots(const uint index);
    void insert_neighbor(std::set<uint> & nbs, const uint index) const;
    void collect_neighbors(std::set<uint> & nbs, const uint index) const;
    void preliminary_calculations();

public:
    Arena() = default;
    Arena(const Arena &) = delete;
    Arena & operator=(const Arena &) = delete;

    void toggle(const uint index);
    bool initialize(const std::vector<std::pair<Tile, State>> & level,
            uint width, uint height);

    inline uint width() const                            { return m_width; }
    inline uint height() const                           { return m_height; }
    inline uint count() const                            { return static_cast<uint>(m_tiles.size()); }

    inline Tile tile(const uint index) const             { return m_tiles[index]; }
    inline const std::vector<Tile> & tiles() const       { return m_tiles; }
    inline bool state(const uint index) const            { return m_states[index]; }
    inline const std::bitset<MAX_COUNT> & states() const { return m_states; }


    void restore_initial_states();
    inline bool is_complete() const                      { return m_states.none(); }

    inline std::pair<bool, bool> dbldot_states() const   { return m_dbldot_states; }
    inline const std::vector<uint> &
        neighbors(const uint index) const                { return m_neighbors[index]; }
    inline const std::vector<uint> &
        rev_neighbors(const uint index) const            { return m_rev_neighbors[index]; }
    inline const std::vector<uint> & dbldots() const     { return m_dbldots; }
    inline bool has_dbldots_neighbors(uint index) const  { return m_has_dbldots_neighbors[index]; }
};

}

#endif
