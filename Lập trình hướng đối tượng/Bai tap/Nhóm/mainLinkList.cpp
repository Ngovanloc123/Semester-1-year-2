#include <iostream>
#include "LinkList.cpp"
#include "NhanVien.cpp"
#include <string>

using namespace std;

int main() {
    LinkList<NhanVien> quanLy;
    Node<T>* pos;
    // Mã nhân viên, tên, ngay nhận việc, giói tính, lương
    NhanVien nv1("NV001", "John Doe", "2021-01-01", "Nam", 50000);
    NhanVien nv2("NV002", "Jane Smith", "2020-12-15", "Nữ", 60000);
    NhanVien nv3("NV003", "David Johnson", "2021-03-05", "Nam", 55000);



    return 0;
}
