#ifndef LINKLIST_H
#define LINKLIST_H


//The Node Define
class ListNode
{
    public:
    int L,R;//The Position Of Table As (x,y)
    ListNode *next,*prov;
};


//The Link Define
class LinkList
{
    public:
    int counts;
    ListNode *head,*tail,*cur,*end;
    //"tail"is not the end Node,tail->next=end

    LinkList();
    ~LinkList();
    void Pop();
    void Push(int LL,int RR);
};

#endif // LINKLIST_H
