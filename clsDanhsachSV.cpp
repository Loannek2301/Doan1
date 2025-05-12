#include "clsDanhsachSV.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <commdlg.h>
#include <vector>
#include <ctime>

using namespace std;
string file_name_before_edit = "";
time_t now = time(0);
tm t;
int dayFull;

clsDanhsachSV::clsDanhsachSV() {
	soluong = 0;
	maDaDD = ""; 
}
void clsDanhsachSV::nhapDanhsachSV() {
	localtime_s(&t, &now);
	dayFull = t.tm_mday;
	cout << "Nhap so luong sinh vien: ";
	cin >> soluong;
	cin.ignore();
	for (int i = 0; i < soluong; i++) { 
		cout << "Nhap sinh vien thu " << i + 1 << ":" << endl;
		sinhVien[i].nhapSinhVien();
	}
}
void clsDanhsachSV::inDanhsachSV() {
	cout << "\n\t\t\t\tDANH SACH SINH VIEN" << endl;
	cout << "|" << setw(12) << left << " MSSV " << "|"
    << setw(30) << left << " Ho va Ten " << "|"
    << setw(12) << left << " Ngay sinh " << "|"
    << setw(12) << left << " Lop " << "|" 
    << setw(16) << left << " So buoi da hoc " << "|" 
    << setw(16) << left << " So buoi vang " << "|"
    << setw(17) << left << " So buoi mon hoc " << "|"<< endl;
cout << "|------------+------------------------------+------------+------------+----------------+----------------+-----------------|" << endl;
	for (int i = 0; i < soluong; i++) {
		sinhVien[i].inSinhVien();
	}
}
bool clsDanhsachSV::DDSobuoiDh() {
	string maSv;
	cout << "Nhap ma sinh vien can diem danh: ";
	cin.ignore();
	getline(cin, maSv);
	if (timkiemvitri(maSv) > -1) { 
		if (sinhVien[timkiemvitri(maSv)].laySobuoiDH() < dayFull) {
			sinhVien[timkiemvitri(maSv)].DDSobuoiDH();
			DDSobuoiV();
			maDaDD = sinhVien[timkiemvitri(maSv)].layMaSV();
			cout << "Diem danh thanh cong";
			return true;
		}
		else
		{
			cout << "Diem danh that bai. Vuot qua ngay hien tai!!";
		}
			
	}
	else {
		cout << "Khong tim thay ma!!";
	}
	return false;
}
bool clsDanhsachSV::DDtatca() {
	int soluonghsdaydu = 0;
	for (int i = 0; i < soluong; i++) {
		if (sinhVien[i].laySobuoiDH() >= dayFull) {
			soluonghsdaydu++;
		}
	}
	if(soluonghsdaydu > 0)
	{
		cout << "Diem danh that bai. Co sinh vien da hoc day du!!";
		return false;
	}
	for (int i = 0; i < soluong; i++) {
		sinhVien[i].DDSobuoiDH();
	}
	DDSobuoiV();
	maDaDD = ""; 
	cout << "Diem danh thanh cong";
	return true;

}
int clsDanhsachSV::maxSobuoi() {
	int max = sinhVien[0].laySobuoiDH();
	for (int i = 1; i < soluong; i++) {
		if (sinhVien[i].laySobuoiDH() > max) {
			max = sinhVien[i].laySobuoiDH();
		}
	}
	return max;
}
void clsDanhsachSV::DDSobuoiV() {
	int max = maxSobuoi();
	for (int i = 0; i < soluong; i++) {
		sinhVien[i].suaSobuoivang(max - sinhVien[i].laySobuoiDH());
	}
}
void clsDanhsachSV::themDanhsachSV() {
	cout << "Nhap sinh vien thu " << soluong + 1 << ":" << endl;
	cin.ignore();
	sinhVien[soluong].nhapSinhVien();
	soluong++;
}
int clsDanhsachSV::timkiemvitri(string ma) {
	for (int i = 0; i < soluong; i++) {
		if (ma == sinhVien[i].layMaSV()) {
			return i;
		}
	}
	return -1;
}
void clsDanhsachSV::suaDanhsachSV() {
		string ma;
		cout << "Nhap ma sinh vien can sua: ";
		cin.ignore();
		getline(cin, ma);
		if (timkiemvitri(ma) > -1) {
			int chon;
			do {
				cout << "-----Menu chinh sua-----" << endl;
				cout << "1. Ho ten" << endl;
				cout << "2. Ngay sinh" << endl;
				cout << "3. Lop" << endl;
				cout << "0. Thoat" << endl;
				cout << "Nhap lua chon cua ban: ";
				cin >> chon;
				switch (chon)
				{
				case 1:
					sinhVien[timkiemvitri(ma)].suaHoTen();
					break;
				case 2:
					sinhVien[timkiemvitri(ma)].suaNgaySinh();
					break;
				case 3:
					sinhVien[timkiemvitri(ma)].suaLop();
					break;
				case 0:
					break;
				default:
					cout << "Nhap lai lua chon cua ban!!!" << endl;
					break;
				}
			} while (chon != 0);
		}
		else {
			cout << "Khong tim thay ma " << ma << endl;
		}
	}
void clsDanhsachSV::xoaDanhsachSV() {
		string ma;
		int position;
		cin.ignore();
		cout << "Nhap ma sinh vien can xoa: ";
		getline(cin, ma);
		position = timkiemvitri(ma);
		if (position > -1) {
				string line;
				soluong--;
				for (int i = 0; i < soluong; ++i) {
					if (i < position)
						continue;
					else if (i == position)
						sinhVien[position] = sinhVien[position + 1];
					else
						sinhVien[i] = sinhVien[i+1];
				}
		}
		else {
			cout << "Khong tim thay ma " << ma << endl;
		}
	}
void clsDanhsachSV::timDanhsachSV() {
	string ma;
	int f = 0;
	cout << "\nNhap ma sinh vien can tim: ";
	cin.ignore();
	getline(cin, ma);
	for (int i = 0; i < soluong; i++) {
		if (ma == sinhVien[i].layMaSV()) {
			sinhVien[i].inSinhVien();
			f = 1;
			break;
		}
	}
	if (f == 0) {
		cout << "Khong tim thay ma " << ma << endl;
	}
}
void clsDanhsachSV::thongkeDanhsachSV() {
	
	int soluonghsDayDu = 0;
	int soluonghsVang = 0;

	for (int i = 0; i < soluong; i++) {
		if (sinhVien[i].laySobuoiDH() == dayFull && sinhVien[i].laySobuoiDH() <= sinhVien[i].laySobuoiMH()){
			soluonghsDayDu++;
		}
		else {
			soluonghsVang++;
		}
	}
	cout << "So luong hoc sinh di hoc day du: " << soluonghsDayDu << endl;
	cout << "So luong hoc sinh vang hoc: " << soluonghsVang << endl;
}
void clsDanhsachSV::ghifileDanhsachSV() {
	if (file_name_before_edit == "") file_name_before_edit = "C:\\doan1\\doan1\\Danh_sach_sinh_vien.txt";
	ofstream ghifile(file_name_before_edit, ios::out);
	if (ghifile.is_open()) {
		for (int i = 0; i < soluong; i++) {
		ghifile << sinhVien[i].layMaSV() << "|" 
		<< sinhVien[i].layHoTen() << "|"
		<< sinhVien[i].layNgaySinh() << "|" 
		<< sinhVien[i].layLop() << "|"
		<< sinhVien[i].laySobuoiDH() << "|"
		<< sinhVien[i].laySobuoivang() << "|"
		<< sinhVien[i].laySobuoiMH() << endl;
		}
		cout << "Ghi file thanh cong!" << endl;
	}
	else {
		cout << "Loi mo file!" << endl;
	}
	ghifile.close();
}
string clsDanhsachSV::moHopThoaiChonFile() {
	char filename[MAX_PATH] = "";
	OPENFILENAMEA ofn;      
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = filename;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	ofn.nFilterIndex = 1;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	if (GetOpenFileNameA(&ofn)) {
		return string(filename);
	}
	else {
		return "";
	}
}
void clsDanhsachSV::docfileDanhsachSV() {
	localtime_s(&t, &now);
	dayFull = t.tm_mday;
	string tenFile = moHopThoaiChonFile();
	file_name_before_edit = tenFile;
	ifstream docfile(tenFile, ios::in);
	if (docfile.is_open()) {
		string line;
		while (getline(docfile, line)) {
			stringstream ss(line);
			string masv, hoten, ngaysinh, Lop, sobuoidh, sobuoiVang, sobuoimh;
			getline(ss, masv, '|');
			getline(ss, hoten, '|');
			getline(ss, ngaysinh, '|');
			getline(ss, Lop, '|');
			getline(ss, sobuoidh, '|');
			getline(ss, sobuoiVang, '|');
			getline(ss, sobuoimh);
			int sbdh, sbv, sbmh;
			stringstream(sobuoidh) >> sbdh;
			stringstream(sobuoiVang) >> sbv;
			stringstream(sobuoimh) >> sbmh;
			sinhVien[soluong].nhapSinhVien(masv, hoten, ngaysinh, Lop, sbdh, sbv, sbmh);
			soluong++;
		}
	}
	else {
		cout << "Loi mo file!" << endl;
	}
	docfile.close();
};
string clsDanhsachSV::getMaDaDD() {
	return maDaDD;
}
