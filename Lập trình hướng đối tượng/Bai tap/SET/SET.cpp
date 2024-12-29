#include "SET.h"
#include <algorithm>

Set::Set(int size) : n(0), data(new int[size]), size(size) {}

Set::Set(int n, int a[], int size) : data(new int[size]), size(size)
{
    this->n = 0;
    for(int i = 0; i < n; i++) {
        if(!(*this)(a[i])) data[this->n++] = a[i];
    }
}

Set::Set(const Set &other) : n(other.n), data(new int[other.n]), size(other.size)
{
    for(int i = 0; i < n; i++) data[i] = other.data[i];
}

Set::~Set()
{
    delete[] data;
}

Set Set::operator+(int a)
{
    if(n == size - 1) {
        cout << "Kich thuoc da dat toi da, khong the them phan tu vao!!\n";
        return *this;
    }

    if((*this)(a)) {
        return *this;
    }

    data[n++] = a;
    return *this;

}

Set Set::operator-(int a)
{
    if(n == 0) {
        cout << "Tap hop rong, khong the xoa phan tu!!\n";
        return *this;
    }
    if(!(*this)(a)) return *this;
    int i;
    for(i = 0; i < n; i++) {
        if(data[i] == a) break;
    }
    if(i == n - 1) n--;
    else {
        for(i; i < n - 1; i++) {
            data[i] = data[i + 1];
        }
        n--;
    }
    return *this;
}

Set Set::operator+(const Set &other)
{
    Set result(other);
    for(int i = 0; i < n; i++) {
        result = result + data[i];
    }
    return result;
}

Set Set::operator-(const Set &other)
{
    Set result(other);
    for(int i = 0; i < n; i++) {
        result = result - data[i];
    }
    return result;
}

Set Set::operator*(const Set &other)
{
    Set result(min(size, other.size));
    if(n == 0 || other.n == 0) return result;
    for(int i = 0; i < n; i++) {
        if(other(data[i])) {
            result = result + data[i];
        }
    }
    return result;
}

bool Set::operator()(int a) const
{
    for(int i = 0; i < n; i++) {
        if(data[i] == a) return true;
    }
    return false;
}

int Set::operator[](int index)
{
    return data[index];
}

Set &Set::operator=(const Set &other)
{
    if(this != &other) {
        delete[] data;
        n = other.n;
        data = new int[n];
        for(int i = 0; i < n; i++) data[i] = other.data[i];
    }
    return *this;
}

ostream &operator<<(ostream &out, const Set &s)
{
    for(int i = 0; i < s.n; i++) {
        out << s.data[i] << " ";
    }
    out << endl;
    return out;
} 
