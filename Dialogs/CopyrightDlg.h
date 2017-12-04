#ifndef COPYRIGHTDLG_H
#define COPYRIGHTDLG_H

#include <QtWidgets/QDialog>
#include "ui_copyright.h"

class CopyrightDlg : public QDialog, public Ui_copyright {
    Q_OBJECT

public:
    CopyrightDlg(QWidget *parent = 0);
    ~CopyrightDlg();

};

#endif // COPYRIGHTDLG_H
