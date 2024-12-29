#pragma once
#include <iostream>

using namespace std;

class Heap {
    int length;
    int heap_size;
    int* arr;
public:
    Heap(int size);
    ~Heap();
    int parent(int node);
    bool is_empty();
    void max_heapify(int node);
    void build_max_heap();
    void heapSort();
    // priority queue
    void increase_key(int i, int key);
    void insert(int value);
    int extract_max();
    int get_max();
    void display();
};