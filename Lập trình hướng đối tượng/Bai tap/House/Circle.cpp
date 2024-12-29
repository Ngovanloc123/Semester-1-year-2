#include "Circle.h"

Circle::Circle(double r)
{
    radius = r;
}

float Circle::area()
{
    return PI * radius * radius;
}
