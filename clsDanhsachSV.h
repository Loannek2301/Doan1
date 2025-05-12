#include <iostream>
#include <string>
#include "clsSinhVien.h"
using namespace std;
class clsDanhsachSV {
private:
	clsSinhVien sinhVien[1000];
	int soluong;
	string maDaDD; 
public:
	clsDanhsachSV();
	void nhapDanhsachSV();
	void inDanhsachSV();
	bool DDSobuoiDh();
	bool DDtatca();
	void DDSobuoiV();
	int maxSobuoi();
	void themDanhsachSV();
	void suaDanhsachSV();
	int timkiemvitri(string);
	void xoaDanhsachSV();
	void timDanhsachSV();
	void thongkeDanhsachSV();
	void ghifileDanhsachSV();
	void docfileDanhsachSV();
	string moHopThoaiChonFile()
	string getMaDaDD(); 
};