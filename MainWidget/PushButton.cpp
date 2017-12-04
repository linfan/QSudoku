#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QTimer>
#include "SudokuWidget.h"

void sudokuMain::setButtonNum(QPushButton *pB, int Num, int size) {
    if (Num == 0) {
        pB->setIcon(QIcon(":/png/empty.png"));
    } else if (Num >= 1 && Num <= 9) {
        QString strIcon = QString::fromUtf8(":/png/");
        strIcon.push_back(QChar(m_cTheme));
        strIcon.push_back(QChar(Num + '0'));
        strIcon.push_back(QString(".png"));
        pB->setIconSize(QSize(size, size));
        pB->setIcon(QIcon(strIcon));
    } else {
        qDebug() << QObject::tr("ERROR: USE ILLEGAL NUMBER IN FUCTION \"setButtonNum\"")
                 << endl;
    }
}

bool sudokuMain::checkGameAlreadyBegin() {
    if (m_bFinished) {
        return false;
    }
    if (m_bLocked) {
        QMessageBox lock(QMessageBox::Information, QString(tr("提示")),
                         QString(tr("请点击\"开始计时\"再做题!")), QMessageBox::Ok, this,
                         Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        lock.exec();
        return false;
    }
    return true;
}

int sudokuMain::pushButtonDown(QPushButton *pB, int L, int R) {
    if (!checkGameAlreadyBegin()) {
        return false;
    }
    if (m_writable[L - 1][R - 1]) {
        m_click_Timer->stop();
        if (m_time_between_click != 0
                && m_last_click_button == 10 * (L - 1) + (R - 1)) { // Double click
            m_table[L - 1][R - 1] = 0;
            clearButton(pB, L, R);
            if (m_beginPorgressBar && m_iSetNum != 0 && m_setted[L - 1][R - 1] == 1) {
                m_blankNumber++;
                m_setted[L - 1][R - 1] = 0;
                m_process = (int)(100 * (1 - (float)m_blankNumber / (float)m_totalBlank));
                progressBar_1->setValue(m_process);
                sendDatagram(m_process);
            }
        } else { // Single click
            m_table[L - 1][R - 1] = m_iSetNum;
            setButtonNum(pB, m_iSetNum, 40);
            if (m_beginPorgressBar && m_iSetNum != 0 && m_setted[L - 1][R - 1] == 0) {
                m_blankNumber--;
                m_setted[L - 1][R - 1] = 1;
                m_process = (int)(100 * (1 - (float)m_blankNumber / (float)m_totalBlank));
                progressBar_1->setValue(m_process);
                sendDatagram(m_process);
            }
            if (m_blankNumber == 0) { // Matrix complete, check result
                if (!matrixEqual(m_table, m_solution)) {
                    QMessageBox fail(QMessageBox::Information, QString(tr("提示")),
                                     QString(tr("不正确,再仔细想想-_-!")), QMessageBox::Ok, this,
                                     Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
                    fail.exec();
                    m_table[L - 1][R - 1] = 0;
                    clearButton(pB, L, R);
                    m_blankNumber = 1;
                    m_setted[L - 1][R - 1] = 0;
                    m_process = (int)(100 * (1 - 1.0 / m_totalBlank));
                    progressBar_1->setValue(m_process);
                    sendDatagram(m_process);
                    return false;
                }
                m_main_Timer->stop();
                m_blankNumber = -1;
                m_beginPorgressBar = false;
                pB_giveUp->setText(QString(tr("完成")));
                sendDatagram(MES_WIN);
                if (rB_online->isChecked()) {
                    QMessageBox finish(QMessageBox::Information, QString(tr("胜利")),
                                       QString(tr("你战胜了对手，好样的^^!")), QMessageBox::Ok, this,
                                       Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
                    finish.exec();
                } else {
                    QMessageBox finish(QMessageBox::Information, QString(tr("成功")),
                                       QString(tr("你真是太太太厉害了^^!")), QMessageBox::Ok, this,
                                       Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
                    finish.exec();
                }
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        m_writable[i][j] = 0;
                    }
                }
                m_bFinished = true;
                m_bLocked = true;
                return true;
            }
        }
        m_last_click_button = 10 * (L - 1) + (R - 1);
        m_time_between_click = 1;
        m_click_Timer->start(100);
    }
    return false;
}

bool sudokuMain::matrixEqual(int left[9][9], int right[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (left[i][j] != right[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void sudokuMain::clearButton(QPushButton *pB, int L, int R) {
    if (m_writable[L - 1][R - 1]) {
        m_table[L - 1][R - 1] = 0;
        setButtonNum(pB, 0, 40);
    }
}

QPushButton* sudokuMain::getPointFromNumber(int num) {
    QPushButton* numBtns[] = { NULL, pB1, pB2, pB3, pB4, pB5, pB6, pB7, pB8, pB9 };
    if (num >= 1 && num <= 9) {
        return numBtns[num];
    }
    return numBtns[0];
}

void sudokuMain::sideButtonDown(QPushButton *pB, int num) {
    if (!checkGameAlreadyBegin()) {
        return;
    }
    if (m_iSetNum != num) {
        if (m_iSetNum != 0) {
            QPushButton *pB_side = getPointFromNumber(m_iSetNum);
            pB_side->setIconSize(QSize(30, 30));
        }
        pB->setIconSize(QSize(40, 40));
    }
    m_iSetNum = num;
}

QPushButton* sudokuMain::getPointFromPosition(int L, int R) {
    SudokuMatrix btnMap = getButtonMatrix();
    // L,R should among 1 to 9
    if (L >= 1 && L <= 9 && R >= 1 && R <= 9) {
        return btnMap[L - 1][R - 1];
    }
    return NULL;
}
