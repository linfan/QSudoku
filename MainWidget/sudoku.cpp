#include <QDebug>
#include "sudokuWidget.h"
#include "../Logic/linkList.h"

//The Calculation
int sudokuMain::GetSolution(int table[9][9][10], int solution[9][9]) {
    int tablecopy[9][3][3];
    int T_L, T_R;           //The Current Position
    int bStepBack = 0;      //If "1" Means The Last Step Has No Usable Value
    int bGotValuable;       //If "0" Means Current Position Has No Usable Value
    int bSolvable = 1;      //If "0" Means This Sudoku_Table Has No Solution
    int bUnique = 1;        //If "0" Means These is More Than One Possible Answers
    int NumOfSolutions = 0; //The Number Of Possible Answer
    int tempN;              //A Temporary Position
    int tempT;              //A Temporary Value
    LinkList recode;        //"recode" tell the positions in "table" which are writable

    //Put Usable Positions In To "recode"
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (table[i][j][0] == 0) {
                recode.Push(i, j);
                setted[i][j] = 0;
            } else {
                setted[i][j] = 1;
            }
        }
    }

    recode.cur = recode.head->next;
    //head Node is ALLTHEWAYS NULL

    if (recode.counts == 0) { //The Table Is Full
        return 0;
    }
    m_totalBlank = recode.counts;
    m_blankNumber = m_totalBlank;
    //qDebug() << "m_totalBlank: " << m_totalBlank <<endl;
    //qDebug() << "m_blankNumber: " << m_blankNumber <<endl;

    // i -> Row, j -> Column, k -> Depth
    // Check Frist To Kill Morbid Table
    for (int i = 0; i < 9; i++) { // The Each Number In Nine Rows Should Be Unique
        for (int k = 0; k < 8; k++) {
            for (int j = k + 1; j < 9; j++) {
                if (table[i][k][0] == table[i][j][0] && table[i][k][0] != 0) {
                    return 0;
                }
            }
        }
    }
    for (int j = 0; j < 9; j++) { // The Each Number In Nine Volunms Should Be Unique
        for (int k = 0; k < 8; k++) {
            for (int i = k + 1; i < 9; i++) {
                if (table[k][j][0] == table[i][j][0] && table[i][j][0] != 0) {
                    return 0;
                }
            }
        }
    }

    int list[] = {00, 03, 06, 30, 33, 36, 60, 63, 66};
    int table_num[9];
    for (int k = 0; k < 9; k++) {
        for (int i = list[k] / 10, index = 0; i < (list[k] / 10) + 3;
                i++) { //The Nine "33" 's Square Each Number Should Be Unique
            for (int j = list[k] % 10; j < (list[k] % 10) + 3; j++, index++) {
                table_num[index] = table[i][j][0];
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 9; j++) {
                if (table_num[i] == table_num[j] && table_num[i] != 0) {
                    return 0;
                }
            }
        }
    }

    do {
        bGotValuable = 0;

        //Get A Usable Position
        T_L = recode.cur->L;
        T_R = recode.cur->R;

        if (bStepBack == 0) {
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
                table[T_L][T_R][k] = 0;   //All To "0"
            }

            for (int j = 0; j < 9; j++) { //The Same Row With Position Of [T_L][T_R]
                tempT = table[T_L][j][0];
                if (j != T_R) {
                    table[T_L][T_R][tempT] = tempT;
                }
            }

            for (int i = 0; i < 9; i++) { //The Same Column With Position Of [T_L][T_R]
                tempT = table[i][T_R][0];
                if (i != T_L) {
                    table[T_L][T_R][tempT] = tempT;
                }
            }

            //The Same "33" 's Square With Position Of [T_L][T_R]
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    tempN = (int(T_L / 3)) * 3 + T_R / 3;
                    tempT = tablecopy[tempN][i][j];
                    table[T_L][T_R][tempT] = tempT;
                }
            }

            for (int k = 1; k < 10; k++) { //Get Inverse
                if (table[T_L][T_R][k] == 0) {
                    table[T_L][T_R][k] = k;
                    bGotValuable = 1;
                } else {
                    table[T_L][T_R][k] = 0;
                }
            }
        } else {
            table[T_L][T_R][0] = 0;
            bStepBack = 0;
            for (int k = 1; k < 10; k++) { //DeTect The Usable Values
                if (table[T_L][T_R][k] != 0) {
                    bGotValuable = 1;
                    break;
                }
            }
        }

        if (bGotValuable == 0) { //If No Usable Value, Move Back
            recode.cur = recode.cur->prov;
            bStepBack = 1;

            if (recode.cur == recode.head) {
                recode.cur = recode.end;
                if (NumOfSolutions == 1) {
                    bSolvable = 1;
                    bUnique = 1;
                } else {
                    bSolvable = 0;
                    bUnique = 0;
                }
                break;//If No Possible Solution ,Do Break
            }
        } else { //If Got Usable Value, Move On
            for (int k = 1; k < 10; k++) {
                if (table[T_L][T_R][k] != 0) {
                    table[T_L][T_R][k] = 0;
                    table[T_L][T_R][0] = k;
                    break;
                }
            }
            recode.cur = recode.cur->next;
        }

        if (recode.cur == recode.end) {
            NumOfSolutions++;
            if (NumOfSolutions == 1) { //Recode The Frist Solution
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        solution[i][j] = table[i][j][0];
                    }
                }
                //"'Reach End' But 'Neither 'Insolvable' Or 'MultiSolutions''",Do continue
                bStepBack = 1;
                recode.cur = recode.cur->prov;
                continue;
            }
            if (NumOfSolutions >= 2) { //If More THan One Possible Answer ,Do Break
                bUnique = 0;
                break;
            }
        }
    } while (recode.cur != recode.end); //If "No Reach The End",Do Loop

    if (bUnique) { //Can NOT Use "bSolvable" ,May Be MultiSolution
        return 1;
    } else { //No Solution Or MultiSolution
        return 0;
    }
}

