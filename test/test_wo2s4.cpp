#define BOOST_TEST_MODULE WayOut2Section4Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section4Level01)
{
    const char * indata = 1 + R"(
__._____
_.Xn____
__nn.___
.._XXv__
Xh.XhNH_
_.N._v..
__.v._._
___X.___
)";
    const char * outdata = 1 + R"(
__._____
_.12____
__3..___
.._.45__
.6.7..8_
_.9._...
__.A._._
___..___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section4Level02)
{
    const char * indata = 1 + R"(
X._____
X.X____
_.._v._
__Vh.N.
N.h.h.h
HV.nn__
_.H_.._
____XXX
_____XX
)";
    const char * outdata = 1 + R"(
1._____
..2____
_.._3._
__45.6.
7.89A.B
.C.DE__
_F._.._
____.G.
_____..
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section4Level04)
{
    const char * indata = 1 + R"(
____XX____
____X.X___
__XXXXn___
__XXX__XX_
XhXXp__p.P
.pv__....X
_..__vX.__
___n.Ph.__
___X..____
____XX____
)";
    const char * outdata = 1 + R"(
____..____
____.1.___
__.2..3___
__...__.._
.45..__.6.
..7__.89..
_..__.AB__
___C.D..__
___.E.____
____..____
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section4Level05)
{
    const char * indata = 1 + R"(
__XXX_____
____..____
.XXX_n.___
_.VXX_.n__
_X__n._.X_
___v_X_Xn.
___XN___X.
____.X.V__
_____Vnh__
)";
    const char * outdata = 1 + R"(
__.1._____
____..____
.234_5.___
_6..7_89__
_.__.A_.._
___B_._.C.
___.D___E.
____...F__
_____GHI__
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section4Level06)
{
    const char * indata = 1 + R"(
.H.vX_____
V__nHn____
N_.___.___
..hnh.Hn__
vV___N_.X_
_n_H._._vn
__N._NV_X.
___v._._hn
____N_.n_n
_____.H.Hv
)";
    const char * outdata = 1 + R"(
.1..._____
2__345____
._6___.___
..789.AB__
.C___D_.._
_._E._._..
__F._GH_..
___.._._IJ
____K_.._L
_____.M.NO
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section4Level07)
{
    const char * indata = 1 + R"(
X...H____
.____X___
VNX.oXn__
n.v____X_
......._v
_XOXXO_X.
__....__X
___XX.nv.
____XoXXX
)";
    const char * outdata = 1 + R"(
.12.3____
.____.___
45...6.__
7.8____9_
.....A._B
_.C..D_E.
__....__.
___F..GH.
____...I.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section4Level08)
{
    const char * indata = 1 + R"(
..XXH_____
V__N_.____
._XHX_V___
.NX_VX.X__
X_X_X_X_N_
_._._._X_X
__N_Xv_HXX
___Xh.XX_V
____.__n_X
_____XhXX.
)";
    const char * outdata = 1 + R"(
....1_____
.__2_.____
3_.4._5___
6.._7...__
._8_._9_A_
_._._._._.
__._B._C..
___D..E._F
____.__._.
_____G.H..
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section4Level09)
{
    const char * indata = 1 + R"(
___vP__________
___XXXvO_______
__X.____v______
HXvN._o_V______
.__X_____._____
_vP._nVXH.n____
_O__n.n_PH.h.__
_._.._XO.__._._
__Xv__h__VHh_O_
____N.OX_._pNN_
_____X_Nnhv__..
______v_n.__.ON
______X__._hV__
_______hO.VH___
__________Np___
)";
    const char * outdata = 1 + R"(
___1.__________
___..2.3_______
__..____4______
5.6.._._.______
.__7_____._____
_.8._.9....____
_A__..._.B.CD__
_E_.._.F.__._._
__..__G__.H._I_
____..J._._.K._
_____L_....__..
______._..__MN.
______O__._..__
_______.P..Q___
__________R.___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section4Level10)
{
    const char * indata = 1 + R"(
...o.X_____
XX.X..O____
.O...O..___
X..X____X__
X.X_Xhn_PX_
X.O_hXN_X.X
_X._VV._...
__X____X..p
___X.PXX.P.
____X...X.X
_____X.p.P.
)";
    const char * outdata = 1 + R"(
......_____
......1____
.2..34..___
5..6____7__
..._.89_.._
..A_.B._...
_C._D.._..E
__.____F...
___......GH
____I.J...K
_____...L..
)";
    test(indata, {outdata});
}

