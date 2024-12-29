#pragma once

#define EMPTY_POS -1

class Stack {
private:
    unsigned int capacity;
    int tos;
    int *array;
public:
    Stack(int capacity);
    ~Stack();
    Stack(const Stack& other);
    void push(const int &value);
    void pop();
    int top();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
};