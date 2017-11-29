/********************************************************************************
** Form generated from reading ui file 'explanatry.ui'
**
** Created: Wed Nov 18 22:56:28 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_EXPLANATRY_H
#define UI_EXPLANATRY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_explanatry
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *title;
    QLabel *text;
    QPushButton *pBL;
    QPushButton *pBR;
    QLabel *label_2;

    void setupUi(QDialog *explanatry)
    {
        if (explanatry->objectName().isEmpty())
            explanatry->setObjectName(QString::fromUtf8("explanatry"));
        explanatry->resize(442, 311);
        explanatry->setMinimumSize(QSize(442, 311));
        explanatry->setMaximumSize(QSize(442, 311));
        buttonBox = new QDialogButtonBox(explanatry);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(310, 250, 91, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        title = new QGroupBox(explanatry);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(30, 20, 381, 221));
        QFont font;
        font.setFamily(QString::fromUtf8("Andale Mono"));
        font.setPointSize(12);
        title->setFont(font);
        text = new QLabel(title);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(10, 30, 361, 131));
        QFont font1;
        font1.setPointSize(10);
        text->setFont(font1);
        pBL = new QPushButton(title);
        pBL->setObjectName(QString::fromUtf8("pBL"));
        pBL->setGeometry(QRect(40, 180, 71, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Andale Mono"));
        font2.setPointSize(10);
        pBL->setFont(font2);
        pBR = new QPushButton(title);
        pBR->setObjectName(QString::fromUtf8("pBR"));
        pBR->setGeometry(QRect(270, 180, 61, 28));
        pBR->setFont(font1);
        label_2 = new QLabel(explanatry);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 260, 261, 20));
        label_2->setTextFormat(Qt::AutoText);

        retranslateUi(explanatry);
        QObject::connect(buttonBox, SIGNAL(accepted()), explanatry, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), explanatry, SLOT(reject()));

        QMetaObject::connectSlotsByName(explanatry);
    } // setupUi

    void retranslateUi(QDialog *explanatry)
    {
        explanatry->setWindowTitle(QApplication::translate("explanatry", "Dialog", 0, QApplication::UnicodeUTF8));
        title->setTitle(QApplication::translate("explanatry", "[\346\223\215\344\275\234\350\257\264\346\230\216]", 0, QApplication::UnicodeUTF8));
        text->setText(QString());
        pBL->setText(QApplication::translate("explanatry", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pBR->setText(QApplication::translate("explanatry", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("explanatry", "[\350\275\257\344\273\266\350\256\276\350\256\241:BY\346\210\220\351\203\275\347\220\206\345\267\245\345\244\247\345\255\246 \346\236\227\345\270\206 \346\235\216\346\231\250 \350\256\270\346\225\217]", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(explanatry);
    } // retranslateUi

};

namespace Ui {
    class explanatry: public Ui_explanatry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPLANATRY_H
