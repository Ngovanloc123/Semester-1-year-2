#ifndef Matrix_h
#define Matrix_h

#include <iostream>

using namespace std;

class Matrix {
    int n;
    int **data;
public:
    Matrix(int n = 2);
    ~Matrix();
    Matrix operator+(const Matrix &other);
    Matrix operator-(const Matrix &other);
    Matrix operator*(const Matrix &other);
    int &operator()(int x, int y);
    Matrix &operator = (const Matrix &other); 
    friend istream& operator >> (istream &in, Matrix &p);
    friend ostream& operator << (ostream &out, const Matrix &p);
};

#endif