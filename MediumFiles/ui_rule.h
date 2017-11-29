/********************************************************************************
** Form generated from reading ui file 'rule.ui'
**
** Created: Thu Nov 19 18:45:52 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RULE_H
#define UI_RULE_H

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

class Ui_rule
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *title;
    QLabel *textB;
    QPushButton *pBL;
    QPushButton *pBR;
    QLabel *textL;
    QLabel *textR;
    QLabel *label_2;

    void setupUi(QDialog *rule)
    {
        if (rule->objectName().isEmpty())
            rule->setObjectName(QString::fromUtf8("rule"));
        rule->resize(554, 433);
        rule->setMinimumSize(QSize(554, 433));
        rule->setMaximumSize(QSize(554, 433));
        buttonBox = new QDialogButtonBox(rule);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(380, 380, 91, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        title = new QGroupBox(rule);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(30, 30, 491, 341));
        textB = new QLabel(title);
        textB->setObjectName(QString::fromUtf8("textB"));
        textB->setGeometry(QRect(0, 30, 481, 241));
        pBL = new QPushButton(title);
        pBL->setObjectName(QString::fromUtf8("pBL"));
        pBL->setGeometry(QRect(20, 290, 61, 28));
        pBR = new QPushButton(title);
        pBR->setObjectName(QString::fromUtf8("pBR"));
        pBR->setGeometry(QRect(400, 290, 61, 28));
        textL = new QLabel(title);
        textL->setObjectName(QString::fromUtf8("textL"));
        textL->setGeometry(QRect(10, 30, 245, 245));
        textL->setMinimumSize(QSize(245, 245));
        textL->setMaximumSize(QSize(245, 245));
        textR = new QLabel(title);
        textR->setObjectName(QString::fromUtf8("textR"));
        textR->setGeometry(QRect(260, 30, 221, 241));
        textR->setScaledContents(false);
        label_2 = new QLabel(rule);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 390, 261, 20));
        label_2->setTextFormat(Qt::AutoText);

        retranslateUi(rule);
        QObject::connect(buttonBox, SIGNAL(accepted()), rule, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), rule, SLOT(reject()));

        QMetaObject::connectSlotsByName(rule);
    } // setupUi

    void retranslateUi(QDialog *rule)
    {
        rule->setWindowTitle(QApplication::translate("rule", "Dialog", 0, QApplication::UnicodeUTF8));
        title->setTitle(QApplication::translate("rule", "[\346\270\270\346\210\217\350\247\204\345\210\231]", 0, QApplication::UnicodeUTF8));
        textB->setText(QString());
        pBL->setText(QApplication::translate("rule", "\344\270\212\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        pBR->setText(QApplication::translate("rule", "\344\270\213\344\270\200\351\241\265", 0, QApplication::UnicodeUTF8));
        textL->setText(QString());
        textR->setText(QString());
        label_2->setText(QApplication::translate("rule", "[\350\275\257\344\273\266\350\256\276\350\256\241:BY\346\210\220\351\203\275\347\220\206\345\267\245\345\244\247\345\255\246 \346\236\227\345\270\206 \346\235\216\346\231\250 \350\256\270\346\225\217]", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(rule);
    } // retranslateUi

};

namespace Ui {
    class rule: public Ui_rule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULE_H
