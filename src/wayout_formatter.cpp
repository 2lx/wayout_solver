#include "wayout_formatter.h"

using namespace WayOut;
using namespace std;

optional<Tile> Formatter::encode_tail(const char iformat[], const char ch) {
    if (       ch == iformat[Formatter::I_NORU]
            || ch == iformat[Formatter::I_NORD]) {
        return Tile::Normal;
    } else if (ch == iformat[Formatter::I_HARU]
            || ch == iformat[Formatter::I_HARD]) {
        return Tile::HArrow;
    } else if (ch == iformat[Formatter::I_VARU]
            || ch == iformat[Formatter::I_VARD]) {
        return Tile::VArrow;
    } else if (ch == iformat[Formatter::I_DARU]
            || ch == iformat[Formatter::I_DARD]) {
        return Tile::DArrow;
    } else if (ch == iformat[Formatter::I_SINU]
            || ch == iformat[Formatter::I_SIND]) {
        return Tile::OneDot;
    } else if (ch == iformat[Formatter::I_YELU]
            || ch == iformat[Formatter::I_YELD]) {
        return Tile::Yellow;
    } else if (ch == iformat[Formatter::I_PLSU]
            || ch == iformat[Formatter::I_PLSD]) {
        return Tile::Plus;
    } else if (ch == iformat[Formatter::I_DBLU]
            || ch == iformat[Formatter::I_DBLD]) {
        return Tile::DblDot;
    } else if (ch == iformat[Formatter::I_NONE]) {
        return Tile::None;
    } else {
        return nullopt;
    }
}

State Formatter::encode_state(const char iformat[], const char ch) {
    if (   ch == iformat[Formatter::I_NORU]
        || ch == iformat[Formatter::I_HARU]
        || ch == iformat[Formatter::I_VARU]
        || ch == iformat[Formatter::I_DARU]
        || ch == iformat[Formatter::I_SINU]
        || ch == iformat[Formatter::I_YELU]
        || ch == iformat[Formatter::I_PLSU]
        || ch == iformat[Formatter::I_DBLU]) {
        return State::Up;
    } else {
        return State::Down;
    }
}

