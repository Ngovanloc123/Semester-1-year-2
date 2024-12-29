#ifndef HOUSE_h
#define HOUSE_h

#include <iostream>
#include "Room.h"
#include "Circle.cpp"
#include "Square.cpp"
#include "Triangle.cpp"
using namespace std;

class House{
    Room *room;
    int quantity;
public:
    House(int quantity);
    virtual ~House();
    friend istream &operator>>(istream &in, House &);
    float areaOfHouse();
};

#endif