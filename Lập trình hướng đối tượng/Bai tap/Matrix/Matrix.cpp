#include "Matrix.h"

Matrix::Matrix(int n) : n(n)
{
    data = new int*[n];
    for (int i = 0; i < n; i++) {
        data[i] = new int[n];
        for(int j = 0; j < n; j++) data[i][j] = 0;
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;
}

Matrix Matrix::operator+(const Matrix &other)
{
    Matrix sum(n);
    if (n!= other.n) {
        cout << "Hai ma tran khong cùng kich thuoc!!!\n";
        return sum;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return sum;
}

Matrix Matrix::operator-(const Matrix &other)
{
    Matrix diff(n);
    if (n!= other.n) {
        cout << "Hai ma tran khong cùng kich thuoc!!!\n";
        return diff;
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            diff.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return diff;
}

Matrix Matrix::operator*(const Matrix &other)
{
    Matrix product(n);
    if (n!= other.n) {
        cout << "Hai ma tran khong cung kich thuoc!!!\n";
        return product;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            product.data[i][j] = 0;
            for (int k = 0; k < n; k++) {
                product.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return product;
    
}

int &Matrix::operator()(int x, int y)
{
    return data[x][y];
}

Matrix &Matrix::operator = (const Matrix &other)
{
    if (this != &other) {
        for (int i = 0; i < n; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    n = other.n;
    data = new int*[n];
    for (int i = 0; i < n; i++) {
        data[i] = new int[n];
        for (int j = 0; j < n; j++) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}


istream &operator >> (istream &in, Matrix &p)
{
    for (int i = 0; i < p.n; i++) {
        for (int j = 0; j < p.n; j++) {
            in >> p.data[i][j];
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const Matrix &p)
{
    for (int i = 0; i < p.n; i++) {
        for (int j = 0; j < p.n; j++) {
            out << p.data[i][j] << " ";
        }
        out << endl;
    }
    return out;
}
