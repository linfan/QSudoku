#include <QDebug>
#include <QString>
#include <QFile>
//#include <QTimer>
//#include <QTime>
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
            m_table[i][j] = 0;
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

void sudokuMain::initStatusTable(int table[9][9]) {
    int emptyGridCounter = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (table[i][j] == 0) {
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
    int blankGridCount = rB_easy->isChecked() ? EASY_MODE_BLANK_GRIDS :
                         rB_normal->isChecked() ? NORM_MODE_BLANK_GRIDS : HARD_MODE_BLANK_GRIDS;
    calc->generateQuzzle(blankGridCount, m_table, m_solution);
    initStatusTable(m_table);
    //Set Table
    QPushButton* pB;
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            if (m_table[x][y] != 0) {
                pB = getPointFromPosition(x + 1, y + 1);
                setButtonNum(pB, m_table[x][y], 40);
                pB->setFlat(true);
                m_writable[x][y] = 0;
                //pB->setDisabled(true);
            }
        }
    }
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            m_writableLock[x][y] = m_writable[x][y];
            m_writable[x][y] = 0;//Alter After Being Setted ,Protect "table"
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
            m_table[i][j] = 0;
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
    if (rB_online->isChecked() && !m_processDlg->m_bConnected) { // ONLINE PLAYER
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
        m_connect_Timer->start(100);
        this->m_processDlg->m_Timer.start(10000);
        m_processDlg->m_bCanceled = false;
        m_processDlg->m_bConnected = false;
        m_processDlg->show();
        this->setVisible(false);
        sendDatagram(MES_REQUEST);//Requesting For Connect
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                m_writable[x][y] = m_writableLock[x][y];//Resume Array "writable"
            }
        }
    } else { // SINGLE PLAYER
        m_main_Timer->start(1000);
        pB_start->setDisabled(true);
        pB_resetTable->setDisabled(true);
        pB_giveUp->setDisabled(false);
        m_beginPorgressBar = 1;
        calc->getSolution(m_table, m_solution);
        int val = (int)(100 * (1 - (float)m_blankNumber / (float)m_totalBlank));
        progressBar_1->setValue(val);
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                m_writable[x][y] = m_writableLock[x][y];//Resume Array "writable"
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
    if (!calc->isSolvable(m_table)) {
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
            if (m_table[x][y] != 0) {
                pB = getPointFromPosition(x + 1, y + 1);
                setButtonNum(pB, m_table[x][y], 40);
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

void sudokuMain::readTableFile(int table[9][9]) {
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
            table[x][y] = Cr - '0';
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
                m_table[i][j] = m_solution[i][j];
                setButtonNum(getPointFromPosition(i + 1, j + 1), m_table[i][j], 40);
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
