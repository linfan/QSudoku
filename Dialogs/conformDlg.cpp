#include "conformDlg.h"
#include "ui_conform.h"

conformDlg::conformDlg(QWidget *parent) :
    QDialog(parent) {
    setupUi(this);
    m_bconformed = false;
    connect(pB_reject, SIGNAL(clicked()), this, SLOT(funReject()));
    connect(pB_conform, SIGNAL(clicked()), this, SLOT(funConform()));
}

conformDlg::~conformDlg() {
}

bool conformDlg::makeMode() {
    exec();
    return m_bconformed;
}

void conformDlg::funReject() {
    m_bconformed = false;
    close();
}

void conformDlg::funConform() {
    m_bconformed = true;
    //close();
}
