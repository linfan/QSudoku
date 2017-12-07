#include "gtest/gtest.h"
#include "../Logic/PosStack.h"
#include <QString>

using namespace testing;

class PopStackTest : public Test {

protected:

    // 每个测试用例开始时运行
    virtual void SetUp() {
        stack = new PosStack();
    }

    // 每个测试用例结束时运行
    virtual void TearDown() {
        delete stack;
    }

    // 在测试中会使用到的成员变量
    PosStack* stack;
};


TEST_F(PopStackTest, should_able_to_push_and_pop_pos) {
    stack->push(1, 2);
    stack->push(3, 4);
    EXPECT_EQ(stack->counts, 2);
    EXPECT_EQ(stack->top->X, 3);
    EXPECT_EQ(stack->top->Y, 4);
    stack->pop();
    EXPECT_EQ(stack->counts, 1);
    EXPECT_EQ(stack->top->X, 1);
    EXPECT_EQ(stack->top->Y, 2);
    stack->pop();
    EXPECT_EQ(stack->counts, 0);
}

TEST_F(PopStackTest, should_throw_exception_when_pop_stack_empty) {
    stack->push(1, 2);
    stack->pop();
    EXPECT_THROW(stack->pop(), QString);
}

