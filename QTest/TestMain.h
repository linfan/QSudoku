#ifndef TEST_MAIN_H
#define TEST_MAIN_H

#include <QObject>

class TestMain : public QObject {
    Q_OBJECT
public:
    explicit TestMain(QObject *parent = 0);
private slots:
    // General
//    void initTestCase();    // call before the first test function
//    void cleanupTestCase(); // call after the last test function
//    void init();            // call before each test function
//    void cleanup();         // call after every test function
    // PopStack Test
    void should_able_to_push_and_pop_pos();
    void should_throw_exception_when_pop_stack_empty();
};

#endif // TEST_MAIN_H
