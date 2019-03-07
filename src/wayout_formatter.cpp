#include "wayout_formatter.h"

using namespace WayOut;

Tile Formatter::encode_tail(const char iformat[], const char ch) {
    if (       ch == iformat[Formatter::I_NRMU]
            || ch == iformat[Formatter::I_NRMD]) {
        return Tile::Normal;
    } else if (ch == iformat[Formatter::I_HORU]
            || ch == iformat[Formatter::I_HORD]) {
        return Tile::HArrow;
    } else if (ch == iformat[Formatter::I_VERU]
            || ch == iformat[Formatter::I_VERD]) {
        return Tile::VArrow;
    } else if (ch == iformat[Formatter::I_DIAU]
            || ch == iformat[Formatter::I_DIAD]) {
        return Tile::DArrow;
    } else if (ch == iformat[Formatter::I_ONEU]
            || ch == iformat[Formatter::I_ONED]) {
        return Tile::OneDot;
    } else if (ch == iformat[Formatter::I_SLPU]
            || ch == iformat[Formatter::I_SLPD]) {
        return Tile::Yellow;
    } else if (ch == iformat[Formatter::I_PLSU]
            || ch == iformat[Formatter::I_PLSD]) {
        return Tile::Plus;
    } else if (ch == iformat[Formatter::I_DBLU]
            || ch == iformat[Formatter::I_DBLD]) {
        return Tile::DblDot;
    } else {
        return Tile::None;
    }
}

State Formatter::encode_state(const char iformat[], const char ch) {
    if (   ch == iformat[Formatter::I_NRMU]
        || ch == iformat[Formatter::I_HORU]
        || ch == iformat[Formatter::I_VERU]
        || ch == iformat[Formatter::I_DIAU]
        || ch == iformat[Formatter::I_ONEU]
        || ch == iformat[Formatter::I_SLPU]
        || ch == iformat[Formatter::I_PLSU]
        || ch == iformat[Formatter::I_DBLU]) {
        return State::Up;
    } else {
        return State::Down;
    }
}

char Formatter::to_char(const uint num) {
    if (num < 10) {
        return static_cast<char>('0' + num);
    } else if (num < 36) {
        return static_cast<char>('A' + num - 10);
    } else {
        return 'Z';
    }
}

