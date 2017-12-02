#ifndef CONFORMDLG_H
#define CONFORMDLG_H

#include <QtWidgets/QDialog>
#include <QTimer>
#include "ui_conform.h"

namespace Ui {
class conformDlg;
}

class conformDlg : public QDialog, public Ui_conformDlg {
    Q_OBJECT
public:
    conformDlg(QWidget *parent = 0);
    ~conformDlg();
    bool m_bconformed;  //Is Connect Successful
    bool makeMode();
private slots:
    void funReject();
    void funConform();
};

#endif // CONFORMDLG_H
