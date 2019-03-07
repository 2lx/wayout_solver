#define BOOST_TEST_MODULE WayOut2Section2Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section2Level01)
{
    const char * indata = 1 + R"(
XX._
XoX.
.XO.
_...
)";
    const char * outdata = 1 + R"(
1.._
....
..2.
_..3
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section2Level03)
{
    const char * indata = 1 + R"(
_..__
.._X_
O_O._
_X._o
___XX
)";
    const char * outdata = 1 + R"(
_..__
1._._
2_34_
_.._.
___5.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section2Level04)
{
    const char * indata = 1 + R"(
__..___
_XXO.__
o....X_
X..O...
_.X...O
__.oX._
___.X__
)";
    const char * outdata = 1 + R"(
__.1___
_..2.__
.3...._
.4.5.6.
_..7..8
__9..._
___A.__
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section2Level05)
{
    const char * indata = 1 + R"(
.Xo..____
O___.X___
._.._____
.__X._.O_
._._XX_..
__.o___.O
__oX._X_.
______X._
____.X.._
)";
    const char * outdata = 1 + R"(
1..23____
4___..___
._56_____
7__.._89_
A_B_C._..
__D.___EF
__..._G_.
______.._
____..HI_
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section2Level06)
{
    const char * indata = 1 + R"(
_._______
XXX______
.._X_____
_..______
_X.X.____
_.XX._X__
_.X..X.X_
___XXX.__
___..__XX
___..X___
___XO____
____XX___
)";
    const char * outdata = 1 + R"(
_._______
...______
.1_2_____
_3.______
_....____
_..4._5__
_....6.._
___7...__
___..__8.
___.9.___
___.A____
____..___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section2Level07)
{
    const char * indata = 1 + R"(
.XX_____
oX_o____
._X_.___
_._._X__
__..O.__
__.O..__
__X_._._
___X_X_X
____._.O
_____o_.
______XX
)";
    const char * outdata = 1 + R"(
..1_____
.._.____
2_3_.___
_4_._.__
__..56__
__.7..__
__8_._._
___._9_.
____._.A
_____._.
______.B
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section2Level08)
{
    const char * indata = 1 + R"(
__...______
__O__O_____
.._.X_.____
X_.________
_.__..X_XX_
_.X_X.._XXX
__..____X.X
___X_XXX__X
________._X
______X.XO_
_______.O__
)";
    const char * outdata = 1 + R"(
__1.2______
__3__4_____
.._5._6____
._.________
_7__.8._.9_
_.A_.B._...
__.C____D..
___._E..__F
________G_.
______H..I_
_______.J__
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section2Level09)
{
    const char * indata = 1 + R"(
X...XOX.O_____
_.OXO..O..____
__.X..O...O___
___.O...OX.X__
____..O..XOO._
_____.X.O..X.X
)";
    const char * outdata = 1 + R"(
1..2.3..4_____
_.5.6.78..____
__....9...A___
___BC...D.E.__
____..F...GH._
_____...I.J..K
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section2Level10)
{
    const char * indata = 1 + R"(
__..____
_O.XX___
X.XO.X__
.O....._
_..X..OX
__.X..._
___O..__
____X___
)";
    const char * outdata = 1 + R"(
__..____
_1...___
...2.3__
.4.5..._
_6....7.
__...8._
___9.A__
____.___
)";
    test(indata, {outdata});
}
