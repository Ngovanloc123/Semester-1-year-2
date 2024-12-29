#ifndef SQUARE_h
#define SQUARE_h

#include "Room.h"

class Square : public Room{
    double side;
public:
    Square(double s);
    float area();    
};

#endif