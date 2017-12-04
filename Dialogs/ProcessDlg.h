#ifndef PROCESSDLG_H
#define PROCESSDLG_H

#include <QtWidgets/QDialog>
#include <QTimer>
#include "ui_process.h"

namespace Ui {
class ProcessDlg;
}

class ProcessDlg : public QDialog, public Ui_processDlg {
    Q_OBJECT
public:
    ProcessDlg(QWidget *parent = 0);
    ~ProcessDlg();
    bool m_bConnected;  //Is Connect Successful
    bool m_bCanceled;  //Is Connect Canceled
    QTimer m_Timer;

private slots:
    void closeDialog();
    void cannelDialog();
};

#endif // PROCESSDLG_H
