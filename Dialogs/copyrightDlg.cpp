#include <sstream>
#include "copyrightDlg.h"

using namespace std;

copyrightDlg::copyrightDlg(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    this->setWindowTitle(QString(tr("关于软件")));
    stringstream ss;
    ss << "[ 数独游戏网络对战平台 V1.0 ]\n\n"
       << "2009年红旗杯\n"
       << "全国大学生开源软件竞赛三等奖作品\n\n"
       << "本软件遵循 GNU/GPL v3 协议\n"
       << "基于 Qt 平台开发设计\n\n"
       << "特此声明^^~\n\n"
       << "      --成都理工大学cdutllx设计组";
    text->setText(QString(tr(ss.str().c_str())));
}

copyrightDlg::~copyrightDlg()
{
}
