#ifndef LINKLIST_H
#define LINKLIST_H


// The position of table as (x,y)
struct Pos {
    int X, Y;
    Pos *up, *down;
};


// The Position Stack
class PosStack {
public:
    // "top" is not the most-top Pos, top->up=cap
    Pos *bottom, *top, *cur, *cap;
    int counts;

    PosStack();
    ~PosStack();
    void pop();
    void push(int x, int y);
};

#endif // LINKLIST_H
