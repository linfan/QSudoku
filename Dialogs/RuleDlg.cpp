#include "RuleDlg.h"
#include <QPixmap>

RuleDlg::RuleDlg(QWidget *parent)
    : QDialog(parent) {
    setupUi(this);
    m_page = 1;
    switchPage();
    textL->setAlignment(Qt::AlignHCenter);
    textR->setAlignment(Qt::AlignHCenter);
    pBL->setVisible(false);
    this->setWindowTitle(QString(tr("数独规则")));
    connect(pBL, &QPushButton::clicked, this, &RuleDlg::previous);
    connect(pBR, &QPushButton::clicked, this, &RuleDlg::next);
}

RuleDlg::~RuleDlg() {
}

void RuleDlg::switchPage() {
    switch (m_page) {
    case 1:
        title->setTitle(QString(tr("[第一页: 什么是数独]")));
        textB->setText(QString(
                           tr("数独是一种源自18世纪末的瑞士，后在美国发展、\n\n并在日本得以发扬光大的数学智力拼图游戏。\n\n拼图是九宫格（即3格宽×3格高）的正方形状，\n\n每一格又细分为一个九宫格。在每一个小九宫格中，\n\n分别填上1至9的数字，让整个大九宫格每一列、每一行的数字都不重复。")));
        textL->clear();
        textR->clear();
        break;
    case 2:
        title->setTitle(QString(tr("[第二页: 数独的区]")));
        textB->clear();
        textL->setPixmap(QPixmap(":/png/H1.png"));
        textR->setText(QString(
                           tr("数独游戏在9x9的方格内进行，\n\n分为3x3的小方格，\n\n被称为[区]。")));
        break;
    case 3:
        title->setTitle(QString(tr("[第三页: 填入数字]")));
        textB->clear();
        textL->setPixmap(QPixmap(":/png/H2.png"));
        textR->setText(QString(
                           tr("数独游戏从已经填入部分数的格开始\n\n数独游戏的目的是根据下列规则，\n\n用1至9之间的数字填满空格，\n\n一个格子只能填入一个数字。")));
        break;
    case 4:
        title->setTitle(QString(tr("[第四页: 数独的行填入]")));
        textB->clear();
        textL->setPixmap(QPixmap(":/png/H3.png"));
        textR->setText(QString(tr("每个数字在每一行只能出现一次。")));
        break;
    case 5:
        title->setTitle(QString(tr("[第五页: 数独的列填入]")));
        textB->clear();
        textL->setPixmap(QPixmap(":/png/H4.png"));
        textR->setText(QString(tr("每个数字在每一列也只能出现一次。")));
        break;
    case 6:
        title->setTitle(QString(tr("[第六页: 数独的区填入]")));
        textB->clear();
        textL->setPixmap(QPixmap(":/png/H5.png"));
        textR->setText(QString(tr("每个数字在每一区只能出现一次。")));
        break;
    case 7:
        title->setTitle(QString(tr("[第二页: 规则总结]")));
        textB->setText(QString(
                           tr("总结这些规则，\n\n即每个数字在每一行、每一列和每一区只能出现一次。\n\n每道题都可根据所提供的数字为线索，\n\n通过逻辑推理解答来。如果按照正确的解题方法，\n\n猜测就没有必要。\n\n一定要记：每道题只有一种答案。")));
        textL->clear();
        textR->clear();
        break;
    }
}

void RuleDlg::next() {
    if (m_page == 7) {
        pBR->setVisible(false);
    } else {
        m_page++;
        pBL->setVisible(true);
        pBR->setVisible(true);
    }
    switchPage();
}

void RuleDlg::previous() {
    if (m_page == 1) {
        pBL->setVisible(false);
    } else {
        m_page--;
        pBL->setVisible(true);
        pBR->setVisible(true);
    }
    switchPage();
}
