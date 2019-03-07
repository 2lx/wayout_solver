#define BOOST_TEST_MODULE WayOut2Section3Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section3Level01)
{
    const char * indata = 1 + R"(
_X.
.pX
X._
)";
    const char * outdata = 1 + R"(
_12
3..
.._
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level02)
{
    const char * indata = 1 + R"(
__X____
_XP____
___.X__
XX_XP__
XP___.X
__.._XP
__.p.__
___.___
)";
    const char * outdata = 1 + R"(
__1____
_..____
___.2__
.._..__
..___.3
__45_..
__...__
___.___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level03)
{
    const char * indata = 1 + R"(
_X____
.XPX__
_X_.__
_XP.._
___X__
__.___
_.p.X_
__._P_
__XP.X
____X_
)";
    const char * outdata = 1 + R"(
_.____
....__
_._1__
_..2._
___.__
__.___
_..3._
__4_._
__....
____._
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level05)
{
    const char * indata = 1 + R"(
...____
XX.oX__
..__.._
XO.._..
..._XPX
.XPX..X
..__.OX
_.X._.X
__X.p.X
____..X
)";
    const char * outdata = 1 + R"(
...____
.....__
.1__.2_
.3.._4.
..._...
...5...
..__.6.
_..._..
__.7.8.
____...
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level06)
{
    const char * indata = 1 + R"(
..________
.OX_______
_.._______
__PPXXPX__
__.XXXXO._
.XP.o._.P_
.O.X.XX___
_XX_X...._
____pp_XOP
____.OX_..
_____..___
)";
    const char * outdata = 1 + R"(
1.________
.2._______
_.._______
__.....3__
__.4..56._
7....._.._
.8.9...___
_.._.A.B._
____.._.C.
____.D._E.
_____.F___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level07)
{
    const char * indata = 1 + R"(
__.._____
__.p.____
__X.X.___
XX__.XX__
XX..P____
_.O._._X_
_.X__XX.X
____.X...
_____..XX
)";
    const char * outdata = 1 + R"(
__.._____
__1.2____
__....___
..__.3.__
4.5.6____
_.7._._._
_..__8.9.
____...A.
_____....
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level08)
{
    const char * indata = 1 + R"(
____PX_______
__X__XP______
__.._X.._____
_.XPX_XPX____
._XXX__XX____
.._.__X_X_X__
.XX__..O__.._
_P.._X..__XO.
___X._O._O.._
____XP_._XXP_
______.___.__
_______X.P___
________.X___
)";
    const char * outdata = 1 + R"(
____.._______
__1__2.______
__.._..._____
_3.4._...____
._5..__6.____
78_9__._._.__
...__A.B__.C_
_.DE_F..__.G.
___.._HI_J.._
____K._._LM._
______.___.__
_______N..___
________.O___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level09)
{
    const char * indata = 1 + R"(
_X._____
.._p.___
X_X__X__
.p_..X._
_X.Xp_..
__..X_pX
___.__X.
____X.._
)";
    const char * outdata = 1 + R"(
_.._____
12_..___
._.__.__
.._...3_
_...._.4
__56._..
___.__..
____.78_
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section3Level10)
{
    const char * indata = 1 + R"(
X.PXX____
XXX..____
.P.PX____
X.X..____
XPXXP.XXP
____X.P.X
____PXXX.
____...PX
____XXP.X
)";
    const char * outdata = 1 + R"(
...1.____
.2...____
....3____
4....____
.........
____5...6
____...7.
____.....
____.8...
)";
    test(indata, {outdata});
}

