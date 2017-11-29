#include "copyrightDlg.h"

copyrightDlg::copyrightDlg(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    this->setWindowTitle(QString(tr("关于软件")));
    text->setText(QString(tr("[ 数独游戏网络对战平台 V1.0 ]\n\n软件基于 红旗Linux6SP2(R)\n\n和 Qt4.5 平台开发设计\n\n本软件遵循 GNU 和 GPL 协议\n\n特此声明^^~\n\n      --成都理工大学cdutllx设计组\n\n         林帆    李晨    许敏")));
}

copyrightDlg::~copyrightDlg()
{
}
