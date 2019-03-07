#define BOOST_TEST_MODULE WayOut1Section5Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section5Level01)
{
    const char * indata = 1 + R"(
.p.
X.X
)";
    const char * outdata = 1 + R"(
X.X
...
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level03)
{
    const char * indata = 1 + R"(
X_.X.p
_._..y
.YX..P
XP._._
XXX._.
)";
    const char * outdata1 = 1 + R"(
._..X. | X_...X
_._... | _._...
..X... | ....X.
..._._ | ..._X_
...._. | .X.._.
)";
    const char * outdata2 = 1 + R"(
X_..XX
_._...
..X.X.
..._X_
.X.._.
)";
    test(indata, {outdata1, outdata2});
}

BOOST_AUTO_TEST_CASE(Section5Level10)
{
    const char * indata = 1 + R"(
X.XPX
XPX..
X.XPX
.X.X.
XPXX.
)";
    const char * outdata = 1 + R"(
..X..
X....
..X..
.....
..X..
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level12)
{
    const char * indata = 1 + R"(
..X.pX
.X..XX
..p..X
XX.X.X
PX..p.
XX.X..
)";
    const char * outdata = 1 + R"(
......
..X..X
...X..
....X.
.X.X..
......
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level13)
{
    const char * indata = 1 + R"(
X_XYX_.
P.X.X_p
XppYPP.
p_.X.XP
._XY._X
)";
    const char * outdata1 = 1 + R"(
._X.._. | ._.X._X
..X.._. | ....._.
....... | X.....X
._.X... | X_.....
._..._. | ._X.._.
)";
    const char * outdata2 = 1 + R"(
._XX._X
..X.._.
X.....X
X_.X...
._X.._.
)";
    test(indata, {outdata1, outdata2});
}

BOOST_AUTO_TEST_CASE(Section5Level17)
{
    const char * indata = 1 + R"(
XO.____
._XP.O_
XO.._X_
_XXPX._
_._..PX
_.XO._X
____XX.
)";
    const char * outdata = 1 + R"(
.X.____
._X..X_
.X.._._
_...X._
_._...X
_..X._.
____X..
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level19)
{
    const char * indata = 1 + R"(
.p.p__X
P_p_XPX
_pXX_._
_Xp._._
.p_pXpX
_XpX._P
.X.__XX
)";
    const char * outdata = 1 + R"(
X.XX__.
._._..X
_.X._._
_X.._X_
.._.X..
_X.X._.
...__.X
)";
    test(indata, {outdata});
}

