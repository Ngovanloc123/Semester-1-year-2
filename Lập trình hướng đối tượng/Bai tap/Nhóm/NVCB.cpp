#include "NVCB.h"

NVCB::NVCB(const std::string &maNV, const std::string &name, const Date &ngayNhanViec, bool gender, double salary, float heSoLuong, int thamNien) 
    : NhanVien(maNV, name, ngayNhanViec, gender, salary) {
        if(heSoLuong < 2.34 || heSoLuong > 10) {
            throw std::invalid_argument("He so luong phai nam trong khoang [2.34, 10]");
        }
        this->heSoLuong = heSoLuong;
        this->thamNien = thamNien;
    }

int NVCB::tinhLuong()
{
    // - Lương NVBC = (Hệ số lương * 1.390.000) * (1 + Thâm niên làm việc).
    salary = (heSoLuong*1.390.000) * (1 + thamNien);
    return salary;
}
