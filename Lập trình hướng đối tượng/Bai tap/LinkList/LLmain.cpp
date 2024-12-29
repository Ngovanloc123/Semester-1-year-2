#include <iostream>
#include "LinkList.cpp"

using namespace std;

int main() {
    LinkList l1;
    l1.insert_front(1);
    l1.insert_front(2);
    l1.insert_back(3);
    l1.insert_front(4);
    l1.insert_front(5);
    l1.insert_back(6);
    l1.insert_back(9);
    cout << "L1:\n";
    cout << l1;
    l1.delete_back();
    l1.delete_front();
    cout << "L1 sau khi xoa:\n";
    cout << l1;
    
    Node* node = l1.begin();
    node = node->next;
    l1.insert_middle(node, 10);
    cout << "L1 sau khi them giua List:\n";
    cout << l1;

    node = node->next->next;
    l1.delete_middle(node);
    cout << "L1 sau khi xoa giua List:\n";
    cout << l1;

    cout << "Sap sep tang dan: ";
    l1.sort(ascending);
    cout << l1;
    cout << "Sap sep giam dan: ";
    l1.sort(descending);
    cout << l1;
}