#include "Time.h"

istream &operator>>(istream &in, Time &t)
{
    cout << "Nhap gio: ";
    in >> t.hour;
    cout << "Nhap phut: ";
    in >> t.minute;
    cout << "Nhap giay: ";
    in >> t.second;
    return in;
}

ostream &operator<<(ostream &out, const Time &t)
{
    out << t.hour << ":" << t.minute << ":" << t.second;
    return out;
}

Time::Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

Time &Time::operator++()
{
    ++second;
    if (second == 60) {
        second = 0;
        ++minute;
        if (minute == 60) {
            minute = 0;
            ++hour;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
    return *this;
}

Time &Time::operator--()
{
    --second;
    if (second < 0) {
        second = 59;
        --minute;
        if (minute < 0) {
            minute = 59;
            --hour;
            if (hour < 0) {
                hour = 23;
            }
        }
    }
    return *this;
}
