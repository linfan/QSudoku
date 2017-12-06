#include <QtTest/QTest>
#include "TestMain.h"
#include "../Logic/PosStack.h"

// See [http://doc.qt.io/qt-5/qtest.html#macros] for more macros

void TestMain::should_able_to_push_and_pop_pos() {
    PosStack* stack = new PosStack();
    stack->push(1, 2);
    stack->push(3, 4);
    QCOMPARE(stack->counts, 2);
    QCOMPARE(stack->top->X, 3);
    QCOMPARE(stack->top->Y, 4);
    stack->pop();
    QCOMPARE(stack->counts, 1);
    QCOMPARE(stack->top->X, 1);
    QCOMPARE(stack->top->Y, 2);
    stack->pop();
    QCOMPARE(stack->counts, 0);
}

void TestMain::should_throw_exception_when_pop_stack_empty() {
    PosStack* stack = new PosStack();
    stack->push(1, 2);
    stack->pop();
    QVERIFY_EXCEPTION_THROWN(stack->pop(), QString);
}
