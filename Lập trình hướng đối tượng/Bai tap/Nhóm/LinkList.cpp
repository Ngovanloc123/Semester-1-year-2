#include "LinkList.h"
#include <iostream>
#include <exception>

using namespace std;

template <typename T>
inline LinkList<T>::LinkList() : head(NULL)
{
    size = 0;
}

template <typename T>
LinkList<T>::~LinkList()
{
    Node<T>* curr = head;
    Node<T>* nextNode;
    while (curr != NULL) {
        nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}

template <typename T>
int LinkList<T>::sizeList()
{
    return size;
}

template <typename T>
Node<T>* LinkList<T>::insert(T value, Node<T>* pos)
{
    Node<T>* newNode = new Node<T>(value);
    if (head == NULL) {
        head = newNode;
        size++;
        return newNode;
    }

    newNode->next = pos->next;
    pos->next = newNode;

    size++;
    return newNode;
}

template <typename T>
void LinkList<T>::erase(Node<T>* node)
{
    if (node == NULL) {  // Kiểm tra nếu node là NULL
        throw invalid_argument("Node to be deleted is null.");
    }

    if (head == NULL) {  // Nếu danh sách đang rỗng
        throw underflow_error("Cannot delete from an empty list.");
    }

    Node<T>* curr = head;
    Node<T>* previous = NULL;

    while (curr != NULL) {
        if (curr == node) {  // Nếu tìm thấy node cần xóa
            if (previous == NULL) {  // Node đang xét là node đầu tiên
                head = curr->next;
            } else {
                previous->next = curr->next;
            }
            delete curr;
            size--;
            return;
        }
        previous = curr;
        curr = curr->next;
    }

    throw runtime_error("Node not found in the list.");  // Nếu không tìm thấy node
}

template <typename T>
void LinkList<T>::display()
{
    if (head == NULL) {
        cerr << "Error: List is empty." << endl;
        return;
    }
    Node<T>* curr = head;
    while(curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
