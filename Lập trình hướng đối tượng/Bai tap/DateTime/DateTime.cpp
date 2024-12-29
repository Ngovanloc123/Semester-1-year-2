#include "DateTime.h"

DateTime::DateTime(int day, int month, int year, int hour, int minute, int second) : 
    Date(day, month, year), Time(hour, minute, second) {}

DateTime &DateTime::operator++()
{
    Time::operator++();
    if (second == 0 && minute == 0) {
        Date::operator++(); // Increment the date
    }
    return *this;
}

DateTime &DateTime::operator--() {
    Time::operator--();

    if (second == 59 && minute == 59) {
        Date::operator--();
    }
    return *this;
}

istream &operator>>(istream &in, DateTime &dt)
{
    in >> static_cast<Date&>(dt);
    in >> static_cast<Time&>(dt);
    return in;
}

ostream &operator<<(ostream &out, const DateTime &dt) {
    out << static_cast<const Date&>(dt) << " ";
    out << static_cast<const Time&>(dt);
    return out;
}
