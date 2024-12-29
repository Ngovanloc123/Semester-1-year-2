#include <iostream>
#include "Vecto3D.cpp"

using namespace std;

int main() {
    Vector3D vector1(1, 2, 3);
    Vector3D vector2(4, 5, 6);
    cout << "So luong vector hien tai: ";
    Vector3D::printCount();
    cout << "\nDo dai khoang cach 2 vector1 va vector 2" << vector1.length(vector2) <<endl;

    {
        Vector3D v3;
        Vector3D::printCount();
    }
    Vector3D::printCount();
    return 0;
}