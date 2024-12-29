#include "House.cpp"
#include <iostream>

using namespace std;

int main() {
    House H(3);
    cin >> H;
    cout << "Dien tich ngoi nha: " << H.areaOfHouse();
}