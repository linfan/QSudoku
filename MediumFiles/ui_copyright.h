/********************************************************************************
** Form generated from reading ui file 'copyright.ui'
**
** Created: Wed Nov 18 22:56:28 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_COPYRIGHT_H
#define UI_COPYRIGHT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_copyright
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLabel *text;

    void setupUi(QDialog *copyright)
    {
        if (copyright->objectName().isEmpty())
            copyright->setObjectName(QString::fromUtf8("copyright"));
        copyright->resize(312, 388);
        copyright->setMinimumSize(QSize(312, 388));
        copyright->setMaximumSize(QSize(312, 388));
        buttonBox = new QDialogButtonBox(copyright);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(110, 290, 91, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label_2 = new QLabel(copyright);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 340, 261, 20));
        label_2->setTextFormat(Qt::AutoText);
        text = new QLabel(copyright);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(50, 30, 221, 241));

        retranslateUi(copyright);
        QObject::connect(buttonBox, SIGNAL(accepted()), copyright, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), copyright, SLOT(reject()));

        QMetaObject::connectSlotsByName(copyright);
    } // setupUi

    void retranslateUi(QDialog *copyright)
    {
        copyright->setWindowTitle(QApplication::translate("copyright", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("copyright", "[\350\275\257\344\273\266\350\256\276\350\256\241:BY\346\210\220\351\203\275\347\220\206\345\267\245\345\244\247\345\255\246 \346\236\227\345\270\206 \346\235\216\346\231\250 \350\256\270\346\225\217]", 0, QApplication::UnicodeUTF8));
        text->setText(QString());
        Q_UNUSED(copyright);
    } // retranslateUi

};

namespace Ui {
    class copyright: public Ui_copyright {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COPYRIGHT_H
