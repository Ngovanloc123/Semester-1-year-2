#include <iostream>
#include "Matrix.cpp"

using namespace std;

int main() {
    try {
        int n; cout << "Nhap kich thuoc ma tran: "; cin >> n;
        Matrix<int> A(n);
        cout << "Nhap ma tran A(3x3):\n";
        cin >> A;
        cout << "In ma tran A:\n";
        cout << A << endl;
        Matrix<int> B(3);
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
        cout << "Gia tri A[0][1]: " << A(0, 1) << endl;
        
        Matrix<float> C(2);
        
        cout << "Nhap ma tran C(2x2):\n";
        cin >> C;
        cout << "In ma tran C:\n";
        cout << C << endl;
    }
    catch(invalid_argument& e) {
        cout << "\nError: " << e.what() << endl;
    }

}