#include "ConformDlg.h"
#include "ui_conform.h"

ConformDlg::ConformDlg(QWidget *parent) :
    QDialog(parent) {
    setupUi(this);
    m_bconformed = false;
    connect(pB_reject, &QPushButton::clicked, this, &ConformDlg::funReject);
    connect(pB_conform, &QPushButton::clicked, this, &ConformDlg::funConform);
}

ConformDlg::~ConformDlg() {
}

bool ConformDlg::makeMode() {
    exec();
    return m_bconformed;
}

void ConformDlg::funReject() {
    m_bconformed = false;
    close();
}

void ConformDlg::funConform() {
    m_bconformed = true;
    //close();
}
