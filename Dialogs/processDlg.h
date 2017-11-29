#ifndef PROCESSDLG_H
#define PROCESSDLG_H

#include <QtGui/QDialog>
#include <QTimer>
#include "ui_process.h"

namespace Ui {
    class processDlg;
}

class processDlg : public QDialog,public Ui_processDlg
{
    Q_OBJECT
public:
    processDlg(QWidget *parent = 0);
    ~processDlg();
    bool m_bConnected;  //Is Connect Successful
    bool m_bCanceled;  //Is Connect Canceled
    QTimer m_Timer;

private slots:
    void closeDialog();
    void cannelDialog();
};

#endif // PROCESSDLG_H
