#define BOOST_TEST_MODULE WayOut2Section1Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section1Level01)
{
    const char * indata = 1 + R"(
__.__
___.X
_X_XX
XXX__
_X___
)";
    const char * outdata = 1 + R"(
__X__
___X.
_._..
.X.__
_.___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level03)
{
    const char * indata = 1 + R"(
..XX
.X_X
X_.X
XX..
)";
    const char * outdata = 1 + R"(
....
.._X
._X.
X..X
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level05)
{
    const char * indata = 1 + R"(
_X.___
_X_X__
__.X._
.X_._X
XX._X.
_.X___
)";
    const char * outdata = 1 + R"(
_..___
_1_.__
__.2._
34_._5
..6_7.
_..___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level06)
{
    const char * indata = 1 + R"(
XX.X____
._.X.___
X_.X..__
.__._.._
.._..__X
_X_.X_X.
__..X..X
)";
    const char * outdata = 1 + R"(
.1..____
._.2.___
._...3__
4__._.5_
6._..__.
_._.._..
__...78.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level07)
{
    const char * indata = 1 + R"(
X..__
X_X._
X.X_X
_._..
__X.X
)";
    const char * outdata = 1 + R"(
...__
1_.._
..2_.
_._.3
__.45
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level08)
{
    const char * indata = 1 + R"(
___._________
___....______
__..__X______
XX.X._.X_____
_..X..X..____
_X._.X.XXX___
_X.X_._....._
___XXX..._XX_
____....X..._
_____X__..XXX
______.XXX.__
______...X___
_________.___
)";
    const char * outdata = 1 + R"(
___._________
___....______
__..__.______
.1..._.2_____
_..3..4..____
_5._.6...7___
_..8_._....._
___...9.._A._
____...B...._
_____.__...C.
______D.E..__
______.F..___
_________.___
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level10)
{
    const char * indata = 1 + R"(
___X_____
___..____
__X.X____
X...X.___
_.X....X_
___....XX
____XX.__
____..___
_____X___
)";
    const char * outdata = 1 + R"(
___1_____
___..____
__2.3____
4.....___
_.5.67.._
___....8.
____9..__
____..___
_____A___
)";
    test(indata, {outdata});
}

