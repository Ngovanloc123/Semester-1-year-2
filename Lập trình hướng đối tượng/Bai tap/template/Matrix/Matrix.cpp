#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix(int n) {
    if(n <= 0 || n > 1000) {
        throw invalid_argument("Kich thuoc ma tran khong hop le!");
    }
    this->n = n;
    data = new T*[n];
    for(int i = 0; i < n; i++) {
        data[i] = new T[n];
        for(int j = 0; j < n; j++) data[i][j] = T();
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for(int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &other) {
    if(n!= other.n) {
        throw invalid_argument("Hai ma tran khong cùng kich thuoc!");
    }

    Matrix sum(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return sum;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &other) {
    if(n!= other.n) {
        throw invalid_argument("Hai ma tran khong cùng kich thuoc!");
    }

    Matrix diff(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            diff.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return diff;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &other) {
    if(n != other.n) {
        throw invalid_argument("Hai ma tran khong cùng kich thuoc!");
    }

    Matrix product(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            product.data[i][j] = T();
            for(int k = 0; k < n; k++) {
                product.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return product;
}

template <typename T>
T &Matrix<T>::operator()(int x, int y) {
    return data[x][y];
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix &other) {
    if(this != &other) {
        for(int i = 0; i < n; i++) {
            delete[] data[i];
        }
        delete[] data;

        n = other.n;
        data = new T*[n];
        for(int i = 0; i < n; i++) {
            data[i] = new T[n];
            for(int j = 0; j < n; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}