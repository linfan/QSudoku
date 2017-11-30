#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QTimer>
#include "sudokuWidget.h"

void sudokuMain::setButtonNum(QPushButton *pB, int Num, int size) {
    if (Num==0) {
        pB->setIcon(QIcon(":/png/empty.png"));
    } else if (Num>=1&&Num<=9) {
        QString strIcon = QString::fromUtf8(":/png/");
        strIcon.push_back(QChar(m_cTheme));
        strIcon.push_back(QChar(Num+'0'));
        strIcon.push_back(QString(".png"));
        pB->setIconSize(QSize(size, size));
        pB->setIcon(QIcon(strIcon));
    } else {
        qDebug() << QObject::tr("ERROR: USE ILLEGAL NUMBER IN FUCTION \"setButtonNum\"")
                 << endl;
    }
}

int sudokuMain::pushButtonDown(QPushButton *pB, int L, int R) {
    if (m_bFinished) {
        return false;
    }
    //qDebug()<<"m_iSetNum: "<<m_iSetNum<<endl;
    if (m_bLocked) {
        QMessageBox lock(QMessageBox::Information, QString(tr("提示")),
                         QString(tr("请点击\"开始计时\"再做题!")), QMessageBox::Ok, this,
                         Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        lock.exec();
        return false;
    }
    if (writable[L-1][R-1]) {
        click_Timer->stop();
        if (m_time_between_click!=0
                && m_last_click_button == 10*(L-1)+(R-1)) { //DOUBLE CLICK
            table[L-1][R-1][0] = 0;
            clearButton(pB, L, R);
            if (m_beginPorgressBar && m_iSetNum!=0 && setted[L-1][R-1]==1) {
                m_blankNumber++;
                setted[L-1][R-1] = 0;
                m_process = (int)(100*(1-(float)m_blankNumber/(float)m_totalBlank));
                progressBar_1->setValue(m_process);
                sendDatagram(m_process);
            }
        } else { //SINGLE CLICK
            table[L-1][R-1][0] = m_iSetNum;
            setButtonNum(pB, m_iSetNum, 40);
            if (m_beginPorgressBar && m_iSetNum!=0 && setted[L-1][R-1]==0) {
                m_blankNumber--;
                setted[L-1][R-1] = 1;
                m_process = (int)(100*(1-(float)m_blankNumber/(float)m_totalBlank));
                progressBar_1->setValue(m_process);
                sendDatagram(m_process);
            }
            if (m_blankNumber==0) { ////Is The Last One Blank,Finish The Table
                int i, j;
                for (i=0; i<9; i++) {
                    for (j=0; j<9; j++) {
                        if (table[i][j][0] != solution[i][j]) {
                            QMessageBox fail(QMessageBox::Information, QString(tr("提示")),
                                             QString(tr("不正确,再仔细想想-_-!")), QMessageBox::Ok, this,
                                             Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
                            fail.exec();
                            table[L-1][R-1][0] = 0;
                            clearButton(pB, L, R);
                            m_blankNumber++;
                            setted[L-1][R-1] = 0;
                            m_process = (int)(100*(1-(float)m_blankNumber/(float)m_totalBlank));
                            progressBar_1->setValue(m_process);
                            sendDatagram(m_process);
                            return false;
                        }
                    }
                }
                main_Timer->stop();
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
                for (i=0; i<9; i++) {
                    for (j=0; j<9; j++) {
                        writable[i][j] = 0;
                    }
                }
                m_bFinished = true;
                m_bLocked = true;
                return true;
            }
        }
        m_last_click_button = 10*(L-1)+(R-1);
        m_time_between_click = 1;
        click_Timer->start(100);
    }
    return false;
}

void sudokuMain::clearButton(QPushButton *pB, int L, int R) {
    if (writable[L-1][R-1]) {
        table[L-1][R-1][0] = 0;
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
    if (m_bFinished) {
        return;
    }
    if (m_bLocked) {
        QMessageBox lock(QMessageBox::Information, QString(tr("提示")),
                         QString(tr("请点击\"开始计时\"再做题!")), QMessageBox::Ok, this,
                         Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        lock.exec();
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


QPushButton* sudokuMain::getPointFromPosition(int L, int R) { //L,R should among 1 to 9
    switch (L*10+R) {
    case 11:
        return pB11;
    case 12:
        return pB12;
    case 13:
        return pB13;
    case 14:
        return pB14;
    case 15:
        return pB15;
    case 16:
        return pB16;
    case 17:
        return pB17;
    case 18:
        return pB18;
    case 19:
        return pB19;

    case 21:
        return pB21;
    case 22:
        return pB22;
    case 23:
        return pB23;
    case 24:
        return pB24;
    case 25:
        return pB25;
    case 26:
        return pB26;
    case 27:
        return pB27;
    case 28:
        return pB28;
    case 29:
        return pB29;

    case 31:
        return pB31;
    case 32:
        return pB32;
    case 33:
        return pB33;
    case 34:
        return pB34;
    case 35:
        return pB35;
    case 36:
        return pB36;
    case 37:
        return pB37;
    case 38:
        return pB38;
    case 39:
        return pB39;

    case 41:
        return pB41;
    case 42:
        return pB42;
    case 43:
        return pB43;
    case 44:
        return pB44;
    case 45:
        return pB45;
    case 46:
        return pB46;
    case 47:
        return pB47;
    case 48:
        return pB48;
    case 49:
        return pB49;

    case 51:
        return pB51;
    case 52:
        return pB52;
    case 53:
        return pB53;
    case 54:
        return pB54;
    case 55:
        return pB55;
    case 56:
        return pB56;
    case 57:
        return pB57;
    case 58:
        return pB58;
    case 59:
        return pB59;

    case 61:
        return pB61;
    case 62:
        return pB62;
    case 63:
        return pB63;
    case 64:
        return pB64;
    case 65:
        return pB65;
    case 66:
        return pB66;
    case 67:
        return pB67;
    case 68:
        return pB68;
    case 69:
        return pB69;

    case 71:
        return pB71;
    case 72:
        return pB72;
    case 73:
        return pB73;
    case 74:
        return pB74;
    case 75:
        return pB75;
    case 76:
        return pB76;
    case 77:
        return pB77;
    case 78:
        return pB78;
    case 79:
        return pB79;

    case 81:
        return pB81;
    case 82:
        return pB82;
    case 83:
        return pB83;
    case 84:
        return pB84;
    case 85:
        return pB85;
    case 86:
        return pB86;
    case 87:
        return pB87;
    case 88:
        return pB88;
    case 89:
        return pB89;

    case 91:
        return pB91;
    case 92:
        return pB92;
    case 93:
        return pB93;
    case 94:
        return pB94;
    case 95:
        return pB95;
    case 96:
        return pB96;
    case 97:
        return pB97;
    case 98:
        return pB98;
    case 99:
        return pB99;
    }
    return 0;
}
