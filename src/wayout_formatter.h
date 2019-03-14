#ifndef WAYOUT_FORMATTER_H
#define WAYOUT_FORMATTER_H

#include "wayout_common.h"
#include <optional>

namespace WayOut
{
class Formatter {
public:
    enum ICONVENTION {
        I_NONE = 0,     I_NORU, I_NORD,
        I_HARU, I_HARD, I_VARU, I_VARD,
        I_DARU, I_DARD,
        I_SINU, I_SIND, I_YELU, I_YELD,
        I_PLSU, I_PLSD, I_DBLU, I_DBLD
    };

    enum OCONVENTION {
        O_NONE = 0, O_TOGG, O_REST
    };

    static std::optional<Tile> encode_tail(const char iformat[], const char ch);
    static State encode_state(const char iformat[], const char ch);

    static constexpr char to_char(const uint num) {
        if (num < 10) {
            return static_cast<char>('0' + num);
        } else if (num < 36) {
            return static_cast<char>('A' + num - 10);
        } else {
            return 'Z';
        }
    }
};
}

#endif
