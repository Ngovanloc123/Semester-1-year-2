#ifndef SET_h
#define SET_h

#include <iostream>

using namespace std;

class Set {
    int n;
    int *data;
    int size;
public:
    Set(int size = 20);
    Set(int n, int a[], int size = 20);
    Set(const Set &other);
    ~Set();
    Set operator + (int a);
    Set operator - (int a);
    Set operator + (const Set &other);
    Set operator - (const Set &other);
    Set operator * (const Set &other);
    bool operator () (int a) const;
    int operator [] (int index);
    Set &operator = (const Set &other);
    friend ostream &operator << (ostream &out, const Set & s);
};

#endif