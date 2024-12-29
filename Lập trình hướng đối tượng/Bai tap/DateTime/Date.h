#ifndef Date_h
#define Date_h
#include <iostream>
using namespace std;

class Date {
protected:
    int day, month, year;
public:
    Date(int = 1, int = 1, int = 2024);
    friend bool isLeapYear(int year);
    Date &operator++();
    Date &operator--();
    friend istream &operator>>(istream &in, Date &d); 
    friend ostream &operator<<(ostream &out, const Date &d); 
};

#endif
