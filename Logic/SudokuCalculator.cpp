#include "PosStack.h"
#include "SudokuCalculator.h"

// The Calculation
bool SudokuCalculator::getSolution(int table[9][9][10], int solution[9][9]) {
    int tablecopy[9][3][3];
    int T_X, T_Y;              // The current position
    bool bStepBack = false;    // If true means the last step has no usable value
    bool bGotValuable = false; // If false means current position has no usable value
    bool bUnique = true;       // If false means these has no Solution or more than one possible answers
    int NumOfSolutions = 0;    // The Number Of Possible Answer
    int tempN;                 // A Temporary Position
    int tempT;                 // A Temporary Value
    PosStack recode;           // "recode" tell the positions in "table" which are writable

    // Put Usable Positions In To "recode"
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (table[i][j][0] == 0) {
                recode.push(i, j);
            }
        }
    }

    // Head Node is ALLTHEWAYS NULL
    recode.cur = recode.bottom->up;

    if (recode.counts == 0) { // The Table Is Full
        return false;
    }

    // i -> Row, j -> Column, k -> Depth
    // Check Frist To Kill Morbid Table
    for (int i = 0; i < 9; i++) { // The Each Number In Nine Rows Should Be Unique
        for (int k = 0; k < 8; k++) {
            for (int j = k + 1; j < 9; j++) {
                if (table[i][k][0] == table[i][j][0] && table[i][k][0] != 0) {
                    return false;
                }
            }
        }
    }
    for (int j = 0; j < 9; j++) { // The Each Number In Nine Volunms Should Be Unique
        for (int k = 0; k < 8; k++) {
            for (int i = k + 1; i < 9; i++) {
                if (table[k][j][0] == table[i][j][0] && table[i][j][0] != 0) {
                    return false;
                }
            }
        }
    }

    int list[] = {00, 03, 06, 30, 33, 36, 60, 63, 66};
    int table_num[9];
    for (int k = 0; k < 9; k++) {
        for (int i = list[k] / 10, index = 0; i < (list[k] / 10) + 3;
                i++) { // The Nine 3x3's Square Each Number Should Be Unique
            for (int j = list[k] % 10; j < (list[k] % 10) + 3; j++, index++) {
                table_num[index] = table[i][j][0];
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 9; j++) {
                if (table_num[i] == table_num[j] && table_num[i] != 0) {
                    return false;
                }
            }
        }
    }

    do {
        bGotValuable = false;

        // Get a usable position
        T_X = recode.cur->X;
        T_Y = recode.cur->Y;

        if (!bStepBack) {
            // table -> tablecopy
            int i = -1;
            for (int j = 0; j < 9; j++) {
                if (j % 3 != 0) {
                    i -= 3;
                }
                for (int k = 0; k < 9; k++) {
                    if (k % 3 == 0) {
                        i++;
                    }
                    tablecopy[i][j % 3][k % 3] = table[j][k][0];
                }
            }

            for (int k = 0; k < 10; k++) {
                table[T_X][T_Y][k] = 0;   // All To "0"
            }

            for (int j = 0; j < 9; j++) { // The Same Row With Position Of [T_L][T_R]
                tempT = table[T_X][j][0];
                if (j != T_Y) {
                    table[T_X][T_Y][tempT] = tempT;
                }
            }

            for (int i = 0; i < 9; i++) { // The Same Column With Position Of [T_L][T_R]
                tempT = table[i][T_Y][0];
                if (i != T_X) {
                    table[T_X][T_Y][tempT] = tempT;
                }
            }

            // The Same 3x3's Square With Position Of [T_L][T_R]
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    tempN = (int(T_X / 3)) * 3 + T_Y / 3;
                    tempT = tablecopy[tempN][i][j];
                    table[T_X][T_Y][tempT] = tempT;
                }
            }

            for (int k = 1; k < 10; k++) { // Get Inverse
                if (table[T_X][T_Y][k] == 0) {
                    table[T_X][T_Y][k] = k;
                    bGotValuable = true;
                } else {
                    table[T_X][T_Y][k] = 0;
                }
            }
        } else {
            table[T_X][T_Y][0] = 0;
            bStepBack = false;
            for (int k = 1; k < 10; k++) { // DeTect The Usable Values
                if (table[T_X][T_Y][k] != 0) {
                    bGotValuable = true;
                    break;
                }
            }
        }

        if (!bGotValuable) { // If No Usable Value, Move Back
            recode.cur = recode.cur->down;
            bStepBack = true;

            if (recode.cur == recode.bottom) {
                recode.cur = recode.cap;
                if (NumOfSolutions == 1) {
                    bUnique = true;
                } else {
                    bUnique = false;
                }
                break;  // If No Possible Solution, Do Break
            }
        } else { // If Got Usable Value, Move On
            for (int k = 1; k < 10; k++) {
                if (table[T_X][T_Y][k] != 0) {
                    table[T_X][T_Y][k] = 0;
                    table[T_X][T_Y][0] = k;
                    break;
                }
            }
            recode.cur = recode.cur->up;
        }

        if (recode.cur == recode.cap) {
            NumOfSolutions++;
            if (NumOfSolutions == 1) { // Recode The Frist Solution
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        solution[i][j] = table[i][j][0];
                    }
                }
                //"'Reach End' But 'Neither 'Insolvable' Or 'MultiSolutions''",Do continue
                bStepBack = true;
                recode.cur = recode.cur->down;
                continue;
            }
            if (NumOfSolutions >= 2) { // If More Than One Possible Answer, Do Break
                bUnique = false;
                break;
            }
        }
    } while (recode.cur != recode.cap); // If "No Reach The End", Do Loop

    if (bUnique) {
        return true;   // Get the onle solution
    } else {
        return false;  // No solution or multi solutions
    }
}

