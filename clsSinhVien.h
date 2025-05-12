#include <iostream>
#include <string>
using namespace std;
class clsSinhVien {
private:
    string maSV;
    string hoTen;
    string ngaySinh;
    string lop;
    int sobuoiDH;
    int sobuoivang;
    int sobuoiMH;
public:
    clsSinhVien();
    void nhapSinhVien(string, string, string, string, int, int, int);
    void nhapSinhVien();
    void inSinhVien();
    void suaMasv();
    void suaHoTen();
    void suaNgaySinh();
    void suaLop();
    void DDSobuoiDH();
    void DDSobuoivang();
    void suaSobuoivang(int);
    void suaSobuoiMH();
    string layMaSV();
    string layHoTen();
    string layNgaySinh();
    string layLop();
    int laySobuoiDH();
    int laySobuoivang();
    int laySobuoiMH();
};