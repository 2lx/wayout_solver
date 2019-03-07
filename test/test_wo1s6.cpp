#define BOOST_TEST_MODULE WayOut1Section6Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section6Level01)
{
    const char * indata = 1 + R"(
D__
X._
_..
__D
)";
    const char * outdata = 1 + R"(
X__
.._
_..
__.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level03)
{
    const char * indata = 1 + R"(
.d_d_
_._X.
X_D_X
d._._
)";
    const char * outdata = 1 + R"(
.._._
_._X.
X_._X
.._._
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level04)
{
    const char * indata = 1 + R"(
..___
D_.X.
._DdD
D_.X.
X.___
)";
    const char * outdata = 1 + R"(
..___
._...
X_.X.
X_...
..___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level05)
{
    const char * indata = 1 + R"(
___d___
D.D_X.X
X_._D..
..D_XX.
___.___
)";
    const char * outdata1 = 1 + R"(
___.___
XX._...
._._X.X
..._..X
___.___
)";
    const char * outdata2 = 1 + R"(
___.___
..._..X
._._XX.
XX._...
___.___
)";
    test(indata, {outdata1, outdata2});
}

BOOST_AUTO_TEST_CASE(Section6Level06)
{
    const char * indata = 1 + R"(
.X...
.DX..
...X.
XX.Xd
d.X..
)";
    const char * outdata = 1 + R"(
.....
.X...
X....
X..X.
X.X..
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level07)
{
    const char * indata = 1 + R"(
_XDX_
X_XXX
PPPPP
_XD_X
_DX_D
)";
    const char * outdata = 1 + R"(
_X.._
._.X.
.....
_.._.
_.X_.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level09)
{
    const char * indata = 1 + R"(
.y.__
X_dX_
D_YD.
X___.
_DY.D
)";
    const char * outdata1 = 1 + R"(
..1__ | ...__
._2._ | ._.._
3_4.. | ._...
.___. | .___.
_5... | _6...
)";
    test(indata, {outdata1});
}

BOOST_AUTO_TEST_CASE(Section6Level11)
{
    const char * indata = 1 + R"(
____.__
dX_.O._
X___.oX
_..O_X_
X.d.___
_..._X_
__X_.d_
)";
    const char * outdata = 1 + R"(
____X__
X._XXX_
.___X.X
_X.X_X_
.X..___
_.XX_X_
__._.._
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level12)
{
    const char * indata = 1 + R"(
Xd__X
XvhhD
__X__
D.vHh
X__dX
)";
    const char * outdata = 1 + R"(
X.__X
.....
__.__
XXX..
.__X.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level13)
{
    const char * indata = 1 + R"(
.X._XX
Xd_D_.
._X_.D
_.d_X.
)";
    const char * outdata = 1 + R"(
..._.X
.X_._.
._X_.X
_.._X.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level14)
{
    const char * indata = 1 + R"(
__D__.
.d_.X.
XX_d_d
.d_...
__.__X
)";
    const char * outdata = 1 + R"(
__.__.
.._X..
.X_X_.
.._.XX
__.__.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Level15)
{
    const char * indata = 1 + R"(
_y..XXd_
X.y__X..
.d_X._X.
._XyY._d
X_.YY._X
_.D..D._
)";
    const char * outdata1 = 1 + R"(
_.12..._ | _......_
...__3.. | ...__...
B._45_6. | .._.._..
7_89D._C | ._..E._.
._A..._. | ._...._.
_......_ | _......_
)";
    test(indata, {outdata1});
}

BOOST_AUTO_TEST_CASE(Section6Level19)
{
    const char * indata = 1 + R"(
.d_odO_X.
X-------X
__O.dX.__
XD_X_X_dX
__od.dX__
Xd_O_._D.
__...O.__
D_______.
X._O.d_XD
)";
    const char * outdata = 1 + R"(
XX_..X_X.
._______X
__X.X..__
X._._._X.
__.X.X.__
X._X_._..
__..XXX__
X_______.
.._XX._X.
)";
    test(indata, {outdata});
}

