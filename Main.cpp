#include <iostream>
#include "solver.h"

int main(int argc, char* argv[]) {
    int brd[9][9] = {
    {8, 7, 6, 9, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 6, 0, 0, 0},
    {0, 4, 0, 3, 0, 5, 8, 0, 0},
    {4, 0, 0, 0, 0, 0, 2, 1, 0},
    {0, 9, 0, 5, 0, 0, 0, 0, 0},
    {0, 5, 0, 0, 4, 0, 3, 0, 6},
    {0, 2, 9, 0, 0, 0, 0, 0, 8},
    {0, 0, 4, 6, 9, 0, 1, 7, 3},
    {0, 0, 0, 0, 0, 1, 0, 0, 4} };

    Solver solver = Solver(brd);

    if (solver.solve()) {
        solver.print();
    }
    else {
        std::cout << "False" << std::endl;
    }
    std::cin.get();
}