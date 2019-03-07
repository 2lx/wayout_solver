#include <iostream>
#include "wayout_solver.h"

using namespace std;

int main() {
    WayOut::Solver solver;
    const char * input_alphabet  = "_X.HhVvNnOoYyPpDd";
    const char * output_alphabet = " X.";

    if (!solver.read_level_data(cin, input_alphabet)) {
        cerr << "Invalid input data" << endl;
        return 0;
    }

    auto result = solver.solve();
    if (!result.first) {
        cout << "There is no solution" << endl;
        return 0;
    }

    cout << "Solution found (" << result.second << " toggle(s)):" << endl;
    solver.print_solution(cout, output_alphabet);
    return 0;
}
