#include <boost/test/unit_test.hpp>
#include "wayout_solver.h"

#include <string_view>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool test(const string_view & indata, const vector<string_view> & outdata) {
    WayOut::Solver solver;
    istringstream iss(string{indata});

    bool is_read = solver.read_level_data(iss, "_X.HhVvNnOoYyPpDd");
    BOOST_REQUIRE_MESSAGE(is_read == true, "Test failed: Invalid input data");

    auto result = solver.solve();
    BOOST_REQUIRE_MESSAGE(result.first == true, "Test failed: Solution was not found");

    ostringstream ossformat1, ossformat2;
    solver.print_solution(ossformat1, "_X.", false);
    solver.print_solution(ossformat2);

    BOOST_REQUIRE_MESSAGE(
        find(begin(outdata), end(outdata), ossformat1.str()) != end(outdata) ||
        find(begin(outdata), end(outdata), ossformat2.str()) != end(outdata),
         "\nTest failed:\nInput data:\n" << indata
        << "Exptected data:\n" << outdata[0]
        << "Observed data:\n" << ossformat2.str());

    return ossformat1.str() == outdata[0] || ossformat2.str() == outdata[0];
}
