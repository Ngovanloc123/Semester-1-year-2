#ifndef LINKLIST_H
#define LINKLIST_H

#include "nhanvien.h"

template <typename T>
class LinkList {
private:
    struct Node {
        T* data;
        Node* next;
        Node(T* data) : data(data), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkList() : head(nullptr), size(0) {}

    void append(T* data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    int getSize() const {
        return size;
    }

    T* operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            temp->data->display();
            temp = temp->next;
        }
    }

    LinkList<T>& operator=(const LinkList<T>& other) {
        if (this == &other) return *this;
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        size = 0;
        Node* otherTemp = other.head;
        while (otherTemp) {
            append(otherTemp->data);
            otherTemp = otherTemp->next;
        }
        return *this;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }

        Node* temp = head;

        if (index == 0) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
        }

        size--;
    }

    ~LinkList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

#endif
