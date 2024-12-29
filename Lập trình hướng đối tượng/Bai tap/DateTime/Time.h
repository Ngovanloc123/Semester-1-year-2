#ifndef Time_h
#define Time_h
#include <iostream>
using namespace std;

class Time {
protected:
    int hour, minute, second;
public:
    Time(int = 0, int = 0, int = 0);
    Time &operator++();
    Time &operator--();
    friend istream &operator>>(istream &in, Time &t); 
    friend ostream &operator<<(ostream &out, const Time &t); 
};

#endif
