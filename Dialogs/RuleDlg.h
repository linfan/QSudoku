#ifndef RULEDLG_H
#define RULEDLG_H

#include <QtWidgets/QDialog>
#include "ui_rule.h"

class RuleDlg : public QDialog, public Ui_rule {
    Q_OBJECT

public:
    RuleDlg(QWidget *parent = 0);
    ~RuleDlg();
private:
    int m_page;
    void switchPage();
private slots:
    void next();
    void previous();

};

#endif // RULEDLG_H
