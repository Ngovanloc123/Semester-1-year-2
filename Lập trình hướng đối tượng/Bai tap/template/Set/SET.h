#ifndef SET_H
#define SET_H

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class Set {
    int n;
    T *data;
    int size;
public:
    Set(int size = 20);
    Set(int n, T a[], int size = 20);
    Set(const Set &other);
    ~Set();
    Set operator+(T a);
    Set operator-(T a);
    Set operator+(const Set &other);
    Set operator-(const Set &other);
    Set operator*(const Set &other);
    bool operator()(T a) const;
    T operator[](int index);
    Set &operator=(const Set &other);
    friend ostream &operator<<(ostream &out, const Set &s) {
        for (int i = 0; i < s.n; i++) {
            out << s.data[i] << " ";
        }
        out << endl;
        return out;
    }
};

#endif