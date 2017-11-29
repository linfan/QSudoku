#include <QDebug>
#include <QString>
#include <QFile>
#include <QTimer>
#include <QTime>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QAbstractButton>
#include "aboutdlg.h"
#include "processDlg.h"
#include "sudokuWidget.h"
#include "explanatryDlg.h"

void sudokuMain::resetTable()
{
    int i,j;
    QPushButton *pB;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            table[i][j][0] = 0;
            writable[i][j] = true;
            pB = getPointFromPosition(i+1,j+1);
            setButtonNum(pB,0,40);
            pB->setFlat(false);
        }
    }
    m_bLocked = false;
    pB_setTable->setHidden(false);
    pB_fileSet->setHidden(false);
    pB_autoSet->setHidden(false);
    pB_start->setHidden(true);
    pB_resetTable->setHidden(true);
    pB_giveUp->setHidden(true);
    pB_resetTable->setDisabled(true);
    pB_start->setDisabled(true);
    pB_giveUp->setDisabled(false);
    groupBox_2->setDisabled(false);
    groupBox_1->setDisabled(false);
    lineEdit_IP->setDisabled(false);
}

void sudokuMain::autoSet()
{
    if(rB_online->isChecked())
    {
        QMessageBox box(QMessageBox::Information,QString(tr("联机对战")),QString(tr("确认开始连接对方主机?")),QMessageBox::Ok|QMessageBox::Cancel,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        box.exec();
        if(box.clickedButton()==box.button(QMessageBox::Cancel))
        {
            return;
        }
    }
    int blankGridNum = 0;
    int randNum;
    int baseNum;
    int index,num;
    int select[9],select_from_6[6],select_from_4[4];
    int pos[4] = {11,12,21,22},L,R;
    for(L=0;L<9;L++)
    {
        for(R=0;R<9;R++)
        {
            table[L][R][0] = 0;
        }
    }
    if(rB_easy->isChecked())
    {
        blankGridNum = 15;
    }
    else if(rB_normal->isChecked())
    {
        blankGridNum = 30;
    }
    else if(rB_hard->isChecked())
    {
        blankGridNum = 45;
    }
    qsrand((QTime::currentTime()).second()*(QTime::currentTime()).minute());
    //Fill The Frist Row
    for(index=0;index<9;index++)
    {
        select[index] = index+1;
    }
    baseNum = 9;
    for(index=0;index<9;index++)
    {
        randNum = qAbs(qrand()%baseNum);//Get A Number Between 0 To baseNum-1
        table[0][index][0] = select[randNum];
        baseNum--;
        select[randNum] = select[8-index];
        select[8-index] = 0;
    }
    //qDebug()<<table[0][0][0]<<' '<<table[0][1][0]<<' '<<table[0][2][0]<<' '<<table[0][3][0]<<' '<<table[0][4][0]<<' '<<table[0][5][0]<<' '<<table[0][6][0]<<' '<<table[0][7][0]<<' '<<table[0][8][0]<<' ';
    //Fill The Frist Volumn
    //Frist Fill table[0][0][0] To table[2][0][0]
    qsrand(qrand());
    index=0;
    for(num=1;num<=9;num++)
    {
        if(num!=table[0][0][0] && num!=table[0][1][0] && num!=table[0][2][0])
        {
            select_from_6[index] = num;
            index++;
        }
    }
    baseNum = 6;
    for(index=1;index<=2;index++)
    {
        randNum = qAbs(qrand()%baseNum);//Get A Number Between 0 To baseNum-1
        table[index][0][0] = select_from_6[randNum];
        baseNum--;
        select_from_6[randNum] = select_from_6[6-index];
        select_from_6[6-index] = 0;
    }
    //Then table[3][0][0] To table[8][0][0]
    qsrand(qrand());
    index=0;
    for(num=1;num<=9;num++)
    {
        if(num!=table[0][0][0] && num!=table[1][0][0] && num!=table[2][0][0])
        {
            select_from_6[index] = num;
            index++;
        }
    }
    baseNum = 6;
    for(index=3;index<9;index++)
    {
        randNum = qAbs(qrand()%baseNum);//Get A Number Between 0 To baseNum-1
        table[index][0][0] = select_from_6[randNum];
        baseNum--;
        select_from_6[randNum] = select_from_6[8-index];
        select_from_6[8-index] = 0;
    }
    //qDebug()<<table[0][0][0]<<' '<<table[1][0][0]<<' '<<table[2][0][0]<<' '<<table[3][0][0]<<' '<<table[4][0][0]<<' '<<table[5][0][0]<<' '<<table[6][0][0]<<' '<<table[7][0][0]<<' '<<table[8][0][0]<<' ';
    //File The Left-Top Square
    qsrand(qrand());
    index=0;
    for(num=1;num<=9;num++)
    {
        if(num!=table[0][0][0] && num!=table[0][1][0] && num!=table[0][2][0] && num!=table[1][0][0] && num!=table[2][0][0])
        {
            select_from_4[index] = num;
            index++;
        }
    }
    baseNum = 4;
    for(index=0;index<4;index++)
    {
        randNum = qAbs(qrand()%baseNum);//Get A Number Between 0 To baseNum-1
        L = (int)(pos[index]/10);
        R = (int)(pos[index]%10);
        table[L][R][0] = select_from_4[randNum];
        baseNum--;
        select_from_4[randNum] = select_from_4[3-index];
        select_from_4[3-index] = 0;
    }
    //qDebug()<<table[0][0][0]<<' '<<table[0][1][0]<<' '<<table[0][2][0]<<' '<<table[1][0][0]<<' '<<table[1][1][0]<<' '<<table[1][2][0]<<' '<<table[2][0][0]<<' '<<table[2][1][0]<<' '<<table[2][2][0]<<' ';
    GetSolution(table,solution);
    //Store The Table
    for(L=0;L<9;L++)
    {
        for(R=0;R<9;R++)
        {
            tableBackup[L][R] = table[L][R][0];
        }
    }
    for(num=0;num<blankGridNum;)
    {
        qsrand(qrand());
        L = qrand()%9;
        qsrand(qrand());
        R = qrand()%9;
        if(table[L][R][0]!=0)
        {
            index = table[L][R][0];
            table[L][R][0] = 0;
            if(GetSolution(table,solution))
            {
                num++;
                tableBackup[L][R] = 0;
                //qDebug()<<num<<"table["<<L<<"]["<<R<<"]Setted";
            }
            else
            {
                //table[L][R][0] = index;
                //qDebug()<<num<<"table["<<L<<"]["<<R<<"]Cleared";
                //Restore The "table" Alter By "GetSolution" Function
                for(L=0;L<9;L++)
                {
                    for(R=0;R<9;R++)
                    {
                        table[L][R][0] = tableBackup[L][R];
                    }
                }
            }
        }
    }
    //Now "solution" Is A Full Table
    //Output It For Debug
    /*for(L=0;L<9;L++)//Output It For Debug
    {
        for(R=0;R<9;R++)
        {
            QPushButton *pB = getPointFromPosition(L+1,R+1);
            setButtonNum(pB,table[L][R][0],40);
        }
    }*/
    //Set Table
    QPushButton* pB;
    for(L=0;L<9;L++)
    {
        for(R=0;R<9;R++)
        {
            if(table[L][R][0]!=0)
            {
                pB = getPointFromPosition(L+1,R+1);
                setButtonNum(pB,table[L][R][0],40);
                pB->setFlat(true);
                writable[L][R] = 0;
                //pB->setDisabled(true);
            }
        }
    }
    for(L=0;L<9;L++)
    {
        for(R=0;R<9;R++)
        {
            writableLock[L][R] = writable[L][R];
            writable[L][R] = 0;//Alter After Being Setted ,Protect "table"
        }
    }
    m_bLocked = true;
    pB_setTable->setHidden(true);
    pB_fileSet->setHidden(true);
    pB_autoSet->setHidden(true);
    pB_start->setHidden(false);
    pB_resetTable->setHidden(false);
    pB_giveUp->setHidden(false);
    pB_resetTable->setDisabled(false);
    pB_start->setDisabled(false);
    pB_giveUp->setDisabled(true);
    groupBox_2->setDisabled(true);
    if(rB_single->isChecked())
    {
        groupBox_1->setDisabled(true);
        lineEdit_IP->setDisabled(true);
    }
    if(rB_online->isChecked())
    {
        startGame();
    }
}

void sudokuMain::giveUp()
{
    int i,j;
    QPushButton *pB;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            pB = getPointFromPosition(i+1,j+1);
            setButtonNum(pB,0,40);
            pB->setFlat(false);
            table[i][j][0] = 0;
            writable[i][j] = 1;
        }
    }
    m_bLocked = false;
    if(!m_bFinished)
    {
        sendDatagram(MES_GIVEUP);
    }
    m_bFinished = false;
    pB_setTable->setHidden(false);
    pB_fileSet->setHidden(false);
    pB_autoSet->setHidden(false);
    pB_start->setHidden(true);
    pB_resetTable->setHidden(true);
    pB_giveUp->setHidden(true);
    main_Timer->stop();
    m_iTimeSecond = 0;
    m_iTimeMinute = 0;
    strTime = QString("00:00");
    lcdNumber->display(QString(strTime));
    progressBar_1->setValue(0);
    progressBar_2->setValue(0);
    pB_giveUp->setText(QString(tr("认输")));
    groupBox_1->setDisabled(false);
    groupBox_2->setDisabled(false);
    lineEdit_IP->setDisabled(false);
    m_processDlg->m_bConnected = false;
}

void sudokuMain::startGame()
{
    if(rB_online->isChecked() && !m_processDlg->m_bConnected)//ONLINE PLAYER
    {
        QString ip;
        ip = lineEdit_IP->text();
        if(ip==QString(tr(("127.0.0.1"))))
        {
            resetTable();
            QMessageBox finish(QMessageBox::Information,QString(tr("提示")),QString(tr("不允许连接本机与本机连接!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
            finish.exec();
            return;
        }
        if(ip.endsWith(QString(tr(".0")))||ip.endsWith(QString(tr(".255"))))
        {
            resetTable();
            QMessageBox finish(QMessageBox::Information,QString(tr("提示")),QString(tr("请输入有效的对方主机地址!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
            finish.exec();
            return;
        }
        int L,R;
        connect_Timer->start(100);
        this->m_processDlg->m_Timer.start(10000);
        m_processDlg->m_bCanceled = false;
        m_processDlg->m_bConnected = false;
        m_processDlg->show();
        this->setVisible(false);
        sendDatagram(MES_REQUEST);//Requesting For Connect
        for(L=0;L<9;L++)
        {
            for(R=0;R<9;R++)
            {
                writable[L][R] = writableLock[L][R];//Resume Array "writable"
            }
        }
    }
    else//SINGLE PLAYER
    {
        int L,R;
        main_Timer->start(1000);
        pB_start->setDisabled(true);
        pB_resetTable->setDisabled(true);
        pB_giveUp->setDisabled(false);
        m_beginPorgressBar = 1;
        //qDebug() << "m_blankNumber: " << m_blankNumber <<endl;
        //qDebug() << "m_totalBlank: " << m_totalBlank <<endl;
        //qDebug() << "1-m_blankNumber/m_totalBlank: " << 1-(float)m_blankNumber/(float)m_totalBlank <<endl;
        GetSolution(table,solution);
        int val = (int)(100*(1-(float)m_blankNumber/(float)m_totalBlank));
        progressBar_1->setValue(val);
        for(L=0;L<9;L++)
        {
            for(R=0;R<9;R++)
            {
                writable[L][R] = writableLock[L][R];//Resume Array "writable"
            }
        }
        m_bLocked = false;
        //m_processDlg->m_bConnected = false;
        groupBox_1->setDisabled(true);
        groupBox_2->setDisabled(true);
        lineEdit_IP->setDisabled(true);
    }
}

void sudokuMain::setTable()
{
    if(rB_online->isChecked())
    {
        QMessageBox box(QMessageBox::Information,QString(tr("联机对战")),QString(tr("确认开始连接对方主机?")),QMessageBox::Ok|QMessageBox::Cancel,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        box.exec();
        if(box.clickedButton()==box.button(QMessageBox::Cancel))
        {
            return;
        }
    }
    int L,R;
    //Judge The Table Array
    int bOK = GetSolution(table,solution);
    if(!bOK)
    {
        QMessageBox box(QMessageBox::Information,QString(tr("提示")),QString(tr("当前九宫格无解或不是唯一解!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        box.exec();
        return;
    }
    else
    {
        //Set Table
        QPushButton* pB;
        for(L=0;L<9;L++)
        {
            for(R=0;R<9;R++)
            {
                if(table[L][R][0]!=0)
                {
                    pB = getPointFromPosition(L+1,R+1);
                    setButtonNum(pB,table[L][R][0],40);
                    pB->setFlat(true);
                    writable[L][R] = 0;
                    //pB->setDisabled(true);
                }
            }
        }
    }
    for(L=0;L<9;L++)
    {
        for(R=0;R<9;R++)
        {
            writableLock[L][R] = writable[L][R];
            writable[L][R] = 0;//Alter After Being Setted ,Protect "table"
        }
    }
    m_bLocked = true;
    pB_setTable->setHidden(true);
    pB_fileSet->setHidden(true);
    pB_autoSet->setHidden(true);
    pB_start->setHidden(false);
    pB_resetTable->setHidden(false);
    pB_giveUp->setHidden(false);
    pB_resetTable->setDisabled(false);
    pB_start->setDisabled(false);
    pB_giveUp->setDisabled(true);
    groupBox_2->setDisabled(true);
    if(rB_single->isChecked())
    {
        groupBox_1->setDisabled(true);
        lineEdit_IP->setDisabled(true);
    }
    if(rB_online->isChecked())
    {
        startGame();
    }
}

void sudokuMain::fileSet()
{
    if(rB_online->isChecked())
    {
        QMessageBox box(QMessageBox::Information,QString(tr("联机对战")),QString(tr("确认开始连接对方主机?")),QMessageBox::Ok|QMessageBox::Cancel,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        box.exec();
        if(box.clickedButton()==box.button(QMessageBox::Cancel))
        {
            return;
        }
    }
    int L,R;
    QString path = QFileDialog::getOpenFileName(this, tr("Open Table Text"), "./Table", tr("Text Files(*.table)"));
    QFile file(path);
    char Cr;
    file.open(QIODevice::ReadOnly);
    for(L=0;L<9;L++)
    {
        for(R=0;R<9;R++)
        {
            file.getChar(&Cr);
            if(Cr<'0'||Cr>'9')
            {
                QMessageBox error(QMessageBox::Critical,QString(tr("错误")),QString(tr("文件读取出错，请确认文件内容!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
                error.exec();
                return;
            }
            table[L][R][0] = Cr - '0';
        }
        file.getChar(&Cr);
        file.getChar(&Cr);
    }
    file.close();
    //Judge The Table Array
    int bOK = GetSolution(table,solution);
    if(!bOK)
    {
        QMessageBox box(QMessageBox::Information,QString(tr("提示")),QString(tr("此九宫格无解或不是唯一解!")),QMessageBox::Ok,this,Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        box.exec();
    }
    else
    {
        //Set Table
        QPushButton* pB;
        for(L=0;L<9;L++)
        {
            for(R=0;R<9;R++)
            {
                if(table[L][R][0]!=0)
                {
                    pB = getPointFromPosition(L+1,R+1);
                    setButtonNum(pB,table[L][R][0],40);
                    pB->setFlat(true);
                    writable[L][R] = 0;
                    //pB->setDisabled(true);
                }
            }
        }
    }
    for(L=0;L<9;L++)
    {
        for(R=0;R<9;R++)
        {
            writableLock[L][R] = writable[L][R];
            writable[L][R] = 0;//Alter After Being Setted ,Protect "table"
        }
    }
    m_bLocked = true;
    pB_setTable->setHidden(true);
    pB_fileSet->setHidden(true);
    pB_autoSet->setHidden(true);
    pB_start->setHidden(false);
    pB_resetTable->setHidden(false);
    pB_giveUp->setHidden(false);
    pB_resetTable->setDisabled(false);
    pB_start->setDisabled(false);
    pB_giveUp->setDisabled(true);
    groupBox_2->setDisabled(true);
    if(rB_single->isChecked())
    {
        groupBox_1->setDisabled(true);
        lineEdit_IP->setDisabled(true);
    }
    if(rB_online->isChecked())
    {
        startGame();
    }
}

void sudokuMain::win()
{
    if(rB_single->isChecked() && !m_bLocked && pB_giveUp->isVisible() && pB_giveUp->isEnabled())
    {
        int i,j;
        main_Timer->stop();
        m_blankNumber = -1;
        m_beginPorgressBar = false;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                table[i][j][0] = solution[i][j];
                setButtonNum(getPointFromPosition(i+1,j+1),table[i][j][0],40);
            }
        }
        m_bFinished = true;
        pB_giveUp->setText(QString(tr("完成")));
        progressBar_1->setValue(100);
        m_bLocked = true;
    }
}

void sudokuMain::expanatry()
{
    aboutDlg ab(this);
    ab.exec();
}
