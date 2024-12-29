#ifndef Vecto3D_h
#define Vecto3D_h

class Vector3D {
private:
    double x, y, z;
    static int count;

public:
    Vector3D();
    Vector3D(double x, double y, double z);
    ~Vector3D();
    void inputVector3D();
    double length(const Vector3D &v);
    static void printCount();
};
#endif