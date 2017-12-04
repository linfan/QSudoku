#ifndef EXPLANATRYDLG_H
#define EXPLANATRYDLG_H

#include <QtWidgets/QDialog>
#include "ui_explanatry.h"

class ExplanatryDlg : public QDialog, public Ui_explanatry {
    Q_OBJECT

public:
    ExplanatryDlg(QWidget *parent = 0);
    ~ExplanatryDlg();
private:
    int m_page;
    void switchPage();
private slots:
    void next();
    void previous();
};

#endif // EXPLANATRYDLG_H
