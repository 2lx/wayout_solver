#define BOOST_TEST_MODULE WayOut1Section1Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section1Level01)
{
    const char * indata = 1 + R"(
.X.
XXX
.X.
)";
    const char * outdata = 1 + R"(
...
.X.
...
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level02)
{
    const char * indata = 1 + R"(
XX_
X.X
_XX
)";
    const char * outdata = 1 + R"(
X._
...
_.X
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level03)
{
    const char * indata = 1 + R"(
X__
.X_
..X
)";
    const char * outdata1 = 1 + R"(
X__
.X_
..X
)";
    const char * outdata2 = 1 + R"(
X__
.._
XX.
)";
    const char * outdata3 = 1 + R"(
.__
XX_
.X.
)";
    test(indata, {outdata1, outdata2, outdata3});
}

BOOST_AUTO_TEST_CASE(Section1Level04)
{
    const char * indata = 1 + R"(
.X__
X.__
__.X
__.X
)";
    const char * outdata = 1 + R"(
.X__
X.__
__X.
__X.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level05)
{
    const char * indata = 1 + R"(
_._
.X.
_._
)";
    const char * outdata = 1 + R"(
_X_
XXX
_X_
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level06)
{
    const char * indata = 1 + R"(
_X.X
X_..
XX_X
XXX_
)";
    const char * outdata1 = 1 + R"(
_.XX
X_.X
.._.
.X._
)";
    const char * outdata2 = 1 + R"(
_X.X
X_..
.._X
.X._
)";

    test(indata, {outdata1, outdata2});
}

BOOST_AUTO_TEST_CASE(Section1Level07)
{
    const char * indata = 1 + R"(
.X.
.X.
XX.
)";
    const char * outdata1 = 1 + R"(
.XX
XX.
...
)";

    test(indata, {outdata1});
}

BOOST_AUTO_TEST_CASE(Section1Level08)
{
    const char * indata = 1 + R"(
X..___
X_.___
._.X.X
X.X._.
___._X
___XX.
)";
    const char * outdata1 = 1 + R"(
...___
X_.___
._.X.X
X.X._.
___._X
___.X.
)";

    test(indata, {outdata1});
}

BOOST_AUTO_TEST_CASE(Section1Level09)
{
    const char * indata = 1 + R"(
.X.X__
X..X__
..____
XX_XX_
___._X
___X.X
)";
    const char * outdata1 = 1 + R"(
.X.X__
X...__
..____
X._X._
___._.
___X.X
)";
    const char * outdata2 = 1 + R"(
..X.__
..X.__
XX____
.._X._
___._.
___X.X
)";

    test(indata, {outdata1, outdata2});
}

BOOST_AUTO_TEST_CASE(Section1Level10)
{
    const char * indata = 1 + R"(
__.._
__.X.
X....
...__
_.X__
)";
    const char * outdata1 = 1 + R"(
__.X_
__XXX
XX.X.
X.X__
_XX__
)";

    test(indata, {outdata1});
}

BOOST_AUTO_TEST_CASE(Section1Level15)
{
    const char * indata = 1 + R"(
X_XXXX
.__._.
X_X__X
X..X_X
)";
    const char * outdata = 1 + R"(
X_X..X
.__._.
X_X__X
...X_.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section1Level20)
{
    const char * indata = 1 + R"(
..._XX.
.X._...
.....XX
__.X.__
..X..XX
.X._X.X
X.._XXX
)";
    const char * outdata = 1 + R"(
.X._..X
XXX_X.X
.X..X..
__.X.__
..X..X.
.X._X..
X.._..X
)";
    test(indata, {outdata});
}

