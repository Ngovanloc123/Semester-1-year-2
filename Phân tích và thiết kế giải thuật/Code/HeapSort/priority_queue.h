#pragma once

#include <iostream>

using namespace std;

class priority_queue {
    int* arr;
    int length;
    int queue_size;
public:
    priority_queue(int size) : arr(new int[size]), length(size) {}
    ~priority_queue() { delete[] arr; }
    int parent(int i);
    void max_heapify(int node);
    void build_max_heap();
    void increase_key(int i, int key);
    bool is_empty() const { return queue_size == 0; }
    void push(int value);
    int pop();
    int top();
    void print() const;
};

