/********************************************************************************
** Form generated from reading ui file 'sudokuWidget.ui'
**
** Created: Thu Nov 19 19:14:45 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SUDOKUWIDGET_H
#define UI_SUDOKUWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_12;
    QPushButton *pB14;
    QPushButton *pB15;
    QPushButton *pB16;
    QPushButton *pB24;
    QPushButton *pB25;
    QPushButton *pB26;
    QPushButton *pB34;
    QPushButton *pB35;
    QPushButton *pB36;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_13;
    QPushButton *pB17;
    QPushButton *pB18;
    QPushButton *pB19;
    QPushButton *pB27;
    QPushButton *pB28;
    QPushButton *pB29;
    QPushButton *pB37;
    QPushButton *pB38;
    QPushButton *pB39;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_21;
    QPushButton *pB41;
    QPushButton *pB42;
    QPushButton *pB43;
    QPushButton *pB51;
    QPushButton *pB53;
    QPushButton *pB61;
    QPushButton *pB62;
    QPushButton *pB63;
    QPushButton *pB52;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_22;
    QPushButton *pB44;
    QPushButton *pB45;
    QPushButton *pB46;
    QPushButton *pB54;
    QPushButton *pB55;
    QPushButton *pB56;
    QPushButton *pB64;
    QPushButton *pB65;
    QPushButton *pB66;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_23;
    QPushButton *pB47;
    QPushButton *pB48;
    QPushButton *pB49;
    QPushButton *pB57;
    QPushButton *pB58;
    QPushButton *pB59;
    QPushButton *pB67;
    QPushButton *pB68;
    QPushButton *pB69;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout_11;
    QPushButton *pB11;
    QPushButton *pB12;
    QPushButton *pB13;
    QPushButton *pB21;
    QPushButton *pB22;
    QPushButton *pB23;
    QPushButton *pB31;
    QPushButton *pB32;
    QPushButton *pB33;
    QWidget *layoutWidget_7;
    QGridLayout *gridLayout_31;
    QPushButton *pB71;
    QPushButton *pB72;
    QPushButton *pB73;
    QPushButton *pB81;
    QPushButton *pB82;
    QPushButton *pB83;
    QPushButton *pB91;
    QPushButton *pB92;
    QPushButton *pB93;
    QWidget *layoutWidget_8;
    QGridLayout *gridLayout_32;
    QPushButton *pB74;
    QPushButton *pB75;
    QPushButton *pB76;
    QPushButton *pB84;
    QPushButton *pB85;
    QPushButton *pB86;
    QPushButton *pB94;
    QPushButton *pB95;
    QPushButton *pB96;
    QWidget *layoutWidget_9;
    QGridLayout *gridLayout_33;
    QPushButton *pB77;
    QPushButton *pB78;
    QPushButton *pB79;
    QPushButton *pB87;
    QPushButton *pB88;
    QPushButton *pB89;
    QPushButton *pB97;
    QPushButton *pB98;
    QPushButton *pB99;
    QLCDNumber *lcdNumber;
    QWidget *layoutWidget_10;
    QGridLayout *gridLayout_0;
    QPushButton *pB1;
    QPushButton *pB2;
    QPushButton *pB3;
    QPushButton *pB4;
    QPushButton *pB5;
    QPushButton *pB6;
    QPushButton *pB7;
    QPushButton *pB8;
    QPushButton *pB9;
    QPushButton *pB_autoSet;
    QPushButton *pB_start;
    QGroupBox *groupBox_1;
    QRadioButton *rB_single;
    QRadioButton *rB_online;
    QLabel *label_ip;
    QGroupBox *groupBox_2;
    QRadioButton *rB_hard;
    QRadioButton *rB_normal;
    QRadioButton *rB_easy;
    QLineEdit *lineEdit_IP;
    QPushButton *pB_fileSet;
    QPushButton *pB_setTable;
    QComboBox *cB_theme;
    QLabel *label;
    QPushButton *pB_resetTable;
    QPushButton *pB_giveUp;
    QComboBox *cB_background;
    QLabel *label_2;
    QPushButton *pB_win;
    QGroupBox *groupBox_3;
    QProgressBar *progressBar_1;
    QProgressBar *progressBar_2;
    QLabel *label_p1;
    QLabel *label_p2;
    QPushButton *pB_help;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(914, 618);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/sudoku.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainForm->setWindowIcon(icon);
        MainForm->setAutoFillBackground(false);
        layoutWidget = new QWidget(MainForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 30, 202, 181));
        gridLayout_12 = new QGridLayout(layoutWidget);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        pB14 = new QPushButton(layoutWidget);
        pB14->setObjectName(QString::fromUtf8("pB14"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pB14->sizePolicy().hasHeightForWidth());
        pB14->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(pB14, 0, 0, 1, 1);

        pB15 = new QPushButton(layoutWidget);
        pB15->setObjectName(QString::fromUtf8("pB15"));
        sizePolicy.setHeightForWidth(pB15->sizePolicy().hasHeightForWidth());
        pB15->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(pB15, 0, 1, 1, 1);

        pB16 = new QPushButton(layoutWidget);
        pB16->setObjectName(QString::fromUtf8("pB16"));
        sizePolicy.setHeightForWidth(pB16->sizePolicy().hasHeightForWidth());
        pB16->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(pB16, 0, 2, 1, 1);

        pB24 = new QPushButton(layoutWidget);
        pB24->setObjectName(QString::fromUtf8("pB24"));
        sizePolicy.setHeightForWidth(pB24->sizePolicy().hasHeightForWidth());
        pB24->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(pB24, 1, 0, 1, 1);

        pB25 = new QPushButton(layoutWidget);
        pB25->setObjectName(QString::fromUtf8("pB25"));
        sizePolicy.setHeightForWidth(pB25->sizePolicy().hasHeightForWidth());
        pB25->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(pB25, 1, 1, 1, 1);

        pB26 = new QPushButton(layoutWidget);
        pB26->setObjectName(QString::fromUtf8("pB26"));
        sizePolicy.setHeightForWidth(pB26->sizePolicy().hasHeightForWidth());
        pB26->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(pB26, 1, 2, 1, 1);

        pB34 = new QPushButton(layoutWidget);
        pB34->setObjectName(QString::fromUtf8("pB34"));
        sizePolicy.setHeightForWidth(pB34->sizePolicy().hasHeightForWidth());
        pB34->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(pB34, 2, 0, 1, 1);

        pB35 = new QPushButton(layoutWidget);
        pB35->setObjectName(QString::fromUtf8("pB35"));
        sizePolicy.setHeightForWidth(pB35->sizePolicy().hasHeightForWidth());
        pB35->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(pB35, 2, 1, 1, 1);

        pB36 = new QPushButton(layoutWidget);
        pB36->setObjectName(QString::fromUtf8("pB36"));
        sizePolicy.setHeightForWidth(pB36->sizePolicy().hasHeightForWidth());
        pB36->setSizePolicy(sizePolicy);

        gridLayout_12->addWidget(pB36, 2, 2, 1, 1);

        layoutWidget_2 = new QWidget(MainForm);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(450, 30, 202, 181));
        gridLayout_13 = new QGridLayout(layoutWidget_2);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        pB17 = new QPushButton(layoutWidget_2);
        pB17->setObjectName(QString::fromUtf8("pB17"));
        sizePolicy.setHeightForWidth(pB17->sizePolicy().hasHeightForWidth());
        pB17->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(pB17, 0, 0, 1, 1);

        pB18 = new QPushButton(layoutWidget_2);
        pB18->setObjectName(QString::fromUtf8("pB18"));
        sizePolicy.setHeightForWidth(pB18->sizePolicy().hasHeightForWidth());
        pB18->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(pB18, 0, 1, 1, 1);

        pB19 = new QPushButton(layoutWidget_2);
        pB19->setObjectName(QString::fromUtf8("pB19"));
        sizePolicy.setHeightForWidth(pB19->sizePolicy().hasHeightForWidth());
        pB19->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(pB19, 0, 2, 1, 1);

        pB27 = new QPushButton(layoutWidget_2);
        pB27->setObjectName(QString::fromUtf8("pB27"));
        sizePolicy.setHeightForWidth(pB27->sizePolicy().hasHeightForWidth());
        pB27->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(pB27, 1, 0, 1, 1);

        pB28 = new QPushButton(layoutWidget_2);
        pB28->setObjectName(QString::fromUtf8("pB28"));
        sizePolicy.setHeightForWidth(pB28->sizePolicy().hasHeightForWidth());
        pB28->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(pB28, 1, 1, 1, 1);

        pB29 = new QPushButton(layoutWidget_2);
        pB29->setObjectName(QString::fromUtf8("pB29"));
        sizePolicy.setHeightForWidth(pB29->sizePolicy().hasHeightForWidth());
        pB29->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(pB29, 1, 2, 1, 1);

        pB37 = new QPushButton(layoutWidget_2);
        pB37->setObjectName(QString::fromUtf8("pB37"));
        sizePolicy.setHeightForWidth(pB37->sizePolicy().hasHeightForWidth());
        pB37->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(pB37, 2, 0, 1, 1);

        pB38 = new QPushButton(layoutWidget_2);
        pB38->setObjectName(QString::fromUtf8("pB38"));
        sizePolicy.setHeightForWidth(pB38->sizePolicy().hasHeightForWidth());
        pB38->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(pB38, 2, 1, 1, 1);

        pB39 = new QPushButton(layoutWidget_2);
        pB39->setObjectName(QString::fromUtf8("pB39"));
        sizePolicy.setHeightForWidth(pB39->sizePolicy().hasHeightForWidth());
        pB39->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(pB39, 2, 2, 1, 1);

        layoutWidget_3 = new QWidget(MainForm);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 220, 202, 181));
        gridLayout_21 = new QGridLayout(layoutWidget_3);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        pB41 = new QPushButton(layoutWidget_3);
        pB41->setObjectName(QString::fromUtf8("pB41"));
        sizePolicy.setHeightForWidth(pB41->sizePolicy().hasHeightForWidth());
        pB41->setSizePolicy(sizePolicy);

        gridLayout_21->addWidget(pB41, 0, 0, 1, 1);

        pB42 = new QPushButton(layoutWidget_3);
        pB42->setObjectName(QString::fromUtf8("pB42"));
        sizePolicy.setHeightForWidth(pB42->sizePolicy().hasHeightForWidth());
        pB42->setSizePolicy(sizePolicy);

        gridLayout_21->addWidget(pB42, 0, 1, 1, 1);

        pB43 = new QPushButton(layoutWidget_3);
        pB43->setObjectName(QString::fromUtf8("pB43"));
        sizePolicy.setHeightForWidth(pB43->sizePolicy().hasHeightForWidth());
        pB43->setSizePolicy(sizePolicy);

        gridLayout_21->addWidget(pB43, 0, 2, 1, 1);

        pB51 = new QPushButton(layoutWidget_3);
        pB51->setObjectName(QString::fromUtf8("pB51"));
        sizePolicy.setHeightForWidth(pB51->sizePolicy().hasHeightForWidth());
        pB51->setSizePolicy(sizePolicy);

        gridLayout_21->addWidget(pB51, 1, 0, 1, 1);

        pB53 = new QPushButton(layoutWidget_3);
        pB53->setObjectName(QString::fromUtf8("pB53"));
        sizePolicy.setHeightForWidth(pB53->sizePolicy().hasHeightForWidth());
        pB53->setSizePolicy(sizePolicy);

        gridLayout_21->addWidget(pB53, 1, 2, 1, 1);

        pB61 = new QPushButton(layoutWidget_3);
        pB61->setObjectName(QString::fromUtf8("pB61"));
        sizePolicy.setHeightForWidth(pB61->sizePolicy().hasHeightForWidth());
        pB61->setSizePolicy(sizePolicy);

        gridLayout_21->addWidget(pB61, 2, 0, 1, 1);

        pB62 = new QPushButton(layoutWidget_3);
        pB62->setObjectName(QString::fromUtf8("pB62"));
        sizePolicy.setHeightForWidth(pB62->sizePolicy().hasHeightForWidth());
        pB62->setSizePolicy(sizePolicy);

        gridLayout_21->addWidget(pB62, 2, 1, 1, 1);

        pB63 = new QPushButton(layoutWidget_3);
        pB63->setObjectName(QString::fromUtf8("pB63"));
        sizePolicy.setHeightForWidth(pB63->sizePolicy().hasHeightForWidth());
        pB63->setSizePolicy(sizePolicy);

        gridLayout_21->addWidget(pB63, 2, 2, 1, 1);

        pB52 = new QPushButton(layoutWidget_3);
        pB52->setObjectName(QString::fromUtf8("pB52"));
        sizePolicy.setHeightForWidth(pB52->sizePolicy().hasHeightForWidth());
        pB52->setSizePolicy(sizePolicy);

        gridLayout_21->addWidget(pB52, 1, 1, 1, 1);

        layoutWidget_4 = new QWidget(MainForm);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(240, 220, 202, 181));
        gridLayout_22 = new QGridLayout(layoutWidget_4);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        pB44 = new QPushButton(layoutWidget_4);
        pB44->setObjectName(QString::fromUtf8("pB44"));
        sizePolicy.setHeightForWidth(pB44->sizePolicy().hasHeightForWidth());
        pB44->setSizePolicy(sizePolicy);

        gridLayout_22->addWidget(pB44, 0, 0, 1, 1);

        pB45 = new QPushButton(layoutWidget_4);
        pB45->setObjectName(QString::fromUtf8("pB45"));
        sizePolicy.setHeightForWidth(pB45->sizePolicy().hasHeightForWidth());
        pB45->setSizePolicy(sizePolicy);

        gridLayout_22->addWidget(pB45, 0, 1, 1, 1);

        pB46 = new QPushButton(layoutWidget_4);
        pB46->setObjectName(QString::fromUtf8("pB46"));
        sizePolicy.setHeightForWidth(pB46->sizePolicy().hasHeightForWidth());
        pB46->setSizePolicy(sizePolicy);

        gridLayout_22->addWidget(pB46, 0, 2, 1, 1);

        pB54 = new QPushButton(layoutWidget_4);
        pB54->setObjectName(QString::fromUtf8("pB54"));
        sizePolicy.setHeightForWidth(pB54->sizePolicy().hasHeightForWidth());
        pB54->setSizePolicy(sizePolicy);

        gridLayout_22->addWidget(pB54, 1, 0, 1, 1);

        pB55 = new QPushButton(layoutWidget_4);
        pB55->setObjectName(QString::fromUtf8("pB55"));
        sizePolicy.setHeightForWidth(pB55->sizePolicy().hasHeightForWidth());
        pB55->setSizePolicy(sizePolicy);

        gridLayout_22->addWidget(pB55, 1, 1, 1, 1);

        pB56 = new QPushButton(layoutWidget_4);
        pB56->setObjectName(QString::fromUtf8("pB56"));
        sizePolicy.setHeightForWidth(pB56->sizePolicy().hasHeightForWidth());
        pB56->setSizePolicy(sizePolicy);

        gridLayout_22->addWidget(pB56, 1, 2, 1, 1);

        pB64 = new QPushButton(layoutWidget_4);
        pB64->setObjectName(QString::fromUtf8("pB64"));
        sizePolicy.setHeightForWidth(pB64->sizePolicy().hasHeightForWidth());
        pB64->setSizePolicy(sizePolicy);

        gridLayout_22->addWidget(pB64, 2, 0, 1, 1);

        pB65 = new QPushButton(layoutWidget_4);
        pB65->setObjectName(QString::fromUtf8("pB65"));
        sizePolicy.setHeightForWidth(pB65->sizePolicy().hasHeightForWidth());
        pB65->setSizePolicy(sizePolicy);

        gridLayout_22->addWidget(pB65, 2, 1, 1, 1);

        pB66 = new QPushButton(layoutWidget_4);
        pB66->setObjectName(QString::fromUtf8("pB66"));
        sizePolicy.setHeightForWidth(pB66->sizePolicy().hasHeightForWidth());
        pB66->setSizePolicy(sizePolicy);

        gridLayout_22->addWidget(pB66, 2, 2, 1, 1);

        layoutWidget_5 = new QWidget(MainForm);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(450, 220, 202, 181));
        gridLayout_23 = new QGridLayout(layoutWidget_5);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setContentsMargins(0, 0, 0, 0);
        pB47 = new QPushButton(layoutWidget_5);
        pB47->setObjectName(QString::fromUtf8("pB47"));
        sizePolicy.setHeightForWidth(pB47->sizePolicy().hasHeightForWidth());
        pB47->setSizePolicy(sizePolicy);

        gridLayout_23->addWidget(pB47, 0, 0, 1, 1);

        pB48 = new QPushButton(layoutWidget_5);
        pB48->setObjectName(QString::fromUtf8("pB48"));
        sizePolicy.setHeightForWidth(pB48->sizePolicy().hasHeightForWidth());
        pB48->setSizePolicy(sizePolicy);

        gridLayout_23->addWidget(pB48, 0, 1, 1, 1);

        pB49 = new QPushButton(layoutWidget_5);
        pB49->setObjectName(QString::fromUtf8("pB49"));
        sizePolicy.setHeightForWidth(pB49->sizePolicy().hasHeightForWidth());
        pB49->setSizePolicy(sizePolicy);

        gridLayout_23->addWidget(pB49, 0, 2, 1, 1);

        pB57 = new QPushButton(layoutWidget_5);
        pB57->setObjectName(QString::fromUtf8("pB57"));
        sizePolicy.setHeightForWidth(pB57->sizePolicy().hasHeightForWidth());
        pB57->setSizePolicy(sizePolicy);

        gridLayout_23->addWidget(pB57, 1, 0, 1, 1);

        pB58 = new QPushButton(layoutWidget_5);
        pB58->setObjectName(QString::fromUtf8("pB58"));
        sizePolicy.setHeightForWidth(pB58->sizePolicy().hasHeightForWidth());
        pB58->setSizePolicy(sizePolicy);

        gridLayout_23->addWidget(pB58, 1, 1, 1, 1);

        pB59 = new QPushButton(layoutWidget_5);
        pB59->setObjectName(QString::fromUtf8("pB59"));
        sizePolicy.setHeightForWidth(pB59->sizePolicy().hasHeightForWidth());
        pB59->setSizePolicy(sizePolicy);

        gridLayout_23->addWidget(pB59, 1, 2, 1, 1);

        pB67 = new QPushButton(layoutWidget_5);
        pB67->setObjectName(QString::fromUtf8("pB67"));
        sizePolicy.setHeightForWidth(pB67->sizePolicy().hasHeightForWidth());
        pB67->setSizePolicy(sizePolicy);

        gridLayout_23->addWidget(pB67, 2, 0, 1, 1);

        pB68 = new QPushButton(layoutWidget_5);
        pB68->setObjectName(QString::fromUtf8("pB68"));
        sizePolicy.setHeightForWidth(pB68->sizePolicy().hasHeightForWidth());
        pB68->setSizePolicy(sizePolicy);

        gridLayout_23->addWidget(pB68, 2, 1, 1, 1);

        pB69 = new QPushButton(layoutWidget_5);
        pB69->setObjectName(QString::fromUtf8("pB69"));
        sizePolicy.setHeightForWidth(pB69->sizePolicy().hasHeightForWidth());
        pB69->setSizePolicy(sizePolicy);

        gridLayout_23->addWidget(pB69, 2, 2, 1, 1);

        layoutWidget_6 = new QWidget(MainForm);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(30, 30, 202, 181));
        gridLayout_11 = new QGridLayout(layoutWidget_6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        pB11 = new QPushButton(layoutWidget_6);
        pB11->setObjectName(QString::fromUtf8("pB11"));
        sizePolicy.setHeightForWidth(pB11->sizePolicy().hasHeightForWidth());
        pB11->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pB11, 0, 0, 1, 1);

        pB12 = new QPushButton(layoutWidget_6);
        pB12->setObjectName(QString::fromUtf8("pB12"));
        sizePolicy.setHeightForWidth(pB12->sizePolicy().hasHeightForWidth());
        pB12->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pB12, 0, 1, 1, 1);

        pB13 = new QPushButton(layoutWidget_6);
        pB13->setObjectName(QString::fromUtf8("pB13"));
        sizePolicy.setHeightForWidth(pB13->sizePolicy().hasHeightForWidth());
        pB13->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pB13, 0, 2, 1, 1);

        pB21 = new QPushButton(layoutWidget_6);
        pB21->setObjectName(QString::fromUtf8("pB21"));
        sizePolicy.setHeightForWidth(pB21->sizePolicy().hasHeightForWidth());
        pB21->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pB21, 1, 0, 1, 1);

        pB22 = new QPushButton(layoutWidget_6);
        pB22->setObjectName(QString::fromUtf8("pB22"));
        sizePolicy.setHeightForWidth(pB22->sizePolicy().hasHeightForWidth());
        pB22->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pB22, 1, 1, 1, 1);

        pB23 = new QPushButton(layoutWidget_6);
        pB23->setObjectName(QString::fromUtf8("pB23"));
        sizePolicy.setHeightForWidth(pB23->sizePolicy().hasHeightForWidth());
        pB23->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pB23, 1, 2, 1, 1);

        pB31 = new QPushButton(layoutWidget_6);
        pB31->setObjectName(QString::fromUtf8("pB31"));
        sizePolicy.setHeightForWidth(pB31->sizePolicy().hasHeightForWidth());
        pB31->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pB31, 2, 0, 1, 1);

        pB32 = new QPushButton(layoutWidget_6);
        pB32->setObjectName(QString::fromUtf8("pB32"));
        sizePolicy.setHeightForWidth(pB32->sizePolicy().hasHeightForWidth());
        pB32->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pB32, 2, 1, 1, 1);

        pB33 = new QPushButton(layoutWidget_6);
        pB33->setObjectName(QString::fromUtf8("pB33"));
        sizePolicy.setHeightForWidth(pB33->sizePolicy().hasHeightForWidth());
        pB33->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(pB33, 2, 2, 1, 1);

        layoutWidget_7 = new QWidget(MainForm);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(30, 410, 202, 181));
        gridLayout_31 = new QGridLayout(layoutWidget_7);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout_31->setContentsMargins(0, 0, 0, 0);
        pB71 = new QPushButton(layoutWidget_7);
        pB71->setObjectName(QString::fromUtf8("pB71"));
        sizePolicy.setHeightForWidth(pB71->sizePolicy().hasHeightForWidth());
        pB71->setSizePolicy(sizePolicy);

        gridLayout_31->addWidget(pB71, 0, 0, 1, 1);

        pB72 = new QPushButton(layoutWidget_7);
        pB72->setObjectName(QString::fromUtf8("pB72"));
        sizePolicy.setHeightForWidth(pB72->sizePolicy().hasHeightForWidth());
        pB72->setSizePolicy(sizePolicy);

        gridLayout_31->addWidget(pB72, 0, 1, 1, 1);

        pB73 = new QPushButton(layoutWidget_7);
        pB73->setObjectName(QString::fromUtf8("pB73"));
        sizePolicy.setHeightForWidth(pB73->sizePolicy().hasHeightForWidth());
        pB73->setSizePolicy(sizePolicy);

        gridLayout_31->addWidget(pB73, 0, 2, 1, 1);

        pB81 = new QPushButton(layoutWidget_7);
        pB81->setObjectName(QString::fromUtf8("pB81"));
        sizePolicy.setHeightForWidth(pB81->sizePolicy().hasHeightForWidth());
        pB81->setSizePolicy(sizePolicy);

        gridLayout_31->addWidget(pB81, 1, 0, 1, 1);

        pB82 = new QPushButton(layoutWidget_7);
        pB82->setObjectName(QString::fromUtf8("pB82"));
        sizePolicy.setHeightForWidth(pB82->sizePolicy().hasHeightForWidth());
        pB82->setSizePolicy(sizePolicy);

        gridLayout_31->addWidget(pB82, 1, 1, 1, 1);

        pB83 = new QPushButton(layoutWidget_7);
        pB83->setObjectName(QString::fromUtf8("pB83"));
        sizePolicy.setHeightForWidth(pB83->sizePolicy().hasHeightForWidth());
        pB83->setSizePolicy(sizePolicy);

        gridLayout_31->addWidget(pB83, 1, 2, 1, 1);

        pB91 = new QPushButton(layoutWidget_7);
        pB91->setObjectName(QString::fromUtf8("pB91"));
        sizePolicy.setHeightForWidth(pB91->sizePolicy().hasHeightForWidth());
        pB91->setSizePolicy(sizePolicy);

        gridLayout_31->addWidget(pB91, 2, 0, 1, 1);

        pB92 = new QPushButton(layoutWidget_7);
        pB92->setObjectName(QString::fromUtf8("pB92"));
        sizePolicy.setHeightForWidth(pB92->sizePolicy().hasHeightForWidth());
        pB92->setSizePolicy(sizePolicy);

        gridLayout_31->addWidget(pB92, 2, 1, 1, 1);

        pB93 = new QPushButton(layoutWidget_7);
        pB93->setObjectName(QString::fromUtf8("pB93"));
        sizePolicy.setHeightForWidth(pB93->sizePolicy().hasHeightForWidth());
        pB93->setSizePolicy(sizePolicy);

        gridLayout_31->addWidget(pB93, 2, 2, 1, 1);

        layoutWidget_8 = new QWidget(MainForm);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(240, 410, 202, 181));
        gridLayout_32 = new QGridLayout(layoutWidget_8);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        gridLayout_32->setContentsMargins(0, 0, 0, 0);
        pB74 = new QPushButton(layoutWidget_8);
        pB74->setObjectName(QString::fromUtf8("pB74"));
        sizePolicy.setHeightForWidth(pB74->sizePolicy().hasHeightForWidth());
        pB74->setSizePolicy(sizePolicy);

        gridLayout_32->addWidget(pB74, 0, 0, 1, 1);

        pB75 = new QPushButton(layoutWidget_8);
        pB75->setObjectName(QString::fromUtf8("pB75"));
        sizePolicy.setHeightForWidth(pB75->sizePolicy().hasHeightForWidth());
        pB75->setSizePolicy(sizePolicy);

        gridLayout_32->addWidget(pB75, 0, 1, 1, 1);

        pB76 = new QPushButton(layoutWidget_8);
        pB76->setObjectName(QString::fromUtf8("pB76"));
        sizePolicy.setHeightForWidth(pB76->sizePolicy().hasHeightForWidth());
        pB76->setSizePolicy(sizePolicy);

        gridLayout_32->addWidget(pB76, 0, 2, 1, 1);

        pB84 = new QPushButton(layoutWidget_8);
        pB84->setObjectName(QString::fromUtf8("pB84"));
        sizePolicy.setHeightForWidth(pB84->sizePolicy().hasHeightForWidth());
        pB84->setSizePolicy(sizePolicy);

        gridLayout_32->addWidget(pB84, 1, 0, 1, 1);

        pB85 = new QPushButton(layoutWidget_8);
        pB85->setObjectName(QString::fromUtf8("pB85"));
        sizePolicy.setHeightForWidth(pB85->sizePolicy().hasHeightForWidth());
        pB85->setSizePolicy(sizePolicy);

        gridLayout_32->addWidget(pB85, 1, 1, 1, 1);

        pB86 = new QPushButton(layoutWidget_8);
        pB86->setObjectName(QString::fromUtf8("pB86"));
        sizePolicy.setHeightForWidth(pB86->sizePolicy().hasHeightForWidth());
        pB86->setSizePolicy(sizePolicy);

        gridLayout_32->addWidget(pB86, 1, 2, 1, 1);

        pB94 = new QPushButton(layoutWidget_8);
        pB94->setObjectName(QString::fromUtf8("pB94"));
        sizePolicy.setHeightForWidth(pB94->sizePolicy().hasHeightForWidth());
        pB94->setSizePolicy(sizePolicy);

        gridLayout_32->addWidget(pB94, 2, 0, 1, 1);

        pB95 = new QPushButton(layoutWidget_8);
        pB95->setObjectName(QString::fromUtf8("pB95"));
        sizePolicy.setHeightForWidth(pB95->sizePolicy().hasHeightForWidth());
        pB95->setSizePolicy(sizePolicy);

        gridLayout_32->addWidget(pB95, 2, 1, 1, 1);

        pB96 = new QPushButton(layoutWidget_8);
        pB96->setObjectName(QString::fromUtf8("pB96"));
        sizePolicy.setHeightForWidth(pB96->sizePolicy().hasHeightForWidth());
        pB96->setSizePolicy(sizePolicy);

        gridLayout_32->addWidget(pB96, 2, 2, 1, 1);

        layoutWidget_9 = new QWidget(MainForm);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(450, 410, 202, 181));
        gridLayout_33 = new QGridLayout(layoutWidget_9);
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        gridLayout_33->setContentsMargins(0, 0, 0, 0);
        pB77 = new QPushButton(layoutWidget_9);
        pB77->setObjectName(QString::fromUtf8("pB77"));
        sizePolicy.setHeightForWidth(pB77->sizePolicy().hasHeightForWidth());
        pB77->setSizePolicy(sizePolicy);

        gridLayout_33->addWidget(pB77, 0, 0, 1, 1);

        pB78 = new QPushButton(layoutWidget_9);
        pB78->setObjectName(QString::fromUtf8("pB78"));
        sizePolicy.setHeightForWidth(pB78->sizePolicy().hasHeightForWidth());
        pB78->setSizePolicy(sizePolicy);

        gridLayout_33->addWidget(pB78, 0, 1, 1, 1);

        pB79 = new QPushButton(layoutWidget_9);
        pB79->setObjectName(QString::fromUtf8("pB79"));
        sizePolicy.setHeightForWidth(pB79->sizePolicy().hasHeightForWidth());
        pB79->setSizePolicy(sizePolicy);

        gridLayout_33->addWidget(pB79, 0, 2, 1, 1);

        pB87 = new QPushButton(layoutWidget_9);
        pB87->setObjectName(QString::fromUtf8("pB87"));
        sizePolicy.setHeightForWidth(pB87->sizePolicy().hasHeightForWidth());
        pB87->setSizePolicy(sizePolicy);

        gridLayout_33->addWidget(pB87, 1, 0, 1, 1);

        pB88 = new QPushButton(layoutWidget_9);
        pB88->setObjectName(QString::fromUtf8("pB88"));
        sizePolicy.setHeightForWidth(pB88->sizePolicy().hasHeightForWidth());
        pB88->setSizePolicy(sizePolicy);

        gridLayout_33->addWidget(pB88, 1, 1, 1, 1);

        pB89 = new QPushButton(layoutWidget_9);
        pB89->setObjectName(QString::fromUtf8("pB89"));
        sizePolicy.setHeightForWidth(pB89->sizePolicy().hasHeightForWidth());
        pB89->setSizePolicy(sizePolicy);

        gridLayout_33->addWidget(pB89, 1, 2, 1, 1);

        pB97 = new QPushButton(layoutWidget_9);
        pB97->setObjectName(QString::fromUtf8("pB97"));
        sizePolicy.setHeightForWidth(pB97->sizePolicy().hasHeightForWidth());
        pB97->setSizePolicy(sizePolicy);

        gridLayout_33->addWidget(pB97, 2, 0, 1, 1);

        pB98 = new QPushButton(layoutWidget_9);
        pB98->setObjectName(QString::fromUtf8("pB98"));
        sizePolicy.setHeightForWidth(pB98->sizePolicy().hasHeightForWidth());
        pB98->setSizePolicy(sizePolicy);

        gridLayout_33->addWidget(pB98, 2, 1, 1, 1);

        pB99 = new QPushButton(layoutWidget_9);
        pB99->setObjectName(QString::fromUtf8("pB99"));
        sizePolicy.setHeightForWidth(pB99->sizePolicy().hasHeightForWidth());
        pB99->setSizePolicy(sizePolicy);

        gridLayout_33->addWidget(pB99, 2, 2, 1, 1);

        lcdNumber = new QLCDNumber(MainForm);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(690, 20, 201, 61));
        layoutWidget_10 = new QWidget(MainForm);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(690, 90, 202, 181));
        gridLayout_0 = new QGridLayout(layoutWidget_10);
        gridLayout_0->setObjectName(QString::fromUtf8("gridLayout_0"));
        gridLayout_0->setContentsMargins(0, 0, 0, 0);
        pB1 = new QPushButton(layoutWidget_10);
        pB1->setObjectName(QString::fromUtf8("pB1"));
        sizePolicy.setHeightForWidth(pB1->sizePolicy().hasHeightForWidth());
        pB1->setSizePolicy(sizePolicy);

        gridLayout_0->addWidget(pB1, 0, 0, 1, 1);

        pB2 = new QPushButton(layoutWidget_10);
        pB2->setObjectName(QString::fromUtf8("pB2"));
        sizePolicy.setHeightForWidth(pB2->sizePolicy().hasHeightForWidth());
        pB2->setSizePolicy(sizePolicy);

        gridLayout_0->addWidget(pB2, 0, 1, 1, 1);

        pB3 = new QPushButton(layoutWidget_10);
        pB3->setObjectName(QString::fromUtf8("pB3"));
        sizePolicy.setHeightForWidth(pB3->sizePolicy().hasHeightForWidth());
        pB3->setSizePolicy(sizePolicy);

        gridLayout_0->addWidget(pB3, 0, 2, 1, 1);

        pB4 = new QPushButton(layoutWidget_10);
        pB4->setObjectName(QString::fromUtf8("pB4"));
        sizePolicy.setHeightForWidth(pB4->sizePolicy().hasHeightForWidth());
        pB4->setSizePolicy(sizePolicy);

        gridLayout_0->addWidget(pB4, 1, 0, 1, 1);

        pB5 = new QPushButton(layoutWidget_10);
        pB5->setObjectName(QString::fromUtf8("pB5"));
        sizePolicy.setHeightForWidth(pB5->sizePolicy().hasHeightForWidth());
        pB5->setSizePolicy(sizePolicy);

        gridLayout_0->addWidget(pB5, 1, 1, 1, 1);

        pB6 = new QPushButton(layoutWidget_10);
        pB6->setObjectName(QString::fromUtf8("pB6"));
        sizePolicy.setHeightForWidth(pB6->sizePolicy().hasHeightForWidth());
        pB6->setSizePolicy(sizePolicy);

        gridLayout_0->addWidget(pB6, 1, 2, 1, 1);

        pB7 = new QPushButton(layoutWidget_10);
        pB7->setObjectName(QString::fromUtf8("pB7"));
        sizePolicy.setHeightForWidth(pB7->sizePolicy().hasHeightForWidth());
        pB7->setSizePolicy(sizePolicy);

        gridLayout_0->addWidget(pB7, 2, 0, 1, 1);

        pB8 = new QPushButton(layoutWidget_10);
        pB8->setObjectName(QString::fromUtf8("pB8"));
        sizePolicy.setHeightForWidth(pB8->sizePolicy().hasHeightForWidth());
        pB8->setSizePolicy(sizePolicy);

        gridLayout_0->addWidget(pB8, 2, 1, 1, 1);

        pB9 = new QPushButton(layoutWidget_10);
        pB9->setObjectName(QString::fromUtf8("pB9"));
        sizePolicy.setHeightForWidth(pB9->sizePolicy().hasHeightForWidth());
        pB9->setSizePolicy(sizePolicy);

        gridLayout_0->addWidget(pB9, 2, 2, 1, 1);

        pB_autoSet = new QPushButton(MainForm);
        pB_autoSet->setObjectName(QString::fromUtf8("pB_autoSet"));
        pB_autoSet->setGeometry(QRect(690, 520, 102, 25));
        pB_start = new QPushButton(MainForm);
        pB_start->setObjectName(QString::fromUtf8("pB_start"));
        pB_start->setGeometry(QRect(690, 520, 102, 25));
        groupBox_1 = new QGroupBox(MainForm);
        groupBox_1->setObjectName(QString::fromUtf8("groupBox_1"));
        groupBox_1->setGeometry(QRect(690, 370, 101, 101));
        rB_single = new QRadioButton(groupBox_1);
        rB_single->setObjectName(QString::fromUtf8("rB_single"));
        rB_single->setGeometry(QRect(10, 25, 99, 21));
        rB_online = new QRadioButton(groupBox_1);
        rB_online->setObjectName(QString::fromUtf8("rB_online"));
        rB_online->setGeometry(QRect(10, 45, 99, 21));
        label_ip = new QLabel(groupBox_1);
        label_ip->setObjectName(QString::fromUtf8("label_ip"));
        label_ip->setGeometry(QRect(10, 70, 21, 18));
        groupBox_2 = new QGroupBox(MainForm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(790, 370, 101, 101));
        rB_hard = new QRadioButton(groupBox_2);
        rB_hard->setObjectName(QString::fromUtf8("rB_hard"));
        rB_hard->setGeometry(QRect(10, 25, 99, 21));
        rB_normal = new QRadioButton(groupBox_2);
        rB_normal->setObjectName(QString::fromUtf8("rB_normal"));
        rB_normal->setGeometry(QRect(10, 45, 99, 21));
        rB_easy = new QRadioButton(groupBox_2);
        rB_easy->setObjectName(QString::fromUtf8("rB_easy"));
        rB_easy->setGeometry(QRect(10, 65, 99, 21));
        lineEdit_IP = new QLineEdit(MainForm);
        lineEdit_IP->setObjectName(QString::fromUtf8("lineEdit_IP"));
        lineEdit_IP->setGeometry(QRect(720, 435, 61, 26));
        pB_fileSet = new QPushButton(MainForm);
        pB_fileSet->setObjectName(QString::fromUtf8("pB_fileSet"));
        pB_fileSet->setGeometry(QRect(690, 560, 102, 25));
        pB_setTable = new QPushButton(MainForm);
        pB_setTable->setObjectName(QString::fromUtf8("pB_setTable"));
        pB_setTable->setGeometry(QRect(690, 480, 102, 25));
        cB_theme = new QComboBox(MainForm);
        cB_theme->setObjectName(QString::fromUtf8("cB_theme"));
        cB_theme->setGeometry(QRect(810, 480, 85, 27));
        label = new QLabel(MainForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(810, 465, 62, 18));
        pB_resetTable = new QPushButton(MainForm);
        pB_resetTable->setObjectName(QString::fromUtf8("pB_resetTable"));
        pB_resetTable->setGeometry(QRect(690, 480, 102, 25));
        pB_giveUp = new QPushButton(MainForm);
        pB_giveUp->setObjectName(QString::fromUtf8("pB_giveUp"));
        pB_giveUp->setGeometry(QRect(690, 560, 102, 25));
        cB_background = new QComboBox(MainForm);
        cB_background->setObjectName(QString::fromUtf8("cB_background"));
        cB_background->setGeometry(QRect(810, 525, 85, 27));
        label_2 = new QLabel(MainForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(810, 510, 62, 18));
        pB_win = new QPushButton(MainForm);
        pB_win->setObjectName(QString::fromUtf8("pB_win"));
        pB_win->setGeometry(QRect(820, 562, 61, 20));
        groupBox_3 = new QGroupBox(MainForm);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(690, 280, 211, 81));
        progressBar_1 = new QProgressBar(groupBox_3);
        progressBar_1->setObjectName(QString::fromUtf8("progressBar_1"));
        progressBar_1->setGeometry(QRect(50, 20, 151, 23));
        progressBar_1->setValue(24);
        progressBar_2 = new QProgressBar(groupBox_3);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(50, 50, 151, 23));
        progressBar_2->setValue(24);
        label_p1 = new QLabel(groupBox_3);
        label_p1->setObjectName(QString::fromUtf8("label_p1"));
        label_p1->setGeometry(QRect(10, 24, 41, 18));
        label_p2 = new QLabel(groupBox_3);
        label_p2->setObjectName(QString::fromUtf8("label_p2"));
        label_p2->setGeometry(QRect(10, 53, 41, 16));
        pB_help = new QPushButton(MainForm);
        pB_help->setObjectName(QString::fromUtf8("pB_help"));
        pB_help->setGeometry(QRect(820, 562, 61, 21));

        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "\346\225\260\347\213\254\346\270\270\346\210\217\347\275\221\347\273\234\345\257\271\346\210\230\345\271\263\345\217\260", 0, QApplication::UnicodeUTF8));
        pB14->setText(QString());
        pB15->setText(QString());
        pB16->setText(QString());
        pB24->setText(QString());
        pB25->setText(QString());
        pB26->setText(QString());
        pB34->setText(QString());
        pB35->setText(QString());
        pB36->setText(QString());
        pB17->setText(QString());
        pB18->setText(QString());
        pB19->setText(QString());
        pB27->setText(QString());
        pB28->setText(QString());
        pB29->setText(QString());
        pB37->setText(QString());
        pB38->setText(QString());
        pB39->setText(QString());
        pB41->setText(QString());
        pB42->setText(QString());
        pB43->setText(QString());
        pB51->setText(QString());
        pB53->setText(QString());
        pB61->setText(QString());
        pB62->setText(QString());
        pB63->setText(QString());
        pB52->setText(QString());
        pB44->setText(QString());
        pB45->setText(QString());
        pB46->setText(QString());
        pB54->setText(QString());
        pB55->setText(QString());
        pB56->setText(QString());
        pB64->setText(QString());
        pB65->setText(QString());
        pB66->setText(QString());
        pB47->setText(QString());
        pB48->setText(QString());
        pB49->setText(QString());
        pB57->setText(QString());
        pB58->setText(QString());
        pB59->setText(QString());
        pB67->setText(QString());
        pB68->setText(QString());
        pB69->setText(QString());
        pB11->setText(QString());
        pB12->setText(QString());
        pB13->setText(QString());
        pB21->setText(QString());
        pB22->setText(QString());
        pB23->setText(QString());
        pB31->setText(QString());
        pB32->setText(QString());
        pB33->setText(QString());
        pB71->setText(QString());
        pB72->setText(QString());
        pB73->setText(QString());
        pB81->setText(QString());
        pB82->setText(QString());
        pB83->setText(QString());
        pB91->setText(QString());
        pB92->setText(QString());
        pB93->setText(QString());
        pB74->setText(QString());
        pB75->setText(QString());
        pB76->setText(QString());
        pB84->setText(QString());
        pB85->setText(QString());
        pB86->setText(QString());
        pB94->setText(QString());
        pB95->setText(QString());
        pB96->setText(QString());
        pB77->setText(QString());
        pB78->setText(QString());
        pB79->setText(QString());
        pB87->setText(QString());
        pB88->setText(QString());
        pB89->setText(QString());
        pB97->setText(QString());
        pB98->setText(QString());
        pB99->setText(QString());
        pB1->setText(QString());
        pB2->setText(QString());
        pB3->setText(QString());
        pB4->setText(QString());
        pB5->setText(QString());
        pB6->setText(QString());
        pB7->setText(QString());
        pB8->setText(QString());
        pB9->setText(QString());
        pB_autoSet->setText(QApplication::translate("MainForm", "\350\207\252\345\212\250\345\207\272\351\242\230", 0, QApplication::UnicodeUTF8));
        pB_start->setText(QApplication::translate("MainForm", "\345\274\200\345\247\213\350\256\241\346\227\266", 0, QApplication::UnicodeUTF8));
        groupBox_1->setTitle(QApplication::translate("MainForm", "[\347\216\251\345\256\266\346\225\260\351\207\217]", 0, QApplication::UnicodeUTF8));
        rB_single->setText(QApplication::translate("MainForm", "\345\215\225\346\234\272\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        rB_online->setText(QApplication::translate("MainForm", "\350\201\224\347\275\221\345\257\271\346\210\230", 0, QApplication::UnicodeUTF8));
        label_ip->setText(QApplication::translate("MainForm", "IP", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainForm", "[\346\270\270\346\210\217\351\232\276\345\272\246]", 0, QApplication::UnicodeUTF8));
        rB_hard->setText(QApplication::translate("MainForm", "\345\233\260\351\232\276", 0, QApplication::UnicodeUTF8));
        rB_normal->setText(QApplication::translate("MainForm", "\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        rB_easy->setText(QApplication::translate("MainForm", "\347\256\200\345\215\225", 0, QApplication::UnicodeUTF8));
        pB_fileSet->setText(QApplication::translate("MainForm", "\350\257\273\345\217\226\351\242\230\345\272\223", 0, QApplication::UnicodeUTF8));
        pB_setTable->setText(QApplication::translate("MainForm", "\344\272\272\345\267\245\345\207\272\351\242\230", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainForm", "\346\233\264\346\215\242\344\270\273\351\242\230", 0, QApplication::UnicodeUTF8));
        pB_resetTable->setText(QApplication::translate("MainForm", "\346\224\276\345\274\203\351\242\230\347\233\256", 0, QApplication::UnicodeUTF8));
        pB_giveUp->setText(QApplication::translate("MainForm", "\350\256\244\350\276\223", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainForm", "\351\200\211\346\213\251\350\203\214\346\231\257", 0, QApplication::UnicodeUTF8));
        pB_win->setText(QApplication::translate("MainForm", "&w", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainForm", "[\346\270\270\346\210\217\350\277\233\345\272\246]", 0, QApplication::UnicodeUTF8));
        label_p1->setText(QApplication::translate("MainForm", "\345\267\261\346\226\271\357\274\232", 0, QApplication::UnicodeUTF8));
        label_p2->setText(QApplication::translate("MainForm", "\345\257\271\346\226\271\357\274\232", 0, QApplication::UnicodeUTF8));
        pB_help->setText(QApplication::translate("MainForm", "\346\223\215\344\275\234\350\257\264\346\230\216", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainForm);
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUWIDGET_H
