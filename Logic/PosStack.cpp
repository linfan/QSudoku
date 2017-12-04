#include "PosStack.h"

#define NULL 0

PosStack::PosStack() {
    counts = 0;
    bottom = new Pos;
    cap = new Pos;
    bottom->up = cap;
    bottom->down = NULL;
    cap->up = NULL;
    cap->down = NULL; // Will be initialize when push
    top = cur = bottom;
}

PosStack::~PosStack() {
    while (bottom != top) {
        PosStack::pop();
    }
    delete bottom;
    delete cap;
}

void PosStack::push(int x, int y) {
    cur = top;
    top = new Pos;
    top->X = x;
    top->Y = y;
    top->up = cap;
    cap->down = top;
    top->down = cur;
    cur->up = top;
    counts++;
}

void PosStack::pop() {
    cur = top->down;
    delete top;
    cur->up = cap;
    top = cur;
    counts--;
}

