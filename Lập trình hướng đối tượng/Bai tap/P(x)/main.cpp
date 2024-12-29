// #include <iostream>
#include "DATHUC.cpp"

using namespace std;

int main() {
    DATHUC P1(3);
    cin >> P1;
    cout << P1 << endl;
    cout << "Da thuc P1: " << P1 << endl;
    cout << "He so mang so mu 2 la: ";
    cout << P1[2];
    cout << endl;
    DATHUC P2(4);
    cin >> P2;
    cout << "Da thuc P2: " << P2 << endl;
    DATHUC P3 = P1 + P2;
    cout << "Tong P1 + P2: " << P3 << endl;
    DATHUC P4 = P1 - P2;
    cout << "Hieu P1 - P2: " << P4 << endl;
    DATHUC P5(P2);
    cout << "Da thuc P3 = P2: " << P5 << endl;
    P5[2] = 5;
    cout << "Da thuc P3 sau khi thay doi he so mang so mu 2: " << P5 << endl;
    
}