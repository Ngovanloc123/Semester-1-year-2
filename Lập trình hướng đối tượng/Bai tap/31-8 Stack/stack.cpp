#include "stack.h"
#include <iostream>

using namespace std;

#define EMPTY_POS -1
#define EMPTY_VALUE 0

Stack::Stack(int capacity)
{
    this->capacity = capacity;
    tos = EMPTY_POS;
    array = new int[capacity];
}

Stack::~Stack()
{
    delete[] array;
}

Stack::Stack(const Stack &other)
{
    capacity = other.capacity;
    tos = other.tos;
    array = new int[capacity];
    for (int i = 0; i <= tos; i++) {
        array[i] = other.array[i];
    }
}

void Stack::push(const int &value)
{
    if (isFull()) {
        cout << "Stack is full!" << endl;
        return;
    }
    array[++tos] = value;
}

void Stack::pop()
{
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    tos--;
}

int Stack::top()
{
    if(isEmpty()) {
        cout << "Stack is full!" << endl;
        return EMPTY_VALUE;
    }
    return array[tos];
}

bool Stack::isEmpty()
{
    return tos == EMPTY_POS;
}

bool Stack::isFull()
{
    return tos == capacity - 1;
}

int Stack::size()
{
    return tos + 1;
}

void Stack::display()
{
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    const char* hex = "0123456789ABCDEF";
    for (int i = tos; i >= 0; i--) {
        cout << hex[array[i]];
    }
    cout << endl;
}
