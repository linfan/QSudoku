#ifndef ABOUTDLG_H
#define ABOUTDLG_H

#include <QtWidgets/QDialog>
#include "ui_aboutdlg.h"

namespace Ui {
class aboutDlg;
}

class aboutDlg : public QDialog, public Ui_aboutDlg {
    Q_OBJECT
public:
    aboutDlg(QWidget *parent = 0);
    ~aboutDlg();

private slots:
    void showExeplanatry();
    void showRule();
    void showCopyright();
    //void closeDialog();
};

#endif // ABOUTDLG_H
