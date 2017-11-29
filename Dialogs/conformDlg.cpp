#include "conformDlg.h"
#include "ui_conform.h"

conformDlg::conformDlg(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    m_bconformed = FALSE;
    connect(pB_reject,SIGNAL(clicked()),this,SLOT(funReject()));
    connect(pB_conform,SIGNAL(clicked()),this,SLOT(funConform()));
}

conformDlg::~conformDlg()
{
}

bool conformDlg::makeMode()
{
    exec();
    return m_bconformed;
}

void conformDlg::funReject()
{
    m_bconformed = FALSE;
    close();
}

void conformDlg::funConform()
{
    m_bconformed = TRUE;
    //close();
}
