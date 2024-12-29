#include <iostream>
#include "DateTime.cpp"
#include "Time.cpp"
#include "Date.cpp"
using namespace std;

int main() {
    cout << "Test class Time\n";
    Time t1(23, 59, 59);
    ++t1;
    cout << t1 << endl;
    Time t2(0, 0, 0);
    --t2;
    cout << t2 << endl;
    Time t3(22, 40, 59);
    ++t3;
    cout << t3 << endl;
    cout << endl;
    cout << "Test class Date\n";
    Date d1(31, 12, 2024);
    ++d1;
    cout << d1 << endl;
    Date d2(1, 1, 2024);
    --d2;
    cout << d2 << endl;
    cout << endl;
    cout << "Test class DateTime\n";
    DateTime dt1(31, 12, 2024, 23, 59, 59);
    ++dt1;
    cout << dt1 << endl;
    DateTime dt2(1, 2, 2024, 0, 0, 0);
    --dt2;
    cout << dt2;
    cout << endl;
}