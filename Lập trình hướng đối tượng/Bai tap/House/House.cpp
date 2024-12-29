#include "House.h"

House::House(int quantity)
{
    this->quantity = quantity;
}

House::~House() {
    delete[] room;
}



float House::areaOfHouse()
{
    int area = 0;
    for(int i = 1; i <= quantity; i++) {
        area += room[i].area();
        cout << room[i].area() << endl;
    }
    return area;
}

istream &operator>>(istream &in, House &h)
{
    for(int i = 1; i <= h.quantity; i++) {
        cout << "Loai phong:\n";
        cout << "1. Hinh tron\n";
        cout << "2. Hinh vuong tam giac\n";
        cout << "3. Hinh vuong\n";
        cout << "Nhap loai phong thu " << i << ": ";
        int choice; cin >> choice;
        if(choice == 1) {
            int x; 
            cout << "Nhap ban kinh: "; cin >> x;
            Circle c(x);
            h.room[i] = static_cast<Room&> (c);
        }
        if(choice == 2) {
            int x; 
            cout << "Nhap canh tam giac: "; cin >> x;
            Triangle t(x);
            h.room[i] = static_cast<Room&> (t);
        }
        if(choice == 3) {
            int x; 
            cout << "Nhap canh hinh vuong: "; cin >> x;
            Square s(x);
            h.room[i] = static_cast<Room&> (s);
        }
    }
    return in;
}
