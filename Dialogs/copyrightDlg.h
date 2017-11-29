#ifndef COPYRIGHTDLG_H
#define COPYRIGHTDLG_H

#include <QtGui/QDialog>
#include "ui_copyright.h"

class copyrightDlg : public QDialog,public Ui_copyright
{
    Q_OBJECT

public:
    copyrightDlg(QWidget *parent = 0);
    ~copyrightDlg();

};

#endif // COPYRIGHTDLG_H
