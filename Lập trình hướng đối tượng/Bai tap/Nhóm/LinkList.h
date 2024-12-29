#ifndef LINKLIST_H
#define LINKLIST_H

template <typename T>
class LinkList;

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;

    friend class LinkList<T>;

public:
    Node(T value) : data(value), next(nullptr) {}
    T getData() { return data;}
};

template <typename T>
class LinkList  {
private:
    Node<T>* head; 
    int size;
public: 
    LinkList();
    ~LinkList();
    int sizeList();
    Node<T>* insert(T value, Node<T>* pos);
    void erase(Node<T> *node);
    void display();
};


#endif
