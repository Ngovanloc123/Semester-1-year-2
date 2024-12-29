#include "SET.cpp"
#include <iostream>

using namespace std;

int main() {
    Set s1(20);
    s1 = s1 + 11;
    s1 = s1 + 20;
    s1 = s1 + 17;
    s1 = s1 + 20;
    s1 = s1 + 15;
    s1 = s1 + 20;
    s1 = s1 + 7;
    s1 = s1 + 5;
    cout << "In ra tap hop s1: " << s1 << endl;
    s1 = s1 - 2;
    s1 = s1 - 5;
    cout << "In ra tap hop s1 sau khi loai bo phan tu: " << s1 << endl;

    int a[] = {10, 1, 3, 4, 4, 7, 5, 4, 6, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);
    Set s2(n, a);
    cout << "In ra tap hop s2: " << s2 << endl;
    
    Set s3(s2);
    cout << "Tap hop s3 sao chep tu s2: " << s3 << endl;

    Set s5;
    s5 = s1 + s2;
    cout << "s5 la hop s1 va s2: " << s5 << endl;
    cout << "s1\\s2: " << s1 - s2 << endl;
    cout << "Giao s1 va s2: " << s1 * s2 << endl;
}