/********************************************************************************
** Form generated from reading ui file 'process.ui'
**
** Created: Wed Nov 18 22:56:28 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROCESS_H
#define UI_PROCESS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_processDlg
{
public:
    QPushButton *pB_return;
    QLabel *label;

    void setupUi(QDialog *processDlg)
    {
        if (processDlg->objectName().isEmpty())
            processDlg->setObjectName(QString::fromUtf8("processDlg"));
        processDlg->resize(223, 109);
        processDlg->setMinimumSize(QSize(223, 109));
        processDlg->setMaximumSize(QSize(223, 109));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/sudoku.png"), QSize(), QIcon::Normal, QIcon::Off);
        processDlg->setWindowIcon(icon);
        pB_return = new QPushButton(processDlg);
        pB_return->setObjectName(QString::fromUtf8("pB_return"));
        pB_return->setGeometry(QRect(60, 60, 92, 28));
        label = new QLabel(processDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 231, 18));

        retranslateUi(processDlg);

        QMetaObject::connectSlotsByName(processDlg);
    } // setupUi

    void retranslateUi(QDialog *processDlg)
    {
        processDlg->setWindowTitle(QApplication::translate("processDlg", "[\350\277\236\346\216\245\344\270\255...\350\257\267\347\255\211\345\276\205]", 0, QApplication::UnicodeUTF8));
        pB_return->setText(QApplication::translate("processDlg", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("processDlg", "\346\255\243\345\234\250\350\277\236\346\216\245\347\233\256\347\232\204\344\270\273\346\234\272, \347\255\211\345\276\205\345\233\236\345\272\224...", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(processDlg);
    } // retranslateUi

};

namespace Ui {
    class processDlg: public Ui_processDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESS_H
