#include "Aboutdlg.h"
#include "ui_aboutdlg.h"
#include "ExplanatryDlg.h"
#include "CopyrightDlg.h"
#include "RuleDlg.h"

AboutDlg::AboutDlg(QWidget *parent) :
    QDialog(parent) {
    setupUi(this);
    this->setWindowTitle(QString(tr("数独")));
    title->setText(QString(tr("数独游戏网络对战平台")));
    text->setText(QString(
                      tr("        这是一款功能强大的数独游戏平台，拥有各种华丽的主题与背\n景，专门为数独游戏爱好者量身定做，支持读取题库、人工出题、\n自动出题三种方式，让你既可以体验经典数独的魅力，又可以打造\n自己的完美数独、还可以由电脑来出各种新颖的题目。同时打破以\n往只能一个人玩数独的孤独与寂寞，可以联网与好友一绝高下。")));
    connect(pB_explanatry, &QPushButton::clicked, this, &AboutDlg::showExeplanatry);
    connect(pB_rule, &QPushButton::clicked, this, &AboutDlg::showRule);
    connect(pB_about, &QPushButton::clicked, this, &AboutDlg::showCopyright);
}

AboutDlg::~AboutDlg() {
}

void AboutDlg::showExeplanatry() {
    //close();
    this->setVisible(false);
    ExplanatryDlg ex(this->parentWidget());
    ex.exec();
    this->setVisible(true);
}

void AboutDlg::showRule() {
    //close();
    this->setVisible(false);
    RuleDlg ru(this->parentWidget());
    ru.exec();
    this->setVisible(true);
}

void AboutDlg::showCopyright() {
    //close();
    this->setVisible(false);
    CopyrightDlg co(this->parentWidget());
    co.exec();
    this->setVisible(true);
}
/*
void aboutDlg::closeDialog()
{
    close();
}
*/
