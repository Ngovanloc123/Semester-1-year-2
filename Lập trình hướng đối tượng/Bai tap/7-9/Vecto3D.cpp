#include <iostream>
#include "Vecto3D.h"
#include <math.h>

using namespace std;

int Vector3D::count = 0;

Vector3D::Vector3D()
{
    x = 0;
    y = 0;
    z = 0;
    count++;
}

Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    count++;
}

Vector3D::~Vector3D()
{
    count--;
}
void Vector3D::inputVector3D()
{
    cout << "Nhap toa do x: ";
    cin >> x;
    cout << "Nhap toa do y: ";
    cin >> y;
    cout << "Nhap toa do z: ";
    cin >> z;
}

double Vector3D::length(const Vector3D &v)
{
    return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
}

void Vector3D::printCount()
{
    cout << count << endl;
}
