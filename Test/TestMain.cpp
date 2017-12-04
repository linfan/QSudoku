#include <QtTest/QtTest>

class TestMain : public QObject {
    Q_OBJECT
private slots:
    void should_able_to_push_and_pop_pos();
};

#include "PosStackTest.h"

QTEST_MAIN(TestMain)
#include "TestMain.moc"
