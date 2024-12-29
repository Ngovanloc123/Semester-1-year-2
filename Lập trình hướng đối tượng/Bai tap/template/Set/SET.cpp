#include "SET.h"

template <typename T>
Set<T>::Set(int size) : n(0), data(new T[size]), size(size) {}

template <typename T>
Set<T>::Set(int n, T a[], int size) : data(new T[size]), size(size) {
    this->n = 0;
    for (int i = 0; i < n; i++) {
        if (!(*this)(a[i])) {
            data[this->n++] = a[i];
        }
    }
    sort(data, data + n);
}

template <typename T>
Set<T>::Set(const Set &other) : n(other.n), data(new T[other.size]), size(other.size) {
    for (int i = 0; i < n; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Set<T>::~Set() {
    delete[] data;
}

template <typename T>
Set<T> Set<T>::operator+(T a) {
    if (n == size) {
        cout << "Kich thuoc da dat toi da, khong the them phan tu vao!!\n";
        return *this;
    }
    if ((*this)(a)) {
        return *this;
    }
    data[n++] = a;
    sort(data, data + n);
    return *this;
}

template <typename T>
Set<T> Set<T>::operator-(T a) {
    if (n == 0) {
        cout << "Tap hop rong, khong the xoa phan tu!!\n";
        return *this;
    }
    if (!(*this)(a)) return *this;

    int i;
    for (i = 0; i < n; i++) {
        if (data[i] == a) break;
    }
    if (i == n - 1) {
        n--;
    } else {
        for (; i < n - 1; i++) {
            data[i] = data[i + 1];
        }
        n--;
    }
    return *this;
}

template <typename T>
Set<T> Set<T>::operator+(const Set &other) {
    Set result(other);
    for (int i = 0; i < n; i++) {
        result = result + data[i];
    }
    sort(data, data + n);
    return result;
}

template <typename T>
Set<T> Set<T>::operator-(const Set &other) {
    Set result(other);
    for (int i = 0; i < n; i++) {
        result = result - data[i];
    }
    return result;
}

template <typename T>
Set<T> Set<T>::operator*(const Set &other) {
    Set result(min(size, other.size));
    if (n == 0 || other.n == 0) return result;
    for (int i = 0; i < n; i++) {
        if (other(data[i])) {
            result = result + data[i];
        }
    }
    return result;
}

template <typename T>
bool Set<T>::operator()(T a) const {
    for (int i = 0; i < n; i++) {
        if (data[i] == a) return true;
    }
    return false;
}

template <typename T>
T Set<T>::operator[](int index) {
    return data[index];
}

template <typename T>
Set<T> &Set<T>::operator=(const Set &other) {
    if (this != &other) {
        delete[] data;
        n = other.n;
        size = other.size;
        data = new T[size];
        for (int i = 0; i < n; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}