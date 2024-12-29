#include "NhanVien.h"
#include <stdexcept>

NhanVien::NhanVien(const std::string &maNV, const std::string &name, const Date &ngayNhanViec, bool gender, double salary)
    : maNV(maNV), name(name), ngayNhanViec(ngayNhanViec), gender(gender), salary() {
        if (maNV.size() != 8)
        {
            throw std::invalid_argument("Ma nhan vien phai co chinh xac 8 ki tu");
        }
    }

std::ostream& operator<<(std::ostream& os, const NhanVien& v)
{
    os << "Ma nhan vien: " << v.maNV << std::endl;
    os << "Ten nhan vien: " << v.name << std::endl;
    os << "Ngay nhan viec: " << v.ngayNhanViec << std::endl;
    os << " Gioi tinh: " << (v.gender ? "Nam" : "Nu") << std::endl;
    os << "Luong: " << v.salary << std::endl;
    v.printDerivedInfo(os);
    return os;
}
