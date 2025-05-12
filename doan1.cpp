#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include "clsDanhsachSV.h"
using namespace std;
int main() {
    clsDanhsachSV dssv;
    int luachon;
    do {
        system("cls");
        cout << "-----Menu cac chuc nang-----" << endl;
        cout << "1. Nhap danh sach sinh vien" << endl;
        cout << "2. In danh sach sinh vien" << endl;
        cout << "3. Diem danh tung sinh vien" << endl;
        cout << "4. Diem danh tat ca sinh vien" << endl;
        cout << "5. Them danh sach sinh vien" << endl;
        cout << "6. Sua danh sach sinh vien" << endl;
        cout << "7. Xoa danh sach sinh vien" << endl;
        cout << "8. Tim sinh vien" << endl;
        cout << "9. Thong ke" << endl;
        cout << "10. Doc file" << endl;
        cout << "11. Ghi file" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> luachon;
        switch (luachon) {
        case 1:
            dssv.nhapDanhsachSV();
            cin.get();
            break;
        case 2:
            dssv.inDanhsachSV();
            cin.ignore();
            cin.get();
            break;
        case 3:
            // ------------------------------------------------------------------------
            cout << "Ma sinh vien da diem danh truoc do: " << dssv.getMaDaDD() << endl; // Hiển thị mã sinh viên đã điểm danh trước đó
            // ------------------------------------------------------------------------
            if (dssv.DDSobuoiDh()) {
                dssv.inDanhsachSV();
            }
            cin.ignore();
            cin.get();
            break;
        case 4:
            if (dssv.DDtatca()) {
                dssv.inDanhsachSV();
            }
            cin.ignore();
            cin.get();
            break;
        case 5:
            dssv.themDanhsachSV();
            dssv.inDanhsachSV();
            cin.ignore();
            cin.get();
            break;
        case 6:
            dssv.suaDanhsachSV();
            dssv.inDanhsachSV();
            cin.ignore();
            cin.get();
            break;
        case 7:
            dssv.xoaDanhsachSV();
            dssv.inDanhsachSV();
            cin.ignore();
            cin.get();
            break;
        case 8:
            dssv.timDanhsachSV();
            cin.ignore();
            cin.get();
            break;
        case 9: 
            cout << "----------- Thong ke ---------- " << endl;
            dssv.thongkeDanhsachSV();
			cin.ignore();
			cin.get();
			break;
        case 10:
            dssv.docfileDanhsachSV();
            dssv.inDanhsachSV();
            cin.ignore();
            cin.get();
            break;
        case 11:
            dssv.ghifileDanhsachSV();
            cin.ignore();
            cin.get();
            break;
        case 0:
            break;
        default:
            cout << "Nhap lai lua chon cua ban!!!" << endl;
            cin.ignore();
            cin.get();
            break;
        }
    } while (luachon != 0);
    return 0;
}
