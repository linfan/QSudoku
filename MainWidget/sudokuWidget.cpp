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

    connect(pB11, SIGNAL(clicked()), this, SLOT(pBk11()));
    connect(pB12, SIGNAL(clicked()), this, SLOT(pBk12()));
    connect(pB13, SIGNAL(clicked()), this, SLOT(pBk13()));
    connect(pB14, SIGNAL(clicked()), this, SLOT(pBk14()));
    connect(pB15, SIGNAL(clicked()), this, SLOT(pBk15()));
    connect(pB16, SIGNAL(clicked()), this, SLOT(pBk16()));
    connect(pB17, SIGNAL(clicked()), this, SLOT(pBk17()));
    connect(pB18, SIGNAL(clicked()), this, SLOT(pBk18()));
    connect(pB19, SIGNAL(clicked()), this, SLOT(pBk19()));

    connect(pB21, SIGNAL(clicked()), this, SLOT(pBk21()));
    connect(pB22, SIGNAL(clicked()), this, SLOT(pBk22()));
    connect(pB23, SIGNAL(clicked()), this, SLOT(pBk23()));
    connect(pB24, SIGNAL(clicked()), this, SLOT(pBk24()));
    connect(pB25, SIGNAL(clicked()), this, SLOT(pBk25()));
    connect(pB26, SIGNAL(clicked()), this, SLOT(pBk26()));
    connect(pB27, SIGNAL(clicked()), this, SLOT(pBk27()));
    connect(pB28, SIGNAL(clicked()), this, SLOT(pBk28()));
    connect(pB29, SIGNAL(clicked()), this, SLOT(pBk29()));

    connect(pB31, SIGNAL(clicked()), this, SLOT(pBk31()));
    connect(pB32, SIGNAL(clicked()), this, SLOT(pBk32()));
    connect(pB33, SIGNAL(clicked()), this, SLOT(pBk33()));
    connect(pB34, SIGNAL(clicked()), this, SLOT(pBk34()));
    connect(pB35, SIGNAL(clicked()), this, SLOT(pBk35()));
    connect(pB36, SIGNAL(clicked()), this, SLOT(pBk36()));
    connect(pB37, SIGNAL(clicked()), this, SLOT(pBk37()));
    connect(pB38, SIGNAL(clicked()), this, SLOT(pBk38()));
    connect(pB39, SIGNAL(clicked()), this, SLOT(pBk39()));

    connect(pB41, SIGNAL(clicked()), this, SLOT(pBk41()));
    connect(pB42, SIGNAL(clicked()), this, SLOT(pBk42()));
    connect(pB43, SIGNAL(clicked()), this, SLOT(pBk43()));
    connect(pB44, SIGNAL(clicked()), this, SLOT(pBk44()));
    connect(pB45, SIGNAL(clicked()), this, SLOT(pBk45()));
    connect(pB46, SIGNAL(clicked()), this, SLOT(pBk46()));
    connect(pB47, SIGNAL(clicked()), this, SLOT(pBk47()));
    connect(pB48, SIGNAL(clicked()), this, SLOT(pBk48()));
    connect(pB49, SIGNAL(clicked()), this, SLOT(pBk49()));

    connect(pB51, SIGNAL(clicked()), this, SLOT(pBk51()));
    connect(pB52, SIGNAL(clicked()), this, SLOT(pBk52()));
    connect(pB53, SIGNAL(clicked()), this, SLOT(pBk53()));
    connect(pB54, SIGNAL(clicked()), this, SLOT(pBk54()));
    connect(pB55, SIGNAL(clicked()), this, SLOT(pBk55()));
    connect(pB56, SIGNAL(clicked()), this, SLOT(pBk56()));
    connect(pB57, SIGNAL(clicked()), this, SLOT(pBk57()));
    connect(pB58, SIGNAL(clicked()), this, SLOT(pBk58()));
    connect(pB59, SIGNAL(clicked()), this, SLOT(pBk59()));

    connect(pB61, SIGNAL(clicked()), this, SLOT(pBk61()));
    connect(pB62, SIGNAL(clicked()), this, SLOT(pBk62()));
    connect(pB63, SIGNAL(clicked()), this, SLOT(pBk63()));
    connect(pB64, SIGNAL(clicked()), this, SLOT(pBk64()));
    connect(pB65, SIGNAL(clicked()), this, SLOT(pBk65()));
    connect(pB66, SIGNAL(clicked()), this, SLOT(pBk66()));
    connect(pB67, SIGNAL(clicked()), this, SLOT(pBk67()));
    connect(pB68, SIGNAL(clicked()), this, SLOT(pBk68()));
    connect(pB69, SIGNAL(clicked()), this, SLOT(pBk69()));

    connect(pB71, SIGNAL(clicked()), this, SLOT(pBk71()));
    connect(pB72, SIGNAL(clicked()), this, SLOT(pBk72()));
    connect(pB73, SIGNAL(clicked()), this, SLOT(pBk73()));
    connect(pB74, SIGNAL(clicked()), this, SLOT(pBk74()));
    connect(pB75, SIGNAL(clicked()), this, SLOT(pBk75()));
    connect(pB76, SIGNAL(clicked()), this, SLOT(pBk76()));
    connect(pB77, SIGNAL(clicked()), this, SLOT(pBk77()));
    connect(pB78, SIGNAL(clicked()), this, SLOT(pBk78()));
    connect(pB79, SIGNAL(clicked()), this, SLOT(pBk79()));

    connect(pB81, SIGNAL(clicked()), this, SLOT(pBk81()));
    connect(pB82, SIGNAL(clicked()), this, SLOT(pBk82()));
    connect(pB83, SIGNAL(clicked()), this, SLOT(pBk83()));
    connect(pB84, SIGNAL(clicked()), this, SLOT(pBk84()));
    connect(pB85, SIGNAL(clicked()), this, SLOT(pBk85()));
    connect(pB86, SIGNAL(clicked()), this, SLOT(pBk86()));
    connect(pB87, SIGNAL(clicked()), this, SLOT(pBk87()));
    connect(pB88, SIGNAL(clicked()), this, SLOT(pBk88()));
    connect(pB89, SIGNAL(clicked()), this, SLOT(pBk89()));

    connect(pB91, SIGNAL(clicked()), this, SLOT(pBk91()));
    connect(pB92, SIGNAL(clicked()), this, SLOT(pBk92()));
    connect(pB93, SIGNAL(clicked()), this, SLOT(pBk93()));
    connect(pB94, SIGNAL(clicked()), this, SLOT(pBk94()));
    connect(pB95, SIGNAL(clicked()), this, SLOT(pBk95()));
    connect(pB96, SIGNAL(clicked()), this, SLOT(pBk96()));
    connect(pB97, SIGNAL(clicked()), this, SLOT(pBk97()));
    connect(pB98, SIGNAL(clicked()), this, SLOT(pBk98()));
    connect(pB99, SIGNAL(clicked()), this, SLOT(pBk99()));

    connect(pB1, SIGNAL(clicked()), this, SLOT(pBk1()));
    connect(pB2, SIGNAL(clicked()), this, SLOT(pBk2()));
    connect(pB3, SIGNAL(clicked()), this, SLOT(pBk3()));
    connect(pB4, SIGNAL(clicked()), this, SLOT(pBk4()));
    connect(pB5, SIGNAL(clicked()), this, SLOT(pBk5()));
    connect(pB6, SIGNAL(clicked()), this, SLOT(pBk6()));
    connect(pB7, SIGNAL(clicked()), this, SLOT(pBk7()));
    connect(pB8, SIGNAL(clicked()), this, SLOT(pBk8()));
    connect(pB9, SIGNAL(clicked()), this, SLOT(pBk9()));
}

sudokuMain::~sudokuMain() {
    delete main_Timer;
    delete click_Timer;
    delete connect_Timer;
    delete m_processDlg;
}

