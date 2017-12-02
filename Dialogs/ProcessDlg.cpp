#include "ProcessDlg.h"
#include "ui_process.h"
#include <QMessageBox>
#include <QString>

processDlg::processDlg(QWidget *parent) :
    QDialog(parent) {
    setupUi(this);
    m_bConnected = false;
    m_bCanceled = false;
    connect(pB_return, SIGNAL(clicked()), this, SLOT(closeDialog()));
    connect(&m_Timer, SIGNAL(timeout()), this, SLOT(cannelDialog()));
}

processDlg::~processDlg() {
}

void processDlg::closeDialog() {
    QMessageBox box(QMessageBox::Critical, QString(tr("错误")),
                    QString(tr("连接失败，请检查网络!")), QMessageBox::Ok, this,
                    Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    box.exec();
    m_bCanceled = true;
    m_Timer.stop();
    //close();
}

void processDlg::cannelDialog() {
    QMessageBox box(QMessageBox::Critical, QString(tr("错误")),
                    QString(tr("连接超时，请检查网络!")), QMessageBox::Ok, this,
                    Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    box.exec();
    m_bCanceled = true;
    m_Timer.stop();
    //close();
}

