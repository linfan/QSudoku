/********************************************************************************
** Form generated from reading ui file 'aboutdlg.ui'
**
** Created: Wed Nov 18 22:56:28 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ABOUTDLG_H
#define UI_ABOUTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_aboutDlg
{
public:
    QDialogButtonBox *pB_return;
    QPushButton *pB_explanatry;
    QPushButton *pB_about;
    QPushButton *pB_rule;
    QLabel *text;
    QLabel *title;

    void setupUi(QDialog *aboutDlg)
    {
        if (aboutDlg->objectName().isEmpty())
            aboutDlg->setObjectName(QString::fromUtf8("aboutDlg"));
        aboutDlg->resize(444, 215);
        aboutDlg->setMinimumSize(QSize(444, 215));
        aboutDlg->setMaximumSize(QSize(444, 215));
        pB_return = new QDialogButtonBox(aboutDlg);
        pB_return->setObjectName(QString::fromUtf8("pB_return"));
        pB_return->setGeometry(QRect(330, 167, 91, 32));
        pB_return->setOrientation(Qt::Horizontal);
        pB_return->setStandardButtons(QDialogButtonBox::Close);
        pB_return->setCenterButtons(true);
        pB_explanatry = new QPushButton(aboutDlg);
        pB_explanatry->setObjectName(QString::fromUtf8("pB_explanatry"));
        pB_explanatry->setGeometry(QRect(130, 170, 92, 28));
        pB_about = new QPushButton(aboutDlg);
        pB_about->setObjectName(QString::fromUtf8("pB_about"));
        pB_about->setGeometry(QRect(230, 170, 92, 28));
        pB_rule = new QPushButton(aboutDlg);
        pB_rule->setObjectName(QString::fromUtf8("pB_rule"));
        pB_rule->setGeometry(QRect(30, 170, 92, 28));
        text = new QLabel(aboutDlg);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(30, 50, 391, 101));
        title = new QLabel(aboutDlg);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(111, 20, 191, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Andale Mono"));
        font.setPointSize(14);
        title->setFont(font);

        retranslateUi(aboutDlg);
        QObject::connect(pB_return, SIGNAL(accepted()), aboutDlg, SLOT(accept()));
        QObject::connect(pB_return, SIGNAL(rejected()), aboutDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(aboutDlg);
    } // setupUi

    void retranslateUi(QDialog *aboutDlg)
    {
        aboutDlg->setWindowTitle(QApplication::translate("aboutDlg", "Dialog", 0, QApplication::UnicodeUTF8));
        pB_explanatry->setText(QApplication::translate("aboutDlg", "\346\223\215\344\275\234\350\257\264\346\230\216", 0, QApplication::UnicodeUTF8));
        pB_about->setText(QApplication::translate("aboutDlg", "\345\205\263\344\272\216\350\275\257\344\273\266", 0, QApplication::UnicodeUTF8));
        pB_rule->setText(QApplication::translate("aboutDlg", "\346\270\270\346\210\217\350\247\204\345\210\231", 0, QApplication::UnicodeUTF8));
        text->setText(QString());
        title->setText(QString());
        Q_UNUSED(aboutDlg);
    } // retranslateUi

};

namespace Ui {
    class aboutDlg: public Ui_aboutDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDLG_H
