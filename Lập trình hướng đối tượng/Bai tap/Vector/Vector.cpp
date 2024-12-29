#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector(int n)
{
    if(n == 0) {
        throw invalid_argument("Kich thuoc khong hop le!");
    }
    this->n = n;
    D = new double[n];
}

Vector::Vector(const Vector &other) : n(other.n), D(new double[other.n])
{
    for (int i = 0; i < n; ++i) {
        D[i] = other.D[i];
    }
}

Vector Vector::operator + (const Vector &other)
{
    if(n != other.n) {
        throw invalid_argument("Hai Vector khong cung so chieu");
    }
    Vector sum(n);
    for (int i = 0; i < n; ++i) {
        sum.D[i] = D[i] + other.D[i];
    }
    return sum;
}

Vector Vector::operator - (const Vector &other)
{
    if(n != other.n) {
        throw invalid_argument("Hai Vector khong cung so chieu");
    }
    Vector diff(n);
    for (int i = 0; i < n; ++i) {
        diff.D[i] = D[i] - other.D[i];
    }
    return diff;
}

double Vector::operator*(const Vector &other)
{
    if(n != other.n) {
        throw invalid_argument("Hai Vector khong cung so chieu");

    }
    double result = 0;
    for (int i = 0; i < n; ++i) {
        result += D[i] * other.D[i];
    }
    return result;
}

void Vector::operator=(const Vector &other)
{
    if (this != &other) {
        delete[] D;

        n = other.n;
        D = new double[n];

        for (int i = 0; i < n; ++i) {
            D[i] = other.D[i];
        }
    }
}

double &Vector::operator[](int index)
{
    if (index < 0 || index >= n) {
        throw out_of_range("Vi tri ngoai Vector!");
    }
    return D[index];
}


istream &operator>>(istream &in, Vector &v)
{
    cout << "Nhap cac phan tu cho Vector co so chieu "<< v.n <<" : \n";
    for(int i = 0; i < v.n; ++i) 
        in >> v.D[i];
    return in;
}

ostream &operator<<(ostream &out, const Vector &v)
{
    out << "[";
    for(int i = 0; i < v.n - 1; ++i) {
        out << v.D[i] << "; ";
    }
    out << v.D[v.n - 1] << "]";
    out << endl;
    return out;
}

