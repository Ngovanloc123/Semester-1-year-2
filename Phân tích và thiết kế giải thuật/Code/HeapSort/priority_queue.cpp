#include "priority_queue.h"

int priority_queue::parent(int i)
{
    return (i - 1) / 2;
}

void priority_queue::max_heapify(int node)
{
    int largest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;
    
    if (left < queue_size && arr[left] > arr[largest])
        largest = left;
    
    if (right < queue_size && arr[right] > arr[largest])
        largest = right;
    
    if (largest != node) {
        int t = arr[largest];
        arr[largest] = arr[node];
        arr[node] = t;
        max_heapify(largest);
    }
}

void priority_queue::build_max_heap()
{
    for (int i = (queue_size - 2) / 2; i >= 0; i--)
        max_heapify(i);
}

void priority_queue::increase_key(int i, int key)
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

void priority_queue::push(int value)
{
    if (queue_size == length) {
        cout << "Priority queue is full. Cannot push " << value << endl;
        return;
    }
    
    queue_size++;
    arr[queue_size - 1] = INT_MIN;
    increase_key(queue_size - 1, value);
}

int priority_queue::pop()
{
    if (queue_size == 0) {
        cout << "Priority queue is empty. Cannot pop!\n";
        return INT_MIN;
    }
    
    int max_value = arr[0];
    arr[0] = arr[queue_size - 1];
    queue_size--;
    max_heapify(0);
    return max_value;
}

int priority_queue::top()
{
    if (queue_size == 0) {
        cout << "Priority queue is empty. Cannot get top!\n";
        return INT_MIN;
    }
    
    return arr[0];
}

void priority_queue::print() const
{
    for (int i = 0; i < queue_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
