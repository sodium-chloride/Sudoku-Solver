#pragma once

#ifndef SOLVER_H
#define SOLVER_H

class Solver {
public:
    int board[9][9];

    Solver(int brd[9][9]);

    bool findEmptySquare(int& row, int& col);
    bool squareIsSafe(int row, int col, int num);
    bool solve();
    void print();
};

#endif