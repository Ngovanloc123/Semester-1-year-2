#ifndef TRIANGLE_h
#define TRIANGLE_h

#include <iostream>
#include "Room.h"

class Triangle : public Room{
    double side;
public:
    Triangle(double s);
    float area();    
};

#endif