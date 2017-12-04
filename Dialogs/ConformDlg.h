#ifndef CONFORMDLG_H
#define CONFORMDLG_H

#include <QtWidgets/QDialog>
#include <QTimer>
#include "ui_conform.h"

namespace Ui {
class ConformDlg;
}

class ConformDlg : public QDialog, public Ui_conformDlg {
    Q_OBJECT
public:
    ConformDlg(QWidget *parent = 0);
    ~ConformDlg();
    bool m_bconformed;  //Is Connect Successful
    bool makeMode();
private slots:
    void funReject();
    void funConform();
};

#endif // CONFORMDLG_H
