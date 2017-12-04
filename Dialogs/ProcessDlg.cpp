#include "ProcessDlg.h"
#include "ui_process.h"
#include <QMessageBox>
#include <QString>

ProcessDlg::ProcessDlg(QWidget *parent) :
    QDialog(parent) {
    setupUi(this);
    m_bConnected = false;
    m_bCanceled = false;
    connect(pB_return, &QPushButton::clicked, this, &ProcessDlg::closeDialog);
    connect(&m_Timer, &QTimer::timeout, this, &ProcessDlg::cannelDialog);
}

ProcessDlg::~ProcessDlg() {
}

void ProcessDlg::closeDialog() {
    QMessageBox box(QMessageBox::Critical, QString(tr("错误")),
                    QString(tr("连接失败，请检查网络!")), QMessageBox::Ok, this,
                    Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    box.exec();
    m_bCanceled = true;
    m_Timer.stop();
    //close();
}

void ProcessDlg::cannelDialog() {
    QMessageBox box(QMessageBox::Critical, QString(tr("错误")),
                    QString(tr("连接超时，请检查网络!")), QMessageBox::Ok, this,
                    Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    box.exec();
    m_bCanceled = true;
    m_Timer.stop();
    //close();
}

