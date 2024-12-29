#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date &Date::operator++()
{
    day++;
    int daysInMonth; // Ngày trong tháng

    // Lấy ngày trong tháng
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31; break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30; break;
        case 2:
            daysInMonth = isLeapYear(year) ? 29 : 28; break;
        default:
            daysInMonth = 30;
    }
    // Cập nhật ngày tháng năm 
    if (day > daysInMonth) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date &Date::operator--()
{
    day--;
    int daysInMonth;
    // Lấy tháng trước
    int previousMonth = month;
    if (month == 1) {
        previousMonth = 12;
        year--;
    }
    else previousMonth--;
    // Lấy ngày trong tháng trước
    switch (previousMonth) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31; break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30; break;
        case 2:
            daysInMonth = isLeapYear(year) ? 29 : 28; break;
        default:
            daysInMonth = 30;
    }
    // Cập nhật ngày tháng năm
    if (day < 1) {
        day = daysInMonth;
        month = previousMonth;
        if (month < 1) {
            month = 12;
            year--;
        }
    }
    return *this;
}

istream &operator>>(istream &in, Date &d)
{
    cout << "Nhap ngay: ";
    in >> d.day;
    cout << "Nhap thang: ";
    in >> d.month;
    cout << "Nhap nam: ";
    in >> d.year;
    return in;
}

ostream &operator<<(ostream &out, const Date &t)
{
    out << t.day << "/" << t.month << "/" << t.year;
    return out;
}
