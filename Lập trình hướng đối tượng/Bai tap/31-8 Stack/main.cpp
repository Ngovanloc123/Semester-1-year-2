#include <iostream>
#include "stack.cpp"

using namespace std;

void change(int x) {
    Stack s(8);
    while(x >= 16) {
        int remainder = x % 16;
        if(remainder < 10)
            s.push(remainder);
        x /= 16;
    }
    s.push(x);
    s.display();
}

int main() {
    int x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Gia tri " << x << " tu he 10 sang he 16 bang: " << endl;
    change(x);
}