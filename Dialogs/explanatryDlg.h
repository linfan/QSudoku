#ifndef EXPLANATRYDLG_H
#define EXPLANATRYDLG_H

#include <QtWidgets/QDialog>
#include "ui_explanatry.h"

class explanatryDlg : public QDialog,public Ui_explanatry
{
    Q_OBJECT

public:
    explanatryDlg(QWidget *parent = 0);
    ~explanatryDlg();
private:
    int m_page;
    void switchPage();
private slots:
    void next();
    void previous();
};

#endif // EXPLANATRYDLG_H
