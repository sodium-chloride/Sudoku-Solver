#include <iostream>
#include "solver.h"

Solver::Solver(int brd[9][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            board[r][c] = brd[r][c];
        }
    }
}

bool Solver::findEmptySquare(int& row, int& col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool Solver::squareIsSafe(int row, int col, int num) {
    //Check row
    for (int c = 0; c < 9; c++) {
        if (board[row][c] == num) {
            return true;
        }
    }
    //Check column
    for (int r = 0; r < 9; r++) {
        if (board[r][col] == num) {
            return true;
        }
    }
    //Check box
    int startCol = col - (col % 3);
    int startRow = row - (row % 3);
    for (int r = startRow; r < startRow + 3; r++) {
        for (int c = startCol; c < startCol + 3; c++) {
            if (board[r][c] == num) {
                return true;
            }
        }
    }
    return false;
}

bool Solver::solve() {
    int row = 0;
    int col = 0;

    //Find empty spot, if none puzzle is solved
    if (!findEmptySquare(row, col)) {
        return true;
    }

    //Sovle square
    for (int num = 1; num <= 9; num++) {
        if (!squareIsSafe(row, col, num)) {
            board[row][col] = num;
            if (solve()) {
                return true;
            }
            board[row][col] = 0;
        }
    }

    //Trigger backtracking 
    return false;
}

void Solver::print() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            std::cout << board[r][c] << " ";
        }
        std::cout << std::endl;
    }
}