#include <QtCore/qglobal.h>
#include <QtCore/QTextCodec>
#include <QString>
#include "ui_sudokuWidget.h"
#include "sudokuWidget.h"
#include "processDlg.h"
#include "conformDlg.h"

sudokuMain::sudokuMain(QWidget *parent)
    : QWidget(parent) {
    setupUi(this);
    m_iSetNum = 0;
    strTime = QString("00:00");
    m_iTimeSecond = 0;
    m_iTimeMinute = 0;
    m_last_click_button = 0;
    m_time_between_click = 0;
    main_Timer = new QTimer(this);
    click_Timer = new QTimer(this);
    rB_normal->setChecked(true);
    rB_single->setChecked(true);
    lineEdit_IP->setVisible(false);
    lineEdit_IP->setText(QString(tr("0.0.0.0")));
    progressBar_2->setVisible(false);
    label_ip->setVisible(false);
    label_p2->setVisible(false);
    m_processDlg = new processDlg(this);
    connect_Timer = new QTimer(this);
    label_p1->setText(QString(tr("^_^ :")));
    label_p2->setText(QString(tr("")));
    this->setMinimumSize(914, 618);
    this->setMaximumSize(914, 618);

    udpReceiver.bind(5824);//Bind With Specified Port

    m_cTheme = 'N';
    m_curTheme = QString(tr("数字"));
    cB_theme->addItem(QIcon(":/png/N1.png"), QString(tr("数字")));
    cB_theme->addItem(QIcon(":/png/S1.png"), QString(tr("太阳系")));
    cB_theme->addItem(QIcon(":/png/F1.png"), QString(tr("表情")));
    cB_theme->addItem(QIcon(":/png/E1.png"), QString(tr("元素")));
    cB_theme->setCurrentIndex(0);
    m_cBackground = 0;
    m_curBackground = QString(tr("没有背景"));
    cB_background->addItem(QIcon(":/png/M.png"), QString(tr("木质格调")));
    cB_background->addItem(QIcon(":/png/X.png"), QString(tr("夏日风情")));
    cB_background->addItem(QIcon(":/png/G.png"), QString(tr("绿意盎然")));
    cB_background->addItem(QIcon(":/png/R.png"), QString(tr("红旗永驻")));
    cB_background->setCurrentIndex(0);
    this->setAutoFillBackground(true);
    changeBackground(QString(tr("木质格调")));

    progressBar_1->setRange(0, 100);
    progressBar_1->setValue(0);
    progressBar_2->setRange(0, 100);
    progressBar_2->setValue(0);
    pB_win->setFlat(true);
    m_totalBlank = 9*9;
    m_blankNumber = m_totalBlank;
    m_beginPorgressBar = false;
    m_bLocked = false;
    m_bFinished = false;

    pB_setTable->setHidden(false);
    pB_fileSet->setHidden(false);
    pB_autoSet->setHidden(false);
    pB_start->setHidden(true);
    pB_resetTable->setHidden(true);
    pB_giveUp->setHidden(true);

    m_iTimeSecond = 0;
    m_iTimeMinute = 0;
    strTime = QString("00:00");
    lcdNumber->display(QString(strTime));

    int L, R, V;
    for (L=0; L<9; L++) {
        for (R=0; R<9; R++) {
            for (V=0; V<10; V++) {
                table[L][R][V] = 0;
            }
            writable[L][R] = 1;
            setted[L][R] = 0;
        }
    }

    setButtonNum(pB1, 1, 30);
    setButtonNum(pB2, 2, 30);
    setButtonNum(pB3, 3, 30);
    setButtonNum(pB4, 4, 30);
    setButtonNum(pB5, 5, 30);
    setButtonNum(pB6, 6, 30);
    setButtonNum(pB7, 7, 30);
    setButtonNum(pB8, 8, 30);
    setButtonNum(pB9, 9, 30);

    connect(click_Timer, SIGNAL(timeout()), this, SLOT(clickTimerUp()));
    connect(main_Timer, SIGNAL(timeout()), this, SLOT(mainTimerUp()));
    connect(connect_Timer, SIGNAL(timeout()), this, SLOT(connectTimerUp()));
    connect(&udpReceiver, SIGNAL(readyRead()), this,
            SLOT(processPendingDatagrams()));

    connect(pB_start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(pB_setTable, SIGNAL(clicked()), this, SLOT(setTable()));
    connect(pB_fileSet, SIGNAL(clicked()), this, SLOT(fileSet()));
    connect(pB_autoSet, SIGNAL(clicked()), this, SLOT(autoSet()));
    connect(pB_resetTable, SIGNAL(clicked()), this, SLOT(resetTable()));
    connect(pB_giveUp, SIGNAL(clicked()), this, SLOT(giveUp()));
    connect(cB_theme, SIGNAL(currentIndexChanged(const QString &)), this,
            SLOT(changeTheme(const QString &)));
    connect(cB_background, SIGNAL(currentIndexChanged(const QString &)), this,
            SLOT(changeBackground(const QString &)));
    connect(rB_single, SIGNAL(clicked()), this, SLOT(enableIP()));
    connect(rB_online, SIGNAL(clicked()), this, SLOT(enableIP()));
    connect(pB_help, SIGNAL(clicked()), this, SLOT(expanatry()));
    connect(pB_win, SIGNAL(clicked()), this, SLOT(win()));

    QPushButton* sideBtns[9] = { pB1, pB2, pB3, pB4, pB5, pB6, pB7, pB8, pB9 };
    QPushButton* btnMap[9][9] = {{ pB11, pB12, pB13, pB14, pB15, pB16, pB17, pB18, pB19 },
                                 { pB21, pB22, pB23, pB24, pB25, pB26, pB27, pB28, pB29 },
                                 { pB31, pB32, pB33, pB34, pB35, pB36, pB37, pB38, pB39 },
                                 { pB41, pB42, pB43, pB44, pB45, pB46, pB47, pB48, pB49 },
                                 { pB51, pB52, pB53, pB54, pB55, pB56, pB57, pB58, pB59 },
                                 { pB61, pB62, pB63, pB64, pB65, pB66, pB67, pB68, pB69 },
                                 { pB71, pB72, pB73, pB74, pB75, pB76, pB77, pB78, pB79 },
                                 { pB81, pB82, pB83, pB84, pB85, pB86, pB87, pB88, pB89 },
                                 { pB91, pB92, pB93, pB94, pB95, pB96, pB97, pB98, pB99 }};

    for (int i = 0; i < 9; i++) {
        connect(sideBtns[i], &QPushButton::clicked, [=]() {
            sideButtonDown(sideBtns[i], i + 1);
        });
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            connect(btnMap[i][j], &QPushButton::clicked, [=]() {
                pushButtonDown(btnMap[i][j], i + 1, j + 1);
            });
        }
    }

}

sudokuMain::~sudokuMain() {
    delete main_Timer;
    delete click_Timer;
    delete connect_Timer;
    delete m_processDlg;
}

