#ifndef LinkList_h
#define LinkList_h

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkList {
    Node* head;
    Node* tail;
public:
    LinkList();
    ~LinkList();
    LinkList(LinkList &other);
    void insert_front(int x);
    void insert_back(int x);
    void insert_middle(Node* position, int x);
    void delete_front();
    void delete_back();
    void delete_middle(Node* position);
    friend ostream &operator << (ostream &out, const LinkList & L);
    void sort(bool CompFunction(int, int));
    Node* begin();
};

#endif