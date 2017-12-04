#ifndef ABOUTDLG_H
#define ABOUTDLG_H

#include <QtWidgets/QDialog>
#include "ui_aboutdlg.h"

namespace Ui {
class AboutDlg;
}

class AboutDlg : public QDialog, public Ui_aboutDlg {
    Q_OBJECT
public:
    AboutDlg(QWidget *parent = 0);
    ~AboutDlg();

private slots:
    void showExeplanatry();
    void showRule();
    void showCopyright();
    //void closeDialog();
};

#endif // ABOUTDLG_H
