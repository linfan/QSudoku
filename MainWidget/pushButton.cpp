#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QTimer>
#include "sudokuWidget.h"

void sudokuMain::setButtonNum(QPushButton *pB,int Num,int size)
{
    if(Num==0)
    {
        pB->setIcon(QIcon(":/png/empty.png"));
    }
    else if(Num>=1&&Num<=9)
    {
        QString strIcon = QString::fromUtf8(":/png/");
        strIcon.push_back(QChar(m_cTheme));
        strIcon.push_back(QChar(Num+'0'));
        strIcon.push_back(QString(".png"));
        pB->setIconSize(QSize(size,size));
        pB->setIcon(QIcon(strIcon));
    }
    else
    {
        qDebug() << QObject::tr("ERROR: USE ILLEGAL NUMBER IN FUCTION \"setButtonNum\"") << endl;
    }
}

int sudokuMain::pushButtonDown(QPushButton *pB,int L,int R)
{
    if(m_bFinished)
    {
        return false;
    }
    //qDebug()<<"m_iSetNum: "<<m_iSetNum<<endl;
    if(m_bLocked)
    {
        QMessageBox lock(QMessageBox::Information,QString(tr("提示")),QString(tr("请点击\"开始计时\"再做题!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        lock.exec();
        return false;
    }
    if(writable[L-1][R-1])
    {
        click_Timer->stop();
        if(m_time_between_click!=0 && m_last_click_button == 10*(L-1)+(R-1))//DOUBLE CLICK
        {
            table[L-1][R-1][0] = 0;
            clearButton(pB,L,R);
            if(m_beginPorgressBar && m_iSetNum!=0 && setted[L-1][R-1]==1)
            {
                m_blankNumber++;
                setted[L-1][R-1] = 0;
                m_process = (int)(100*(1-(float)m_blankNumber/(float)m_totalBlank));
                progressBar_1->setValue(m_process);
                sendDatagram(m_process);
            }
        }
        else//SINGLE CLICK
        {
            table[L-1][R-1][0] = m_iSetNum;
            setButtonNum(pB,m_iSetNum,40);
            if(m_beginPorgressBar && m_iSetNum!=0 && setted[L-1][R-1]==0)
            {
                m_blankNumber--;
                setted[L-1][R-1] = 1;
                m_process = (int)(100*(1-(float)m_blankNumber/(float)m_totalBlank));
                progressBar_1->setValue(m_process);
                sendDatagram(m_process);
            }
            if(m_blankNumber==0)////Is The Last One Blank,Finish The Table
            {
                int i,j;
                for(i=0;i<9;i++)
                {
                    for(j=0;j<9;j++)
                    {
                        if(table[i][j][0] != solution[i][j])
                        {
                            QMessageBox fail(QMessageBox::Information,QString(tr("提示")),QString(tr("不正确,再仔细想想-_-!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
                            fail.exec();
                            table[L-1][R-1][0] = 0;
                            clearButton(pB,L,R);
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
                if(rB_online->isChecked())
                {
                    QMessageBox finish(QMessageBox::Information,QString(tr("胜利")),QString(tr("你战胜了对手，好样的^^!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
                    finish.exec();
                }
                else
                {
                    QMessageBox finish(QMessageBox::Information,QString(tr("成功")),QString(tr("你真是太太太厉害了^^!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
                    finish.exec();
                }
                for(i=0;i<9;i++)
                {
                    for(j=0;j<9;j++)
                    {
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

void sudokuMain::clearButton(QPushButton *pB,int L,int R)
{
    if(writable[L-1][R-1])
    {
        table[L-1][R-1][0] = 0;
        setButtonNum(pB,0,40);
    }
}

void sudokuMain::pBk11()
{
    pushButtonDown(pB11,1,1);
}

void sudokuMain::pBk12()
{
    pushButtonDown(pB12,1,2);
}

void sudokuMain::pBk13()
{
    pushButtonDown(pB13,1,3);
}

void sudokuMain::pBk14()
{
    pushButtonDown(pB14,1,4);
}

void sudokuMain::pBk15()
{
    pushButtonDown(pB15,1,5);
}

void sudokuMain::pBk16()
{
    pushButtonDown(pB16,1,6);
}

void sudokuMain::pBk17()
{
    pushButtonDown(pB17,1,7);
}

void sudokuMain::pBk18()
{
    pushButtonDown(pB18,1,8);
}

void sudokuMain::pBk19()
{
    pushButtonDown(pB19,1,9);
}


void sudokuMain::pBk21()
{
    pushButtonDown(pB21,2,1);
}

void sudokuMain::pBk22()
{
    pushButtonDown(pB22,2,2);
}

void sudokuMain::pBk23()
{
    pushButtonDown(pB23,2,3);
}

void sudokuMain::pBk24()
{
    pushButtonDown(pB24,2,4);
}

void sudokuMain::pBk25()
{
    pushButtonDown(pB25,2,5);
}

void sudokuMain::pBk26()
{
    pushButtonDown(pB26,2,6);
}

void sudokuMain::pBk27()
{
    pushButtonDown(pB27,2,7);
}

void sudokuMain::pBk28()
{
    pushButtonDown(pB28,2,8);
}

void sudokuMain::pBk29()
{
    pushButtonDown(pB29,2,9);
}


void sudokuMain::pBk31()
{
    pushButtonDown(pB31,3,1);
}

void sudokuMain::pBk32()
{
    pushButtonDown(pB32,3,2);
}

void sudokuMain::pBk33()
{
    pushButtonDown(pB33,3,3);
}

void sudokuMain::pBk34()
{
    pushButtonDown(pB34,3,4);
}

void sudokuMain::pBk35()
{
    pushButtonDown(pB35,3,5);
}

void sudokuMain::pBk36()
{
    pushButtonDown(pB36,3,6);
}

void sudokuMain::pBk37()
{
    pushButtonDown(pB37,3,7);
}

void sudokuMain::pBk38()
{
    pushButtonDown(pB38,3,8);
}

void sudokuMain::pBk39()
{
    pushButtonDown(pB39,3,9);
}


void sudokuMain::pBk41()
{
    pushButtonDown(pB41,4,1);
}

void sudokuMain::pBk42()
{
    pushButtonDown(pB42,4,2);
}

void sudokuMain::pBk43()
{
    pushButtonDown(pB43,4,3);
}

void sudokuMain::pBk44()
{
    pushButtonDown(pB44,4,4);
}

void sudokuMain::pBk45()
{
    pushButtonDown(pB45,4,5);
}

void sudokuMain::pBk46()
{
    pushButtonDown(pB46,4,6);
}

void sudokuMain::pBk47()
{
    pushButtonDown(pB47,4,7);
}

void sudokuMain::pBk48()
{
    pushButtonDown(pB48,4,8);
}

void sudokuMain::pBk49()
{
    pushButtonDown(pB49,4,9);
}


void sudokuMain::pBk51()
{
    pushButtonDown(pB51,5,1);
}

void sudokuMain::pBk52()
{
    pushButtonDown(pB52,5,2);
}

void sudokuMain::pBk53()
{
    pushButtonDown(pB53,5,3);
}

void sudokuMain::pBk54()
{
    pushButtonDown(pB54,5,4);
}

void sudokuMain::pBk55()
{
    pushButtonDown(pB55,5,5);
}

void sudokuMain::pBk56()
{
    pushButtonDown(pB56,5,6);
}

void sudokuMain::pBk57()
{
    pushButtonDown(pB57,5,7);
}

void sudokuMain::pBk58()
{
    pushButtonDown(pB58,5,8);
}

void sudokuMain::pBk59()
{
    pushButtonDown(pB59,5,9);
}


void sudokuMain::pBk61()
{
    pushButtonDown(pB61,6,1);
}

void sudokuMain::pBk62()
{
    pushButtonDown(pB62,6,2);
}

void sudokuMain::pBk63()
{
    pushButtonDown(pB63,6,3);
}

void sudokuMain::pBk64()
{
    pushButtonDown(pB64,6,4);
}

void sudokuMain::pBk65()
{
    pushButtonDown(pB65,6,5);
}

void sudokuMain::pBk66()
{
    pushButtonDown(pB66,6,6);
}

void sudokuMain::pBk67()
{
    pushButtonDown(pB67,6,7);
}

void sudokuMain::pBk68()
{
    pushButtonDown(pB68,6,8);
}

void sudokuMain::pBk69()
{
    pushButtonDown(pB69,6,9);
}


void sudokuMain::pBk71()
{
    pushButtonDown(pB71,7,1);
}

void sudokuMain::pBk72()
{
    pushButtonDown(pB72,7,2);
}

void sudokuMain::pBk73()
{
    pushButtonDown(pB73,7,3);
}

void sudokuMain::pBk74()
{
    pushButtonDown(pB74,7,4);
}

void sudokuMain::pBk75()
{
    pushButtonDown(pB75,7,5);
}

void sudokuMain::pBk76()
{
    pushButtonDown(pB76,7,6);
}

void sudokuMain::pBk77()
{
    pushButtonDown(pB77,7,7);
}

void sudokuMain::pBk78()
{
    pushButtonDown(pB78,7,8);
}

void sudokuMain::pBk79()
{
    pushButtonDown(pB79,7,9);
}


void sudokuMain::pBk81()
{
    pushButtonDown(pB81,8,1);
}

void sudokuMain::pBk82()
{
    pushButtonDown(pB82,8,2);
}

void sudokuMain::pBk83()
{
    pushButtonDown(pB83,8,3);
}

void sudokuMain::pBk84()
{
    pushButtonDown(pB84,8,4);
}

void sudokuMain::pBk85()
{
    pushButtonDown(pB85,8,5);
}

void sudokuMain::pBk86()
{
    pushButtonDown(pB86,8,6);
}

void sudokuMain::pBk87()
{
    pushButtonDown(pB87,8,7);
}

void sudokuMain::pBk88()
{
    pushButtonDown(pB88,8,8);
}

void sudokuMain::pBk89()
{
    pushButtonDown(pB89,8,9);
}


void sudokuMain::pBk91()
{
    pushButtonDown(pB91,9,1);
}

void sudokuMain::pBk92()
{
    pushButtonDown(pB92,9,2);
}

void sudokuMain::pBk93()
{
    pushButtonDown(pB93,9,3);
}

void sudokuMain::pBk94()
{
    pushButtonDown(pB94,9,4);
}

void sudokuMain::pBk95()
{
    pushButtonDown(pB95,9,5);
}

void sudokuMain::pBk96()
{
    pushButtonDown(pB96,9,6);
}

void sudokuMain::pBk97()
{
    pushButtonDown(pB97,9,7);
}

void sudokuMain::pBk98()
{
    pushButtonDown(pB98,9,8);
}

void sudokuMain::pBk99()
{
    pushButtonDown(pB99,9,9);
}

QPushButton* sudokuMain::getPointFromNumber(int num)
{
    switch(num)
    {
        case 1:
        return pB1;
        case 2:
        return pB2;
        case 3:
        return pB3;
        case 4:
        return pB4;
        case 5:
        return pB5;
        case 6:
        return pB6;
        case 7:
        return pB7;
        case 8:
        return pB8;
        case 9:
        return pB9;
    }
    return 0;
}

void sudokuMain::sideButtonDown(QPushButton *pB,int num)
{
    if(m_bFinished)
    {
        return;
    }
    if(m_bLocked)
    {
        QMessageBox lock(QMessageBox::Information,QString(tr("提示")),QString(tr("请点击\"开始计时\"再做题!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        lock.exec();
        return;
    }
    if(m_iSetNum!=num)
    {
        if(m_iSetNum!=0)
        {
            QPushButton *pB_side = getPointFromNumber(m_iSetNum);
            pB_side->setIconSize(QSize(30,30));
        }
        pB->setIconSize(QSize(40,40));
    }
    m_iSetNum = num;
}

void sudokuMain::pBk1()
{
    sideButtonDown(pB1,1);
}

void sudokuMain::pBk2()
{
    sideButtonDown(pB2,2);
}

void sudokuMain::pBk3()
{
    sideButtonDown(pB3,3);
}

void sudokuMain::pBk4()
{
    sideButtonDown(pB4,4);
}

void sudokuMain::pBk5()
{
    sideButtonDown(pB5,5);
}

void sudokuMain::pBk6()
{
    sideButtonDown(pB6,6);
}

void sudokuMain::pBk7()
{
    sideButtonDown(pB7,7);
}

void sudokuMain::pBk8()
{
    sideButtonDown(pB8,8);
}

void sudokuMain::pBk9()
{
    sideButtonDown(pB9,9);
}


QPushButton* sudokuMain::getPointFromPosition(int L,int R)//L,R should among 1 to 9
{
    switch(L*10+R)
    {
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
