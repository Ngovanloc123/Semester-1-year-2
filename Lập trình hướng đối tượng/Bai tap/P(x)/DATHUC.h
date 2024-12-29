#ifndef DATHUC_h
#define DATHUC_h

#include <iostream>

using namespace std;

class DATHUC {
    int n;
    int *data;
public:
    DATHUC(int n = 1);
    DATHUC(int n, int a[]);
    ~DATHUC();
    DATHUC operator+(const DATHUC &other);
    DATHUC operator-(const DATHUC &other);
    int operator()(int val);
    int &operator [](int index);
    DATHUC &operator = (const DATHUC &other); 
    friend istream& operator >> (istream &in, DATHUC &p);
    friend ostream& operator << (ostream &out, const DATHUC &p);
};

#endif