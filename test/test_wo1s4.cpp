#define BOOST_TEST_MODULE WayOut1Section4Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section4Level01)
{
    const char * indata = 1 + R"(
Y.
.Y
)";
    const char * outdata1 = 1 + R"(
.X | .X
.. | ..
)";
    const char * outdata2 = 1 + R"(
.. | ..
X. | X.
)";
    test(indata, {outdata1, outdata2});
}

BOOST_AUTO_TEST_CASE(Section4Level05)
{
    const char * indata = 1 + R"(
.V_.V
H..h.
_X_X_
.Y.HX
X._Xy
)";
    const char * outdata1 = 1 + R"(
.._.. | .._.X
..... | .X.X.
_X_._ | _._X_
..... | .X.X.
.._X. | X._..
)";
    const char * outdata2 = 1 + R"(
.._.X
.X.X.
_X_X_
.X.X.
X._X.
)";
    test(indata, {outdata1, outdata2});
}

BOOST_AUTO_TEST_CASE(Section4Level07)
{
    const char * indata = 1 + R"(
.XhX_
Y_v.X
.yOY.
YX._.
_.X.X
)";
    const char * outdata1 = 1 + R"(
..1._ | ...._
._2.. | ._...
7.3.4 | 8....
..5_6 | ..._.
_.... | _....
)";

    test(indata, {outdata1});
}

BOOST_AUTO_TEST_CASE(Section4Level15)
{
    const char * indata = 1 + R"(
...._X_
.YY_XO.
y.y_.X.
XXX_.OX
_y_.Y.y
)";
    const char * outdata1 = 1 + R"(
.X.._._ | ...._._
XXX_... | ..._.XX
..._... | ..._.X.
.X._X.. | ..._.X.
_._..X. | _._....
)";
    const char * outdata2 = 1 + R"(
.X.._._ | ...._._
XXX_... | ..._.XX
..._... | ..._.X.
.X._... | ..._XX.
_._..X. | _._....
)";
    const char * outdata3 = 1 + R"(
.X.._._
XXX_.X.
..._..X
.X._.XX
_._XX..
)";
    test(indata, {outdata1, outdata2, outdata3});
}

BOOST_AUTO_TEST_CASE(Section4Level18)
{
    const char * indata = 1 + R"(
__h.__
__vX__
XhYyH.
vXyYVX
__Xh__
__vV__
)";
    const char * outdata1 = 1 + R"(
__12__ | __..__
__..__ | __..__
3..94. | ...A..
.5...6 | ......
__.7__ | __..__
__.8__ | __..__
)";
    test(indata, {outdata1});
}

BOOST_AUTO_TEST_CASE(Section4Level20)
{
    const char * indata = 1 + R"(
.X.X..
.yyyy.
XYYYY.
.YYyy.
XyyyYX
.X.X.X
)";
    const char * outdata1 = 1 + R"(
..X...
..X...
..X.X.
XX..XX
......
..XXX.
)";
    test(indata, {outdata1});
}


