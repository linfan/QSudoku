#include "../Logic/PosStack.h"

void TestMain::should_able_to_push_and_pop_pos() {
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
    linkList->pop();
    QCOMPARE(linkList->counts, 0);
}
