
#include <iostream>
#include "Vector.cpp"

using namespace std;

int main() {
    try{
        Vector v1(5);
        cout << "Nhap Vector v1:\n";
        cin >> v1;

        cout << "Phan tu cua Vector v1 tai vi tri thu 3: ";
        cout << v1[6];
        cout << endl;

        Vector v2(4);
        cout << "Nhap Vector v2:\n";
        cin >> v2;

        cout << "Tong hai Vector v1, v2:\n";
        cout << v1 + v2 << endl;

        cout << "Hieu hai Vector v1, v2:\n";
        cout << v1 - v2 << endl;

        cout << "Tich vo huong cua v1, v2:\n";
        cout << v1 * v2 << endl;
    }
    catch(invalid_argument& e) {
        cout << "\nError: " << e.what() << endl;
    }
    catch(out_of_range& e) {
        cout << "\nError: " << e.what() << endl;
    }


}