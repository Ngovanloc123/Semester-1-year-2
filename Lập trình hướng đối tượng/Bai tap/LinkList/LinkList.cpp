#include "LinkList.h"

void swap(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}

bool ascending(int left, int right) {
    return left > right;
}

bool descending(int left, int right) {
    return left < right;
}

LinkList::LinkList() : head(NULL), tail(NULL) {}

LinkList::~LinkList()
{
    Node *current = head;
    Node *nextNode;
    while(current != NULL) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

LinkList::LinkList(LinkList &other)
{
    Node *current = other.head;
    if(current == NULL) {
        head = NULL;
        tail = NULL;
        return;
    }
    while(current != NULL) {
        Node *newNode = new Node();
        newNode->data = current->data;
        newNode->next = current->next;
        current = current->next;
    }
}

void LinkList::insert_front(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    if(tail == NULL) tail = newNode;
}

void LinkList::insert_back(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}
void LinkList::insert_middle(Node *position, int x)
{
    if(position == NULL) return;
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = position->next;
    position->next = newNode;
    if(position == tail) tail = newNode;
}

void LinkList::delete_front()
{
    if(head == NULL) return;

    if(head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node *front = head;
    head = head->next;
    delete front;
}

void LinkList::delete_back()
{
    if(tail == NULL) return;


    if(head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    // Tìm phần tử kế cuối
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    // Xóa phần tử cuối
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void LinkList::delete_middle(Node *position)
{
    if(position == NULL || position->next == NULL) return;

    Node* temp = position->next;
    position->next = temp->next;
    delete temp;

}

void LinkList::sort(bool CompFunction(int, int))
{
    Node *nodei = head;
    Node *nodej;
    while(nodei != NULL) {
        nodej = nodei->next;
        while(nodej != NULL) {
            if(CompFunction(nodei->data, nodej->data)) swap(nodei->data, nodej->data);
            nodej = nodej->next;
        }
        nodei = nodei->next;
    }
}

Node *LinkList::begin()
{
    return head;
}

ostream &operator<<(ostream &out, const LinkList &L)
{
    Node *current = L.head;
    while(current != NULL){
        out << current->data << " ";
        current = current->next;
    }
    out << endl;
    return out;
}
