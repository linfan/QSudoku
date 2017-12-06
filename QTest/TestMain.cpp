#include <QtTest/QTest>
#include "TestMain.h"

TestMain::TestMain(QObject *parent)
    : QObject(parent) {
}


QTEST_APPLESS_MAIN( TestMain )
