#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class Matrix {
    int n;
    T **data;
public:
    Matrix(int n = 2);
    ~Matrix();
    Matrix operator+(const Matrix &other);
    Matrix operator-(const Matrix &other);
    Matrix operator*(const Matrix &other);
    T &operator()(int x, int y);
    Matrix &operator=(const Matrix &other); 
    friend istream& operator>>(istream &in, Matrix &p) {
        for (int i = 0; i < p.n; i++) {
            for (int j = 0; j < p.n; j++) {
                in >> p.data[i][j];
            }
        }
        return in;
    }
    friend ostream& operator<<(ostream &out, const Matrix &p) {
        for (int i = 0; i < p.n; i++) {
            for (int j = 0; j < p.n; j++) {
                out << p.data[i][j] << "\t";
            }
            out << endl;
        }
        return out;
    }
};

#endif