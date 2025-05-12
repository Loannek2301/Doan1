#include "clsSinhVien.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
clsSinhVien::clsSinhVien() {
    maSV = "";
    hoTen = "";
    ngaySinh = "";
    lop = "";
    sobuoiDH = 0;
    sobuoivang = 0;
    sobuoiMH = 0;
}
void clsSinhVien::nhapSinhVien(string ma, string ten, string ns, string l, int dh, int v, int mh) {
   maSV = ma;
   hoTen = ten;
   ngaySinh = ns;
   lop = l;
   sobuoiDH = dh;
   sobuoivang = v;
   sobuoiMH = mh;}
void clsSinhVien::nhapSinhVien() {
    cout << "Nhap ma SV: ";
    getline(cin, maSV);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh: ";
    getline(cin, ngaySinh);
    cout << "Nhap lop: ";
    getline(cin, lop);
    cout << "Nhap so buoi mon hoc: ";
    cin >> sobuoiMH;
    sobuoiDH = 0;
    sobuoivang = 0;
    cin.ignore();
}
void clsSinhVien::inSinhVien() {
    cout << "|" << setw(12) << left << maSV << "|"
        << setw(30) << left << hoTen << "|"
        << setw(12) << left << ngaySinh << "|"
        << setw(12) << left << lop << "|" 
        << setw(16) << left << sobuoiDH << "|" 
        << setw(16) << left << sobuoivang << "|"
        << setw(17) << left << sobuoiMH << "|" <<
       endl;
}
string clsSinhVien::layMaSV() {
    return maSV;
}
string clsSinhVien::layHoTen() {
    return hoTen;
}
string clsSinhVien::layNgaySinh() {
    return ngaySinh;
}
string clsSinhVien::layLop() {
    return lop;
}
int clsSinhVien::laySobuoiDH() {
    return sobuoiDH;
}
int clsSinhVien::laySobuoivang() {
    return sobuoivang;
}
int clsSinhVien::laySobuoiMH() {
    return sobuoiMH;
}
void clsSinhVien::suaMasv() {
    string masv;
    cin.ignore();
    cout << "Nhap lai ma sinh vien: ";
    getline(cin, masv);
    maSV = masv;
}
void clsSinhVien::suaHoTen() {
    string ten;
    cin.ignore();
    cout << "Nhap lai ten sinh vien: ";
    getline(cin, ten);
    hoTen = ten;
}
void clsSinhVien::suaNgaySinh() {
    string ngay;
    cin.ignore();
    cout << "Nhap lai ngay sinh: ";
    getline(cin, ngay);
    ngaySinh = ngay;
}
void clsSinhVien::suaLop() {
    string l;
    cin.ignore();
    cout << "Nhap lai lop: ";
    getline(cin, l);
    lop = l;
}
void clsSinhVien::DDSobuoiDH() {
    sobuoiDH++;
}
void clsSinhVien::DDSobuoivang() {
    sobuoivang++;
}
void clsSinhVien::suaSobuoivang(int sb) {
    sobuoivang = sb;
}
void clsSinhVien::suaSobuoiMH() {
    int sobuoi;
    cout << "Nhap so buoi mon hoc: ";
    cin >> sobuoi;
    sobuoiMH = sobuoi;
}