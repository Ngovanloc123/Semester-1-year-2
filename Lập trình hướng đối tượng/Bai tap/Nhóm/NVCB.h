#ifndef NVCB_H
#define NVCB_H

#include "NhanVien.cpp"

class NVCB : public NhanVien {
private:
    float heSoLuong;
    int thamNien;

public:
    NVCB(const std::string& maNV, const std::string& name, const Date& ngayNhanViec, bool gender, double salary, float heSoLuong, int thamNien);

    int tinhLuong() override;
};

class 

#endif