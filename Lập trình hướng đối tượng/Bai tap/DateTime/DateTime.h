#ifndef DateTime_h
#define DateTime_h
#include "Date.h"
#include "Time.h"
#include <iostream>
using namespace std;

class DateTime : public Date, public Time {
public:
    DateTime(int = 1, int = 1, int = 2024, int = 0, int = 0, int = 0);
    DateTime &operator++();
    DateTime &operator--();
    friend istream &operator>>(istream &in, DateTime &t); 
    friend ostream &operator<<(ostream &out, const DateTime &t); 
};

#endif