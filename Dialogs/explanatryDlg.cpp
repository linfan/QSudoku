#include "explanatryDlg.h"
#include <QString>

explanatryDlg::explanatryDlg(QWidget *parent)
    : QDialog(parent) {
    setupUi(this);
    m_page = 1;
    switchPage();
    this->setWindowTitle(QString(tr("操作说明")));
    pBL->setVisible(false);
    connect(pBL, SIGNAL(clicked()), this, SLOT(previous()));
    connect(pBR, SIGNAL(clicked()), this, SLOT(next()));
}

explanatryDlg::~explanatryDlg() {
}

void explanatryDlg::switchPage() {
    switch (m_page) {
    case 1:
        title->setTitle(QString(tr("[第一页: 界面介绍]")));
        text->setText(QString(
                          tr("数独游戏网络对战平台界面分为操作界面与游戏界面。\n\n-游戏界面-：由9X9的空白方格组成。\n\n-操作界面-：由计时器、1～9个数字按键、游戏进度条、\n          玩家数量、游戏难度、出题方式、\n          按键主题与背景主题组成。")));
        break;
    case 2:
        title->setTitle(QString(tr("[第二页: 出题方式]")));
        text->setText(QString(
                          tr("出题方式分为读取题库、人工出题与自动出题三种方式。\n\n-人工出题-：使用当前九宫格内容做为游戏题。\n\n-读取题库-：从题库中读取经典数独题目。\n\n-自动出题-：由计算机随机生成一个唯一解的题目。")));
        break;
    case 3:
        title->setTitle(QString(tr("[第三页: 游戏模式]")));
        text->setText(QString(
                          tr("游戏模式分为 单人游戏与网络对战两种模式。\n\n-单人模式-：一个人自己玩。\n\n-对战模式-：与好朋友一绝高下吧！")));
        break;
    case 4:
        title->setTitle(QString(tr("[第四页: 游戏难度]")));
        text->setText(QString(
                          tr("游戏难度分为简单、正常、困难三种难度。\n\n-简单-：在题目中挖掉15个空。\n\n-正常-：在题目中挖掉30个空。\n\n-困难-：在题目中挖掉45个空。")));
        break;
    case 5:
        title->setTitle(QString(tr("[第五页: 开始游戏]")));
        text->setText(QString(
                          tr("确定题目后，点击[开始计时]，再点击操作界面的数字按键，\n\n被选中的数字会变大，然后点击游戏界面的空白方格填入，\n\n双击方格为删除方格内容，当正确的填满后游戏结束。")));
        break;
    case 6:
        title->setTitle(QString(tr("[第六页: 打造自己的题目]")));
        text->setText(QString(
                          tr("直接通过操作界面的数字按键将9X9的空白方格，\n\n填好后点击[人工出题]，如果此题有解且为唯一解，\n\n那么出题成功，开始做题吧。")));
        break;
    case 7:
        title->setTitle(QString(tr("[第七页: 体验经典难题]")));
        text->setText(QString(
                          tr("单击[读取题库]，选择安装目录下的Table文件夹中\n\n找到*.table文件，双击任意一个即可导入，\n\n这些题目都是我们仔细挑选的经典数独题。")));
        break;
    case 8:
        title->setTitle(QString(tr("[第八页: 挑战电脑出题]")));
        text->setText(QString(
                          tr("选好难度后，直接点击[自动出题]，\n\n电脑将自动生成唯一解的题目，\n\n几乎无穷的数独组合，从此数独高手不再担心没有题目做啦！")));
        break;
    case 9:
        title->setTitle(QString(tr("[第九页: 网络对战]")));
        text->setText(QString(
                          tr("双方在玩家人数里选择联网对战，然后输入对方IP，\n\n由其中任意一方加载题目，当加载题目的一方点击[开始计时]，\n\n对方在弹出对话框中选[同意连接]，双方就同步开始计时，\n\n只要一方完成或认输，都将结束游戏。")));
        break;
    case 10:
        title->setTitle(QString(tr("[第十页: 游戏技巧]")));
        text->setText(QString(
                          tr("1.感觉单一的游戏界面过于单调吗-_-\n可以在[更换主题]与[选择背景]里更改主题与背景噢。\n\n2.题目实在做不出来了怎么办呢^^~。\n在单人游戏的时候摁下键盘的Alt+w可以查看答案，呵呵。")));
        break;
    }
}

void explanatryDlg::next() {
    if (m_page == 10) {
        pBR->setVisible(false);
    } else {
        m_page++;
        pBL->setVisible(true);
        pBR->setVisible(true);
    }
    switchPage();
}

void explanatryDlg::previous() {
    if (m_page == 1) {
        pBL->setVisible(false);
    } else {
        m_page--;
        pBL->setVisible(true);
        pBR->setVisible(true);
    }
    switchPage();
}
