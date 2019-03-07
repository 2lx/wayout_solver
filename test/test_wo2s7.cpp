#define BOOST_TEST_MODULE WayOut2Section7Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section7Level01)
{
    const char * indata = 1 + R"(
X.X__
...._
X...X
_....
__X.X
)";
    const char * outdata = 1 + R"(
1..__
..2._
.34.5
_..6.
__7..
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section7Level02)
{
    const char * indata = 1 + R"(
___hX___
_nn.N.__
_h.h_XH_
_.hv__.n
XXv_N.Hv
_HNhHV._
__v...H_
___.____
)";
    const char * outdata = 1 + R"(
___1.___
_23.4.__
_.5._.._
_67.__.8
9.A_.BCD
_.E..FG_
__.HI.._
___J____
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section7Level03)
{
    const char * indata = 1 + R"(
..X_____
...X..X_
X.._.p..
_._OX..p
_X..__X.
_.OX_yY_
_XyY..X_
__.O.___
)";
    const char * outdata = 1 + R"(
..1_____ | ..._____
23....._ | ......._
..._..4. | ..._....
_._5..6. | _._.....
_..7__D. | _...__E.
_.8._.._ | _..._.._
_.9.AB._ | _......_
__.C.___ | __...___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section7Level04)
{
    const char * indata = 1 + R"(
___.X_____
___._.____
X.XX_.X___
.._O__X.__
_.X_.XO.__
___oX_X.O_
___O.oO_..
____X__X.O
_____X.O_.
)";
    const char * outdata = 1 + R"(
___.._____
___._1____
...._.2___
3._4__.5__
_6._.78.__
___.._9AB_
___CD.E_..
____.__.FG
_____H.I_.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section7Level05)
{
    const char * indata = 1 + R"(
Xy_____
XX.____
X_Y.___
yY._.y_
_..Xy.Y
.Y_Y._X
_._....
__YyY__
____X._
)";
    const char * outdata = 1 + R"(
1._____ | .._____
.C.____ | .F.____
._..___ | ._..___
.3._.5_ | ..._.._
_.2..46 | _......
7._.._8 | .._.._.
_9_DAB. | _._G...
__.E.__ | __...__
____.._ | ____.._
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section7Level06)
{
    const char * indata = 1 + R"(
Vh.Y..___
.nd.yoX__
v..Vn.n._
Y.yn.Onvd
_.pyP.Pyy
__pO....X
___.DhY.P
)";
    const char * outdata = 1 + R"(
1.B.23___
..C....__
4.D....._
.5..678..
_........
__.A....9
___..EF..
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section7Level07)
{
    const char * indata = 1 + R"(
X.P.___
.X..d._
XhX..._
..X....
X.PXX.d
_n..vX.
__X.X.X
)";
    const char * outdata = 1 + R"(
...8___
.1..9._
2....A_
.......
3.4...B
_....5.
__6.7..
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section7Level08)
{
    const char * indata = 1 + R"(
_._D______
__D__d____
X_XX__.___
_X__X__X__
__D_DX_.._
___._X._X.
____D__X_X
_____._D._
______DX..
______XX__
)";
    const char * outdata = 1 + R"(
_._.______
__.__6____
._5.__.___
_7__.__1__
__._8._23_
___._.._4.
____.__._.
_____._.9_
______..A.
______B.__
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section7Level09)
{
    const char * indata = 1 + R"(
_..X.___
XXX__.__
._X_Xn__
yYX__.X_
_..X_Xn.
___Y._X.
____..._
)";
    const char * outdata = 1 + R"(
_12..___
3..__.__
._4_56__
.8.__.._
_.7._.9.
___.._A.
____BC._
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section7Level10)
{
    const char * indata = 1 + R"(
_X..____
.pX_.___
.._..p__
P_.X._._
XXX_PX.X
_P.X.._.
__.PX_.p
___XXXX_
)";
    const char * outdata = 1 + R"(
_.1.____
2.3_4___
.._.5.__
._..._._
.6._.7..
_....._8
__..9_A.
___...._
)";
    test(indata, {outdata});
}

