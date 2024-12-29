#include "Heap.h"

Heap::Heap(int size) : length(size) , arr(new int[size]){}

Heap::~Heap() {
    delete[] arr;
}

int Heap::parent(int node)
{
    return (node - 1) / 2;
}

bool Heap::is_empty()
{
    return heap_size == 0;
}

void Heap::max_heapify(int node)
{
    int largest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;
    
    if (left < heap_size && arr[left] > arr[largest])
        largest = left;
    
    if (right < heap_size && arr[right] > arr[largest])
        largest = right;
    
    if (largest != node) {
        int t = arr[largest];
        arr[largest] = arr[node];
        arr[node] = t;
        max_heapify(largest);
    }
}

void Heap::build_max_heap()
{
    for (int i = heap_size / 2 - 1; i >= 0; i--)
        max_heapify(i);
}

void Heap::heapSort()
{
    build_max_heap();
    int t = heap_size;
    for (int i = heap_size - 1; i > 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heap_size--;
        max_heapify(0);
    }
    heap_size = t;
}

void Heap::increase_key(int i, int key)
{
    if (key < arr[i]) {
        cout << "New key is smaller than current key!\n";
        return;
    }
    
    arr[i] = key;
    while (i > 0 && arr[parent(i)] < arr[i]) {
        int t = arr[i];
        arr[i] = arr[parent(i)];
        arr[parent(i)] = t;
        i = parent(i);
    }
}

void Heap::insert(int value)
{
    if (heap_size == length) {
        cout << "Heap overflow!\n";
        return;
    }
    
    arr[heap_size] = INT_MIN;
    increase_key(heap_size, value);
    heap_size++;
}

int Heap::extract_max()
{
    if (is_empty()) {
        std::cout << "Heap underflow!\n";
        return INT_MIN;
    }
    
    int max_value = arr[0];
    arr[0] = arr[heap_size - 1];
    heap_size--;
    max_heapify(0);
    return max_value;
}

int Heap::get_max()
{
    if (is_empty()) {
        cout << "Heap is empty!\n";
        return INT_MIN;
    }
    
    return arr[0];
}

void Heap::display()
{
    if (is_empty()) {
        std::cout << "Heap is empty!\n";
        return;
    }
    
    for (int i = 0; i < heap_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
