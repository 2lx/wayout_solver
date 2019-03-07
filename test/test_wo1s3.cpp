#define BOOST_TEST_MODULE WayOut1Section3Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section3Level01)
{
    const char * indata = 1 + R"(
.O.
)";
    const char * outdata = 1 + R"(
XXX
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level06)
{
    const char * indata = 1 + R"(
X.X..
XO..X
..O.O
.o...
XX..X
)";
    const char * outdata = 1 + R"(
.X...
.X...
..X.X
..X.X
.X...
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level10)
{
    const char * indata = 1 + R"(
.XV.X.
...hOX
.OX.h.
.vVXX.
..OXXX
XH..VX
)";
    const char * outdata = 1 + R"(
X.X...
X..XX.
.X....
.X..X.
..X..X
.X..X.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level20)
{
    const char * indata = 1 + R"(
__.vXoV__
_..X.XhX_
..H_V_..h
Xv_X.X_Ov
O...O..H.
Xv_o.X_O.
.X._._.oX
_..XOX.X_
__.O.O.__
)";
    const char * outdata = 1 + R"(
__.XX.X__
_.....X._
..X_X_..X
.X_..._XX
XX.XXX.X.
.X_..._X.
..._X_X.X
_..XX.X._
__XXXX.__
)";
    test(indata, {outdata});
}

