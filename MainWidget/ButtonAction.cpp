#include <QDebug>
#include <QString>
#include <QFile>
#include <QTimer>
#include <QTime>
#include <QPushButton>
#include <QMessageBox>
#include <QFileDialog>
#include <QAbstractButton>
#include "Aboutdlg.h"
#include "ProcessDlg.h"
#include "SudokuWidget.h"
#include "ExplanatryDlg.h"
#include "Logic/ConstPool.h"

void sudokuMain::resetTable() {
    int i, j;
    QPushButton *pB;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            m_table[i][j][0] = 0;
            m_writable[i][j] = true;
            pB = getPointFromPosition(i + 1, j + 1);
            setButtonNum(pB, 0, 40);
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

void sudokuMain::initStatusTable(int table[9][9][10]) {
    int emptyGridCounter = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (table[i][j][0] == 0) {
                emptyGridCounter++;
                m_setted[i][j] = 0;
            } else {
                m_setted[i][j] = 1;
            }
        }
    }
    m_totalBlank = emptyGridCounter;
    m_blankNumber = emptyGridCounter;
}

void sudokuMain::autoSet() {
    if (rB_online->isChecked()) {
        QMessageBox box(QMessageBox::Information, QString(tr("联机对战")),
                        QString(tr("确认开始连接对方主机?")),
                        QMessageBox::Ok | QMessageBox::Cancel, this,
                        Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        box.exec();
        if (box.clickedButton() == box.button(QMessageBox::Cancel)) {
            return;
        }
    }
    int blankGridNum = 0;
    int randNum;
    int baseNum;
    int index, num;
    int select[9], select_from_6[6], select_from_4[4];
    int pos[4] = {11, 12, 21, 22}, L, R;
    for (L = 0; L < 9; L++) {
        for (R = 0; R < 9; R++) {
            m_table[L][R][0] = 0;
        }
    }
    if (rB_easy->isChecked()) {
        blankGridNum = EASY_MODE_BLANK_GRIDS;
    } else if (rB_normal->isChecked()) {
        blankGridNum = NORM_MODE_BLANK_GRIDS;
    } else if (rB_hard->isChecked()) {
        blankGridNum = HARD_MODE_BLANK_GRIDS;
    }
    qsrand((QTime::currentTime()).second() * (QTime::currentTime()).minute());
    //Fill The Frist Row
    for (index = 0; index < 9; index++) {
        select[index] = index + 1;
    }
    baseNum = 9;
    for (index = 0; index < 9; index++) {
        randNum = qAbs(qrand() % baseNum); //Get A Number Between 0 To baseNum-1
        m_table[0][index][0] = select[randNum];
        baseNum--;
        select[randNum] = select[8 - index];
        select[8 - index] = 0;
    }
    //qDebug()<<table[0][0][0]<<' '<<table[0][1][0]<<' '<<table[0][2][0]<<' '<<table[0][3][0]<<' '<<table[0][4][0]<<' '<<table[0][5][0]<<' '<<table[0][6][0]<<' '<<table[0][7][0]<<' '<<table[0][8][0]<<' ';
    //Fill The Frist Volumn
    //Frist Fill table[0][0][0] To table[2][0][0]
    qsrand(qrand());
    index = 0;
    for (num = 1; num <= 9; num++) {
        if (num != m_table[0][0][0] && num != m_table[0][1][0] && num != m_table[0][2][0]) {
            select_from_6[index] = num;
            index++;
        }
    }
    baseNum = 6;
    for (index = 1; index <= 2; index++) {
        randNum = qAbs(qrand() % baseNum); //Get A Number Between 0 To baseNum-1
        m_table[index][0][0] = select_from_6[randNum];
        baseNum--;
        select_from_6[randNum] = select_from_6[6 - index];
        select_from_6[6 - index] = 0;
    }
    //Then table[3][0][0] To table[8][0][0]
    qsrand(qrand());
    index = 0;
    for (num = 1; num <= 9; num++) {
        if (num != m_table[0][0][0] && num != m_table[1][0][0] && num != m_table[2][0][0]) {
            select_from_6[index] = num;
            index++;
        }
    }
    baseNum = 6;
    for (index = 3; index < 9; index++) {
        randNum = qAbs(qrand() % baseNum); //Get A Number Between 0 To baseNum-1
        m_table[index][0][0] = select_from_6[randNum];
        baseNum--;
        select_from_6[randNum] = select_from_6[8 - index];
        select_from_6[8 - index] = 0;
    }
    //qDebug()<<table[0][0][0]<<' '<<table[1][0][0]<<' '<<table[2][0][0]<<' '<<table[3][0][0]<<' '<<table[4][0][0]<<' '<<table[5][0][0]<<' '<<table[6][0][0]<<' '<<table[7][0][0]<<' '<<table[8][0][0]<<' ';
    //File The Left-Top Square
    qsrand(qrand());
    index = 0;
    for (num = 1; num <= 9; num++) {
        if (num != m_table[0][0][0] && num != m_table[0][1][0] && num != m_table[0][2][0]
                && num != m_table[1][0][0] && num != m_table[2][0][0]) {
            select_from_4[index] = num;
            index++;
        }
    }
    baseNum = 4;
    for (index = 0; index < 4; index++) {
        randNum = qAbs(qrand() % baseNum); //Get A Number Between 0 To baseNum-1
        L = (int)(pos[index] / 10);
        R = (int)(pos[index] % 10);
        m_table[L][R][0] = select_from_4[randNum];
        baseNum--;
        select_from_4[randNum] = select_from_4[3 - index];
        select_from_4[3 - index] = 0;
    }
    //qDebug()<<table[0][0][0]<<' '<<table[0][1][0]<<' '<<table[0][2][0]<<' '<<table[1][0][0]<<' '<<table[1][1][0]<<' '<<table[1][2][0]<<' '<<table[2][0][0]<<' '<<table[2][1][0]<<' '<<table[2][2][0]<<' ';
    initStatusTable(m_table);
    calc->getSolution(m_table, m_solution);
    // Store The Table
    for (L = 0; L < 9; L++) {
        for (R = 0; R < 9; R++) {
            m_tableBackup[L][R] = m_table[L][R][0];
        }
    }
    for (num = 0; num < blankGridNum;) {
        qsrand(qrand());
        L = qrand() % 9;
        qsrand(qrand());
        R = qrand() % 9;
        if (m_table[L][R][0] != 0) {
            index = m_table[L][R][0];
            m_table[L][R][0] = 0;
            initStatusTable(m_table);
            if (calc->getSolution(m_table, m_solution)) {
                num++;
                m_tableBackup[L][R] = 0;
                //qDebug()<<num<<"table["<<L<<"]["<<R<<"]Setted";
            } else {
                //table[L][R][0] = index;
                //qDebug()<<num<<"table["<<L<<"]["<<R<<"]Cleared";
                //Restore The "table" Alter By "GetSolution" Function
                for (L = 0; L < 9; L++) {
                    for (R = 0; R < 9; R++) {
                        m_table[L][R][0] = m_tableBackup[L][R];
                    }
                }
            }
        }
    }
    // Now "solution" Is A Full Table
    // Output It For Debug
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
    for (L = 0; L < 9; L++) {
        for (R = 0; R < 9; R++) {
            if (m_table[L][R][0] != 0) {
                pB = getPointFromPosition(L + 1, R + 1);
                setButtonNum(pB, m_table[L][R][0], 40);
                pB->setFlat(true);
                m_writable[L][R] = 0;
                //pB->setDisabled(true);
            }
        }
    }
    for (L = 0; L < 9; L++) {
        for (R = 0; R < 9; R++) {
            m_writableLock[L][R] = m_writable[L][R];
            m_writable[L][R] = 0;//Alter After Being Setted ,Protect "table"
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
    if (rB_single->isChecked()) {
        groupBox_1->setDisabled(true);
        lineEdit_IP->setDisabled(true);
    }
    if (rB_online->isChecked()) {
        startGame();
    }
}

void sudokuMain::giveUp() {
    int i, j;
    QPushButton *pB;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            pB = getPointFromPosition(i + 1, j + 1);
            setButtonNum(pB, 0, 40);
            pB->setFlat(false);
            m_table[i][j][0] = 0;
            m_writable[i][j] = 1;
        }
    }
    m_bLocked = false;
    if (!m_bFinished) {
        sendDatagram(MES_GIVEUP);
    }
    m_bFinished = false;
    pB_setTable->setHidden(false);
    pB_fileSet->setHidden(false);
    pB_autoSet->setHidden(false);
    pB_start->setHidden(true);
    pB_resetTable->setHidden(true);
    pB_giveUp->setHidden(true);
    m_main_Timer->stop();
    m_iTimeSecond = 0;
    m_iTimeMinute = 0;
    m_strTime = QString("00:00");
    lcdNumber->display(QString(m_strTime));
    progressBar_1->setValue(0);
    progressBar_2->setValue(0);
    pB_giveUp->setText(QString(tr("认输")));
    groupBox_1->setDisabled(false);
    groupBox_2->setDisabled(false);
    lineEdit_IP->setDisabled(false);
    m_processDlg->m_bConnected = false;
}

void sudokuMain::startGame() {
    if (rB_online->isChecked() && !m_processDlg->m_bConnected) { //ONLINE PLAYER
        QString ip;
        ip = lineEdit_IP->text();
        if (ip == QString(tr(("127.0.0.1")))) {
            resetTable();
            QMessageBox finish(QMessageBox::Information, QString(tr("提示")),
                               QString(tr("不允许连接本机与本机连接!")), QMessageBox::Ok, this,
                               Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
            finish.exec();
            return;
        }
        if (ip.endsWith(QString(tr(".0"))) || ip.endsWith(QString(tr(".255")))) {
            resetTable();
            QMessageBox finish(QMessageBox::Information, QString(tr("提示")),
                               QString(tr("请输入有效的对方主机地址!")), QMessageBox::Ok, this,
                               Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
            finish.exec();
            return;
        }
        int L, R;
        m_connect_Timer->start(100);
        this->m_processDlg->m_Timer.start(10000);
        m_processDlg->m_bCanceled = false;
        m_processDlg->m_bConnected = false;
        m_processDlg->show();
        this->setVisible(false);
        sendDatagram(MES_REQUEST);//Requesting For Connect
        for (L = 0; L < 9; L++) {
            for (R = 0; R < 9; R++) {
                m_writable[L][R] = m_writableLock[L][R];//Resume Array "writable"
            }
        }
    } else { //SINGLE PLAYER
        int L, R;
        m_main_Timer->start(1000);
        pB_start->setDisabled(true);
        pB_resetTable->setDisabled(true);
        pB_giveUp->setDisabled(false);
        m_beginPorgressBar = 1;
        //qDebug() << "m_blankNumber: " << m_blankNumber <<endl;
        //qDebug() << "m_totalBlank: " << m_totalBlank <<endl;
        //qDebug() << "1-m_blankNumber/m_totalBlank: " << 1-(float)m_blankNumber/(float)m_totalBlank <<endl;
        calc->getSolution(m_table, m_solution);
        int val = (int)(100 * (1 - (float)m_blankNumber / (float)m_totalBlank));
        progressBar_1->setValue(val);
        for (L = 0; L < 9; L++) {
            for (R = 0; R < 9; R++) {
                m_writable[L][R] = m_writableLock[L][R];//Resume Array "writable"
            }
        }
        m_bLocked = false;
        //m_processDlg->m_bConnected = false;
        groupBox_1->setDisabled(true);
        groupBox_2->setDisabled(true);
        lineEdit_IP->setDisabled(true);
    }
}

void sudokuMain::setTable(bool isLoadFromFile) {
    if (rB_online->isChecked()) {
        QMessageBox box(QMessageBox::Information, QString(tr("联机对战")),
                        QString(tr("确认开始连接对方主机?")),
                        QMessageBox::Ok | QMessageBox::Cancel, this,
                        Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        box.exec();
        if (box.clickedButton() == box.button(QMessageBox::Cancel)) {
            return;
        }
    }

    if (isLoadFromFile) {
        try {
            readTableFile(m_table);
        } catch (char c) {
            QMessageBox error(QMessageBox::Critical, QString(tr("错误")),
                              QString(tr("文件读取出错，请确认文件内容!")), QMessageBox::Ok,
                              this, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
            error.exec();
            return;
        }
    }

    // Judge The Table Array
    if (!calc->getSolution(m_table, m_solution)) {
        QMessageBox box(QMessageBox::Information, QString(tr("提示")),
                        QString(tr("此九宫格无解或不是唯一解!")), QMessageBox::Ok, this,
                        Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
        box.exec();
        return;
    }

    initStatusTable(m_table);

    //Set Table
    QPushButton* pB;
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (m_table[x][y][0] != 0) {
                pB = getPointFromPosition(x + 1, y + 1);
                setButtonNum(pB, m_table[x][y][0], 40);
                pB->setFlat(true);
                m_writable[x][y] = 0;
                //pB->setDisabled(true);
            }
        }
    }

    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            m_writableLock[x][y] = m_writable[x][y];
            m_writable[x][y] = 0; // Alter After Being Setted, Protect "table"
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
    if (rB_single->isChecked()) {
        groupBox_1->setDisabled(true);
        lineEdit_IP->setDisabled(true);
    }
    if (rB_online->isChecked()) {
        startGame();
    }
}

void sudokuMain::readTableFile(int table[9][9][10]) {
    QString path = QFileDialog::getOpenFileName(this, tr("Open Table Text"),
                   "./Table", tr("Text Files(*.table)"));
    QFile file(path);
    char Cr;
    file.open(QIODevice::ReadOnly);
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            file.getChar(&Cr);
            if (Cr < '0' || Cr > '9') {
                throw Cr;
            }
            table[x][y][0] = Cr - '0';
        }
        file.getChar(&Cr);
        file.getChar(&Cr);
    }
    file.close();
}

void sudokuMain::win() {
    if (rB_single->isChecked() && !m_bLocked && pB_giveUp->isVisible()
            && pB_giveUp->isEnabled()) {
        int i, j;
        m_main_Timer->stop();
        m_blankNumber = -1;
        m_beginPorgressBar = false;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                m_table[i][j][0] = m_solution[i][j];
                setButtonNum(getPointFromPosition(i + 1, j + 1), m_table[i][j][0], 40);
            }
        }
        m_bFinished = true;
        pB_giveUp->setText(QString(tr("完成")));
        progressBar_1->setValue(100);
        m_bLocked = true;
    }
}

void sudokuMain::expanatry() {
    AboutDlg ab(this);
    ab.exec();
}
