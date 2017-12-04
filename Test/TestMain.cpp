#include <QtTest/QtTest>
#include "../Logic/PosStack.h"

class TestMain: public QObject {
    Q_OBJECT
private slots:
    void toUpper();
};

void TestMain::toUpper() {
    PosStack* linkList = new PosStack();
    linkList->push(1, 2);
    linkList->push(3, 4);
    QCOMPARE(linkList->counts, 2);
    QCOMPARE(linkList->top->X, 3);
    QCOMPARE(linkList->top->Y, 4);
    linkList->pop();
    QCOMPARE(linkList->counts, 1);
    QCOMPARE(linkList->top->X, 1);
    QCOMPARE(linkList->top->Y, 2);
}

QTEST_MAIN(TestMain)
#include "TestMain.moc"
