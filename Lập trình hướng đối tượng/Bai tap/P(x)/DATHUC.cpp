#include "DATHUC.h"
#include <algorithm>
#include <cmath>


DATHUC::DATHUC(int n) : n(n) {
    data =  new int[n + 1];
}

DATHUC::DATHUC(int n, int a[]) : n(n)
{
    data = new int[n];
    for (int i = 0; i <= n; i++)
        data[i] = a[i];
}

DATHUC::~DATHUC()
{
    delete[] data;
}

DATHUC DATHUC::operator + (const DATHUC &other)
{
    int max_n = max(n, other.n);
    DATHUC sum(max_n);
    for(int i = 0; i <= max_n; i++) {
        sum.data[i] = 0;
        if(i <= n) sum.data[i] +=data[i];
        if(i <= other.n) sum.data[i] += other.data[i];
    }
    return sum;
}

DATHUC DATHUC::operator - (const DATHUC &other)
{
    int max_n = max(n, other.n);
    DATHUC sum(max_n);
    for(int i = 0; i <= max_n; i++) {
        sum.data[i] = 0;
        if(i <= n) sum.data[i] = data[i];
        if(i <= other.n) sum.data[i] -= other.data[i];
    }
    return sum;
}

int DATHUC::operator()(int val)
{
    int result = 0;
    for(int i = 0; i <= n; i++) result += data[i] * pow(val, i);
    return result;
}

int &DATHUC::operator[](int index)
{
    return data[index];
}

DATHUC &DATHUC::operator=(const DATHUC &other)
{
    if(this == &other) return *this;
    delete[] data;
    n = other.n;
    data = new int[n + 1];
    for(int i = 0; i <= n; i++) data[i] = other.data[i];
    return *this;
}

istream &operator>>(istream &in, DATHUC &p)
{
    cout << "Nhap da thuc bac " << p.n << ":\n";
    for(int i = 0; i <= p.n; i++) in >> p.data[i];
    return in;
}

ostream &operator<<(ostream &out, const DATHUC &p)
{
    for(int i = 0; i <= p.n; i++) {
        if(p.data[i] != 0) {
            if(i == 0) out <<  p.data[i]; 
            else cout << " + " << p.data[i] << "x^" << i; 
        }
    }
    return out;
}
