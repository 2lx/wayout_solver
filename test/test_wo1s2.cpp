#define BOOST_TEST_MODULE WayOut1Section2Tests

#include <boost/test/unit_test.hpp>
#include "test_common.h"

BOOST_AUTO_TEST_CASE(Section2Level01)
{
    const char * indata = 1 + R"(
_..._
_X_._
.VXHX
_X_._
_..._
)";
    const char * outdata = 1 + R"(
_..._
_._._
.X.X.
_._._
_..._
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section2Level05)
{
    const char * indata = 1 + R"(
XX.X..
XX._X.
.X_._X
X_._..
X._X.X
.X.X..
)";
    const char * outdata = 1 + R"(
X...XX
..._..
.X_._X
X_._..
.._..X
..XXX.
)";
    test(indata, {outdata});
}

BOOST_AUTO_TEST_CASE(Section2Level20)
{
    const char * indata = 1 + R"(
XHX..X___
hV_.v._X_
X__X_.___
...vXh.X.
Hh_._.__X
...V.h..V
___X_X._.
hv_._h__X
Xh_HX.VXV
)";
    const char * outdata = 1 + R"(
X.X.X.___
.X_.X._X_
X__._.___
.XXX.XX..
X._._.__.
...X..XXX
___._X._X
XX_._X__.
X._X...X.
)";
    test(indata, {outdata});
}

