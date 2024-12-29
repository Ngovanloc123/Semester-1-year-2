#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <date.h>

class NhanVien
{
    private:
            std::string maNV;
            std::string name;
            Date ngayNhanViec;
            bool gender; //
            double salary; // lương chung

    public:
                NhanVien(const std::string& maNV, const std::string& name, const Date& ngayNhanViec, bool gender, double salary);
                virtual ~NhanVien() = default;
                virtual double tinhLuong() = 0;
                friend std::ostream& operator<<(std::ostream& os, const NhanVien& nv);
                virtual void printDerivedInfo(std::ostream& os) const = 0;


};

#endif