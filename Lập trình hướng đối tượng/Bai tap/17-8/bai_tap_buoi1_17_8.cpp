// Tạo struct Date gồm ngày tháng năm
// Nạp chồng toán tử ++, --, a++, ++a;

#include <iostream>

using namespace std;

struct Date{
    int day, month, year;
    // Date(int day, int month, int year) {
    //     this->day = day;
    //     this->month = month;
    //     this->year = year;
    // }
};

istream &operator>>(istream &in, Date &a) {
    cout << "Nhap ngay: ";
    in >> a.day;
    cout << "Nhap thang: ";
    in >> a.month;
    cout << "Nhap nam: ";
    in >> a.year;
    return in;
}

ostream &operator<<(ostream &out, const Date &a) {
    return out << a.day << "/" << a.month << "/" << a.year;
}

// Kiểm tra năm nhuận 
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Nạp chồng toán tử ++ (tiền tố)
Date &operator++(Date &a) {
    a.day++;
    int daysInMonth;// Ngày trong tháng

    // Lấy ngày trong tháng
    switch (a.month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31; break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30; break;
        case 2:
            daysInMonth = isLeapYear(a.year) ? 29 : 28; break;
        default:
            daysInMonth = 30;
    }
    // Cập nhật ngày tháng năm 
    if (a.day > daysInMonth) {
        a.day = 1;
        a.month++;
        if (a.month > 12) {
            a.month = 1;
            a.year++;
        }
    }
    return a;
}

// Nạp chồng toán tử ++ (hậu tố)
Date operator++(Date &a, int) {
    Date temp = a; // Lưu giá trị hiện tại
    ++a;           // Tăng ngày lên một
    return temp;   // Trả về giá trị ban đầu
}

int main() {
    // Date date(30, 4, 2024)
    Date date;
    cin >> date;
    cout << "Date sau khi ++: " << date++ << endl;
    
}