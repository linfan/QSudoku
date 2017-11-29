#include "linkList.h"

#define NULL 0

LinkList::LinkList() {
    counts = 0;
    head = new ListNode;
    end = new ListNode;
    head->next = end;
    head->prov = NULL;
    end->next = NULL;
    end->prov = NULL;//Will Be Init When Push
    tail = cur = head;
}

LinkList::~LinkList() {
    while (head != tail) {
        LinkList::Pop();
    }
    delete head;
    delete end;
}

void LinkList::Push(int LL, int RR) {
    cur = tail;
    tail = new ListNode;
    tail->L = LL;
    tail->R = RR;
    tail->next = end;
    end->prov = tail;
    tail->prov = cur;
    cur->next = tail;
    counts++;
}

void LinkList::Pop() {
    cur = tail->prov;
    delete tail;
    cur->next = end;
    tail = cur;
    counts--;
}

