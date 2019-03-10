#define BOOST_TEST_MODULE WayOut2Section6Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section6Level01)
{
    const char * indata = 1 + R"(
_X__X___
_Xd_.d__
____Xd__
Xd___X__
DX_Xd___
___._._D
____Xd__
)";
    const char * outdata = 1 + R"(
_1__2___
_.._..__
____3.__
4.___.__
.._5.___
___._._.
____6.__
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level02)
{
    const char * indata = 1 + R"(
___X___
X_X.X__
X__dDX_
_D_D..X
__.__X_
___D.__
____.X_
)";
    const char * outdata1 = 1 + R"(
___1___
._...__
4__5.._
_._...2
__6__3_
___78__
____.._
)";
    const char * outdata2 = 1 + R"(
___1___
2_...__
.__5.._
_._.6.3
__4__._
___78__
____.._
)";
    test(indata, {outdata1, outdata2});
}

BOOST_AUTO_TEST_CASE(Section6Level03)
{
    const char * indata = 1 + R"(
_XX.___
XXX.d__
......_
XDX.XXX
_.XX...
__....X
___..d_
)";
    const char * outdata = 1 + R"(
_1..___
.....__
5....6_
.7...2.
_8....3
__.4...
___.9._
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level04)
{
    const char * indata = 1 + R"(
___.dX______
_X._oX______
_.DP________
p_X___D.____
..__dX_.Y___
Xd__Xy__Yp__
___X__DX____
___XD_.._dXX
____Yy____Xd
_____._d_D__
_______..___
_______X.___
)";
    const char * outdata = 1 + R"(
___..2______ | ___...______
_13_..______ | _.._..______
_4..________ | _...________
._.___..____ | ._.___..____
56__7._G.___ | ..__.._H.___
..__..__..__ | ..__..__..__
___8__..____ | ___.__..____
___9A_BC_.D. | ___.._.._...
____..____.. | ____..____..
_____._._.__ | _____._._.__
_______EF___ | _______..___
_______..___ | _______..___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level06)
{
    const char * indata = 1 + R"(
__X..._____
_y.n_HY____
h.v_X_.N___
XX_X_Y_.Y__
h.nX.v.yv._
..h..XhY..y
_....v.X.vX
__HX_._n_.y
___Xv_N_..H
____YX_.vX_
_____VYXY__
)";
    const char * outdata = 1 + R"(
__...._____
_.1._2.____
..3_4_.5___
.._._._..__
67.8.9..A._
..B..C..D..
_....E.F..G
__.._._._..
___H._I_J.K
____.L_.M._
_____..N.__
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level07)
{
    const char * indata = 1 + R"(
___.h.________
_XP_nd._______
XXXX_.Vn______
X.p...N.O_____
_..._vX._Xd___
___.._X__...X_
___XdX_._..O._
___XX.__X.O___
____.p_d__....
_____..__..Xd.
_______X.X..__
_________.____
)";
    const char * outdata = 1 + R"(
___.1L________
_2._3.._______
...._M.4______
.5......6_____
_.7._.89_.N___
___.._A__.O.B_
___P.._C_.DE._
___..Q__..F___
____.G_.__H...
_____..__I....
_______.JK..__
_________.____
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level08)
{
    const char * indata = 1 + R"(
__Xy.._______
_X.Y.Yy______
__.YyY.______
____..X______
.Xp._X.______
.X.X....h.h__
XP..P.XXHXnN_
_X.p._..NvVX_
___.__.._.XhX
_____.O.O_nXV
______XX..___
______.O.OO__
________...__
)";
    const char * outdata = 1 + R"(
__..1._______
_.2..3.______
__.4...______
____..5______
67.8_9.______
..........A__
..BC..D.E.FG_
_...._..H.I._
___.__.J_..K.
_____.L.M_NO.
______P.Q.___
______.RSTU__
________...__
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level09)
{
    const char * indata = 1 + R"(
___XX______
__.XdX_____
_...X..____
XXd.X.X.___
X....D..X__
_.X.X.X.X._
__..XX..X.X
___X.X.X.Xd
____.D..X._
_____X.X.__
______.X___
)";
    const char * outdata = 1 + R"(
___..______
__.9.A_____
_.B....____
..C...1.___
2....D..3__
_.4.5....._
__........E
___6.....F.
____.G..7._
_____..8.__
______..___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section6Level10)
{
    const char * indata = 1 + R"(
___YY__________
___.p.yy_______
__.y.Xy.h______
Y.X....vX______
XO.y...X.y_____
_Oy.Hd.X..O____
_...o.X...y.v__
_.dX.hXXY.P.vn_
__nv.y....XX.X_
____pXyyX...Xy_
_____X...YPNhX.
______hYO.X..XY
______.pX.D.P__
_______....n___
__________v.___
)";
    const char * outdata = 1 + R"(
___..__________
___....._______
__..12.34______
......5..______
678..Y...._____
_9..ZZ....A____
_....Z..BC.DE__
_.Z..F.G....HI_
__JKL........M_
____....N....._
_____OP....QRST
______..U.Z....
______..V...W__
_______.X...___
__________..___
)";
    test(indata, {outdata});
}

