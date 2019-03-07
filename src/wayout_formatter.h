#ifndef WAYOUT_FORMATTER_H
#define WAYOUT_FORMATTER_H

#include "wayout_common.h"

namespace WayOut
{
class Formatter {
public:
    enum {
        I_NONE = 0,     I_NRMU, I_NRMD,
        I_HORU, I_HORD, I_VERU, I_VERD,
        I_DIAU, I_DIAD,
        I_ONEU, I_ONED, I_SLPU, I_SLPD,
        I_PLSU, I_PLSD, I_DBLU, I_DBLD
    };

    enum {
        O_NONE = 0, O_TOGG, O_REST
    };

    static Tile  encode_tail(const char iformat[], const char ch);
    static State encode_state(const char iformat[], const char ch);
    static char to_char(const uint num);
};
}

#endif
