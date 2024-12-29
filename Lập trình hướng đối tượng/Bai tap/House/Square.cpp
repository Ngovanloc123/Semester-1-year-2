#include "Square.h"

Square::Square(double s)
{
    side = s;
}

float Square::area()
{
    return side * side;
}
