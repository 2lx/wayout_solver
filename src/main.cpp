#include <iostream>
#include <fstream>
#include "wayout_solver.h"
#include "wayout_formatter.h"

using namespace std;
using namespace WayOut;

const char * input_alphabet  = "_X.HhVvNnOoYyPpDd";
const char * output_alphabet = " X.";

void print_prompt() {
    const tuple<uint, uint, const char *> conventions[] = {
        {Formatter::I_NONE, Formatter::I_NONE, "tile missing"},
        {Formatter::I_NORU, Formatter::I_NORD, "normal tile"},
        {Formatter::I_HARU, Formatter::I_HARD, "horizontal arrow"},
        {Formatter::I_VARU, Formatter::I_VARD, "vertical arrow"},
#ifdef WAYOUT2
        {Formatter::I_DARU, Formatter::I_DARD, "diagonal arrow"},
#endif
        {Formatter::I_SINU, Formatter::I_SIND, "single dot"},
        {Formatter::I_YELU, Formatter::I_YELD, "yellow"},
#ifdef WAYOUT2
        {Formatter::I_PLSU, Formatter::I_PLSD, "hex"},
#else
        {Formatter::I_PLSU, Formatter::I_PLSD, "plus"},
#endif
        {Formatter::I_DBLU, Formatter::I_DBLD, "double dot"},
    };

    cout << "Tiles conventions (mode on, mode off, description)\n";
    for (const auto [ind1, ind2, descr]: conventions) {
        cout << "'" << input_alphabet[ind1] << "' '"
             << input_alphabet[ind2] << "' - " << descr << '\n';
    }
    cout << "\nPlease, enter a rectangular level layout terminating with Ctrl-d:\n";
}

int main(int argc, char* argv[]) {
    WayOut::Solver solver;
    bool succ = false;

    if (argc == 1) {
        print_prompt();
        succ = solver.read_level_data(cin, input_alphabet);
    } else if (argc == 2) {
        ifstream fs(argv[1], ios_base::in);
        succ = solver.read_level_data(fs, input_alphabet);
    } else {
        cerr << "Invalid argument count. Usage: " << argv[0] << " FILE" << endl;
        return 0;
    }

    if (!succ) {
        cerr << "Invalid input data" << endl;
        return 0;
    }

    auto result = solver.solve();
    if (!result.first) {
        cout << "There is no solution" << endl;
        return 0;
    }

    cout << "Solution found (" << result.second << " moves):" << endl;
    solver.print_solution(cout, output_alphabet);
    return 0;
}
