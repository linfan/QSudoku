#ifndef _SUDOKUMAIN_H_
#define _SUDOKUMAIN_H_

#include <QtWidgets/QWidget>
#include <QUdpSocket>
#include <QTimer>
#include <array>
#include "ui_sudokuWidget.h"

#define MES_REQUEST 200
#define MES_CONFIRM 300
#define MES_FINISH  400
#define MES_GIVEUP  500
#define MES_WIN     600
#define MES_REJECT  700

using SudokuMatrix = std::array<std::array<QPushButton*, 9>, 9>;

class processDlg;

class sudokuMain : public QWidget, public Ui_MainForm {
    Q_OBJECT

public:
    sudokuMain(QWidget *parent = 0);
    ~sudokuMain();

private:
    int m_iSetNum;           // The Number To Put Into The Table
    QTimer *main_Timer;      // Timer Clock
    QTimer *click_Timer;     // Calculate The Time Between Double Click,Is This A Little Too Luxury^^~
    int m_time_between_click;// Recode The Time Between Double Click
    int m_last_click_button; // The Last Button Clicked By Player
    QString strTime;         // Timer String To Display
    int m_iTimeSecond;       // The Second Part Of Timer
    int m_iTimeMinute;       // The Minute Part Of Timer
    int table[9][9][10];     // The Question Table
    int tableBackup[9][9];   // The "table"'s Copy For Restore, Because "GetSolution" May Alter The "table"
    int setted[9][9];        // Recode The Grids On Table Those Have Been Setted With A Value
    int solution[9][9];      // The Solution Calculated By Computer
    char m_cTheme;           // The Code Of Theme Selected By Player
    QString m_curTheme;      // The Name Of Current Theme
    char m_cBackground;      // The Code Of Background Selected By Player
    QString m_curBackground; // The Name Of Current Background
    int writable[9][9];      // Mark The Writable Positions On Table
    int writableLock[9][9];  // Backup The State Of Array "writable" When Protecting "table" From Being Altered
    int m_bLocked;           // Whether The Table Has Been Locked
    int m_blankNumber;       // The Currenttly Number Of Blank Grid In Table
    int m_process;           // The Currenttly Process Of The Game
    int m_rivalProcess;      // The Process Of The Rival On Online Game
    int m_totalBlank;        // Number Of Blank Grid In Table When Game Beginning
    int m_beginPorgressBar;  // Whether The ProgressBar Work, Set After "main_Timer.start()" Called
    QUdpSocket udpReceiver;  // The UDP Object For Receive Messages
    QUdpSocket udpSender;    // The UDP Object For Send Messages
    processDlg *m_processDlg;// When Connectint, Show It
    QTimer *connect_Timer;   // To Calculate Time When Connecting
    bool m_bFinished;        // If Player Full The Table Successfully, It Will Be Set

    int pushButtonDown(QPushButton *pB, int L, int R);
    void sideButtonDown(QPushButton *pB, int num);
    void clearButton(QPushButton *pB, int L, int R);
    QPushButton* getPointFromPosition(int L, int R);
    QPushButton* getPointFromNumber(int num);
    void setButtonNum(QPushButton *pB, int Num, int size);
    void sendDatagram(int message);
    void showTable();
    bool matrixEqual(int table[9][9][10], int solution[9][9]);
    bool checkGameAlreadyBegin();
    SudokuMatrix getButtonMatrix();
    int GetSolution(int table[9][9][10], int solution[9][9]);

private slots:
    void mainTimerUp();
    void connectTimerUp();
    void clickTimerUp();
    void startGame();
    void setTable();
    void fileSet();
    void resetTable();
    void autoSet();
    void giveUp();
    void changeTheme(const QString & text);
    void changeBackground(const QString & text);
    void enableIP();
    void expanatry();
    void processPendingDatagrams();
    void win();
};

#endif // _SUDOKUMAIN_H_
