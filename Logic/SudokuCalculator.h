#ifndef SUDOKU_H
#define SUDOKU_H

class SudokuCalculator {
public:
    bool getSolution(int table[9][9], int solution[9][9]);
    bool isSolvable(int table[9][9]);
    void generateQuzzle(int blankGridCount, int table[9][9], int solution[9][9]);
};

#endif // SUDOKU_H
