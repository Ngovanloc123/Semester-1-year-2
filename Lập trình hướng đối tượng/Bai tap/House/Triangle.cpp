#include "Triangle.h"

Triangle::Triangle(double s)
{
    side = s;
}

float Triangle::area()
{
    return side * side * 1.732 / 4;
}
