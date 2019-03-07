#define BOOST_TEST_MODULE WayOut2Section5Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section5Level01)
{
    const char * indata = 1 + R"(
__.._
_Y..y
X_y_.
.X.Y_
_Y.__
)";
    const char * outdata = 1 + R"(
__.1_
_.2.3
._4_5
6.7._
_8.__
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level02)
{
    const char * indata = 1 + R"(
..____
y_X.__
X_.Xy_
X.Y_YX
_y..X.
__.__.
__Y.XX
____._
)";
    const char * outdata = 1 + R"(
..____
._..__
1_2.._
..3_.4
_...5.
__6__.
__7..8
____._
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level03)
{
    const char * indata = 1 + R"(
_X.y_____
X__Y.____
yX_.._Xy_
_.Y_XY_yX
__.__.._.
___.y_.__
___y._X__
____YX___
)";
    const char * outdata = 1 + R"(
_1.._____ | _..._____
2__4.____ | .__..____
.C_.3_BD_ | .F_.._E._
_.._.._.. | _.._.._..
__.__.5_. | __.__.._.
___.._6__ | ___.._.__
___87_.__ | ___.._.__
____9A___ | ____..___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level04)
{
    const char * indata = 1 + R"(
__yy______
_..Y._____
XhX..n____
.vv__vy___
_..___nH__
__..___y._
___Yh_yn..
____vn..H_
_____NY.__
______X___
)";
    const char * outdata = 1 + R"(
__3.______ | __..______
_1245_____ | _...._____
.6...B____ | .....E____
...__.D___ | ...__..___
_..___7.__ | _..___..__
__C.___.._ | __F.___.._
___.._.... | ___.._....
____..8.9_ | ____....._
_____.A.__ | _____...__
______.___ | ______.___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level05)
{
    const char * indata = 1 + R"(
__.X.______
__.O.O_____
.X__XX.____
..__o._____
X..Xy.__v__
_X.X.YH..N_
__X__.yH..h
_____XX__n.
____P.P__h.
_____...X__
______X.P__
)";
    const char * outdata = 1 + R"(
__1.2______
__.3.4_____
..__.5.____
67__.8_____
......__.__
_..9.BAC.._
__D__....EF
_____G.__..
____H..__IJ
_____...K__
______L..__
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level06)
{
    const char * indata = 1 + R"(
___XPy.______
___Y.Xp._____
Y__XPy.._____
...__Y.P_____
_PhX._X__..__
_X.YV.__XOXOX
__yN.X_X_.YY.
___XXy_vy_OXO
_______XYh_..
______.vnX___
______yHYX___
________XV___
)";
    const char * outdata = 1 + R"(
___1..2______
___....._____
6__3...4_____
.5.__..._____
_..7._8__..__
_...9.__.ABC.
__.DE._._....
___F.._G._HIJ
_______.LK_..
______.M..___
______.NO.___
________..___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level07)
{
    const char * indata = 1 + R"(
..X______
.O..X____
.X._Xy.__
_..X_o_._
_YY_YX_._
__o_y.__y
___X_._.X
____.XYO.
_____....
)";
    const char * outdata = 1 + R"(
..1______
23..4____
..._...__
_5.6_._._
_7._.8_._
__._..__.
___._9_.A
____BC.D.
_____..E.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level08)
{
    const char * indata = 1 + R"(
__X_____
p..P____
.X..X___
..XX.X__
XX.p.Y._
_....YpY
__YX.X.Y
___Py.X_
____y___
)";
    const char * outdata = 1 + R"(
__._____
..1.____
..2..___
......__
......3_
_4......
__5...6.
___...._
____.___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level09)
{
    const char * indata = 1 + R"(
___oX..______
___yO..y_____
__Y...YO_____
..Xp.__X.____
X.yX.X.X.____
..p_.....OXy_
PY.__.Y..X.YX
_Xy...v.y__XY
___..nX.yX_..
_____.Vh....X
_____.h__VXXY
_____.N.h..__
______.XH..__
)";
    const char * outdata = 1 + R"(
___....______ | ___....______
___.1..._____ | ___....._____
__....32_____ | __......_____
..4.5__..____ | .....__..____
..6.....7____ | .........____
.8._.K...9.._ | ..._.L......_
...__.......A | ...__........
_B.......__C. | _........__..
___......D_.. | ___......._..
_____.E.....F | _____........
_____..__G.H. | _____..__....
_____..IJ..__ | _____......__
______.....__ | ______.....__
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section5Level10)
{
    const char * indata = 1 + R"(
_____X____
____yy.___
___XY.Y.__
__.YX...Y_
_.y.Y.yyy.
Xy....Y.X_
_X.Y..yX__
__Y..y.___
___.yX____
____._____
)";
    const char * outdata = 1 + R"(
_____1____
____...___
___2.34.__
__......8_
_...65...7
...9....A_
_B.C...D__
__.....___
___E.F____
____G_____
)";
    test(indata, {outdata});
}

