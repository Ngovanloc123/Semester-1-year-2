#include <iostream>
#include "Heap.cpp"
#include "priority_queue.cpp"

using namespace std;

int main() {
    // Heap h(100);
    // h.insert(0);
    // h.insert(3);
    // h.insert(5);
    // h.insert(1);
    // h.insert(10);
    // h.insert(8);
    // h.insert(23);
    // h.insert(25);
    // h.insert(36);
    // h.insert(74);
    // h.insert(20);
    // h.insert(56);
    // h.insert(14);
    // h.insert(3);
    // h.display();
    // h.insert(15);
    // h.display();
    priority_queue pq(100);
    pq.push(0);
    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(8);
    pq.push(23);
    pq.push(25);
    pq.push(36);
    pq.push(74);
    pq.push(20);
    pq.push(56);
    pq.print();
    cout << pq.top();
    pq.pop();
    cout << endl;
    cout << pq.top();
    pq.push(100);
    cout << pq.top();

}