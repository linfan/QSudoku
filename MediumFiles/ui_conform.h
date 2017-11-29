/********************************************************************************
** Form generated from reading ui file 'conform.ui'
**
** Created: Wed Nov 18 22:56:28 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONFORM_H
#define UI_CONFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_conformDlg
{
public:
    QLabel *label;
    QPushButton *pB_reject;
    QPushButton *pB_conform;

    void setupUi(QDialog *conformDlg)
    {
        if (conformDlg->objectName().isEmpty())
            conformDlg->setObjectName(QString::fromUtf8("conformDlg"));
        conformDlg->resize(298, 109);
        conformDlg->setMinimumSize(QSize(298, 109));
        conformDlg->setMaximumSize(QSize(298, 109));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/sudoku.png"), QSize(), QIcon::Normal, QIcon::Off);
        conformDlg->setWindowIcon(icon);
        label = new QLabel(conformDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 231, 18));
        pB_reject = new QPushButton(conformDlg);
        pB_reject->setObjectName(QString::fromUtf8("pB_reject"));
        pB_reject->setGeometry(QRect(40, 60, 92, 28));
        pB_conform = new QPushButton(conformDlg);
        pB_conform->setObjectName(QString::fromUtf8("pB_conform"));
        pB_conform->setGeometry(QRect(150, 60, 92, 28));

        retranslateUi(conformDlg);
        QObject::connect(pB_conform, SIGNAL(clicked()), conformDlg, SLOT(close()));

        QMetaObject::connectSlotsByName(conformDlg);
    } // setupUi

    void retranslateUi(QDialog *conformDlg)
    {
        conformDlg->setWindowTitle(QApplication::translate("conformDlg", "[\350\257\267\346\261\202\350\277\236\346\216\245]", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("conformDlg", "\346\224\266\345\210\260\345\257\271\346\226\271\350\277\236\346\216\245\350\257\267\346\261\202\357\274\214\346\230\257\345\220\246\345\220\214\346\204\217\350\277\236\346\216\245\357\274\237", 0, QApplication::UnicodeUTF8));
        pB_reject->setText(QApplication::translate("conformDlg", "\346\213\222\347\273\235", 0, QApplication::UnicodeUTF8));
        pB_conform->setText(QApplication::translate("conformDlg", "\345\220\214\346\204\217", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(conformDlg);
    } // retranslateUi

};

namespace Ui {
    class conformDlg: public Ui_conformDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFORM_H
