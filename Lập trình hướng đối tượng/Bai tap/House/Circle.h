#ifndef CIRCLE_h
#define CIRCLE_h

#include "Room.h"

const float PI = 3.141;

class Circle : public Room{
    double radius;
public:
    Circle(double r);
    float area();    
};

#endif