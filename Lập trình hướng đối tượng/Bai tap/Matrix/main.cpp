#include <iostream>
#include "Matrix.cpp"

using namespace std;

int main() {
    Matrix A(3);
    cout << "Nhap ma tran A(3x3):\n";
    cin >> A;
    cout << "In ma tran A:\n";
    cout << A << endl;
    Matrix B(4);
    cout << "Nhap ma tran B(3x3):\n";
    cin >> B;
    cout << "In ma tran B:\n";
    cout << B << endl;
    cout << "Tong Cua A va B:\n";
    cout << A + B << endl;
    cout << "Hieu Cua A va B:\n";
    cout << A - B << endl;
    cout << "Tich Cua A va B:\n";
    cout << A * B << endl;
    cout << A(0, 1);
    
    // Matrix C(4);

}