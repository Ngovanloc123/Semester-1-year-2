#pragma once
#include <iostream>
#include <exception>

using namespace std;

class Vector {
    int n;
    double *D;
public:
    Vector(int n = 1);
    ~Vector() { delete[] D; }
    Vector(const Vector& other);
    Vector operator + (const Vector& other);
    Vector operator - (const Vector& other);
    double operator * (const Vector& other);
    void operator = (const Vector& other);
    double &operator [] (int index); 
    friend istream& operator >> (istream &in, Vector &v);
    friend ostream& operator << (ostream &out, const Vector &v);
};