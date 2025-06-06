#include <iostream>
#include <string>
#include "KHstruct.h"
#include "Class.h"
#include "Teacher.h"
#include "Student.h"
#include "luu.h"
using namespace std;

// Quản lý danh sách
QLKH* dsKhoaHoc = nullptr;


// Forward declarations
void systemManagement();
void gioiThieu();
void thongKe();
void quanLyKhoaHoc();
void quanLyGiaoVien();
void quanLyLopHoc();
void quanLyHocVien();

void menu() {
    cout << "===== CHUONG TRINH QUAN LY TRUNG TAM TIENG ANH =====\n";
    int choice = 0;
    do {
        cout << "\n===== MENU CHINH =====\n";
        cout << "1. Gioi thieu ve trung tam" << endl;
        cout << "2. Quan ly" << endl;
        cout << "3. Thong ke" << endl;
        cout << "4. Luu du lieu ra file" << endl;
        cout << "5. Doc du lieu tu file" << endl;
        cout << "0. Thoat" << endl;
        cout << endl << "Lua chon: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            cout << "Nhap so hop le!\n";
            continue;
        }
        cin.ignore();
        switch (choice) {
            case 1:
                system("cls");
                gioiThieu();
                system("cls");
                break;
            case 2:
                system("cls");
                systemManagement();
                system("cls");
                break;
            case 3:
                system("cls");
                thongKe();
                system("cls");
                break;
            case 4:
                writeDataToFile(dsKhoaHoc, "data.txt");
                cout << "Da luu du lieu ra file data.txt!\n";
                break;
            case 5:
                readDataFromFile(dsKhoaHoc, "data.txt");
                cout << "Da nap du lieu tu file data.txt!\n";
                break;
            case 0:
                system("cls");
                cout << "Cam on ban da su dung chuong trinh!\n";
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Chu so khong hop le, moi nhap lai!\n";
        }
    } while (choice != 0);
}

void systemManagement() {
    int choice = 0;
    do {
        cout << "\n===== QUAN LY HE THONG =====\n";
        cout << "Chon chuc nang quan ly:\n";
        cout << "1. Quan ly Khoa hoc" << endl;
        cout << "2. Quan ly Giao vien" << endl;
        cout << "3. Quan ly Lop hoc" << endl;
        cout << "4. Quan ly Hoc vien" << endl;
        cout << "0. Quay lai" << endl;
        cout << endl << "Lua chon: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            cout << "Nhap so hop le!\n";
            continue;
        }
        cin.ignore();
        switch (choice) {
            case 1:
                system("cls");
                quanLyKhoaHoc();
                system("cls");
                break;
            case 2:
                system("cls");
                quanLyGiaoVien();
                system("cls");
                break;
            case 3:
                system("cls");
                quanLyLopHoc();
                system("cls");
                break;
            case 4:
                system("cls");
                quanLyHocVien();
                system("cls");
                break;
            case 0:
                cout << "Quay lai menu chinh.\n";
                break;
            default:
                cout << "Chu so khong hop le, moi nhap lai!\n";
        }
    } while (choice != 0);
}

void gioiThieu() {
    cout << "\n--- GIOI THIEU VE TRUNG TAM ---\n";
    cout << "Trung tam dao tao lap trinh ...\n";
    cout << "------------------------------\n\n";
}

void thongKe() {
    cout << "\n--- THONG KE ---\n";
    cout << "(Chuc nang dang phat trien)\n";
    cout << "----------------\n\n";
}

void quanLyKhoaHoc() {
    int choice;
    do {
        system("cls");
        cout << "\n===== QUAN LY KHOA HOC =====\n";
        cout << "1. Them khoa hoc\n";
        cout << "2. Xoa khoa hoc\n";
        cout << "3. Sua thong tin khoa hoc\n";
        cout << "4. Xem danh sach khoa hoc\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                system("cls");
                cout << "===== THEM KHOA HOC =====\n";
                KhoaHoc kh;
                cout << "Nhap ID khoa hoc: ";
                getline(cin, kh.ID);
                if(seachKhoaHoc(dsKhoaHoc, kh.ID) != nullptr) {
                    cout << "ID khoa hoc da ton tai! Vui long nhap ID khac.\n";
                    break;
                }
                cout << "Nhap ten khoa hoc: ";
                getline(cin, kh.Name);
                cout << "Nhap trinh do yeu cau: ";
                getline(cin, kh.type);
                kh.teachers = nullptr;
                kh.classes = nullptr;
                addKhoaHoc(dsKhoaHoc, kh);
                cout << "Da them khoa hoc thanh cong!\n";
                break;
            }
            case 2: {
                system("cls");
                cout << "===== XOA KHOA HOC =====\n";
                cout << "Nhap ten khoa hoc can xoa: ";
                string name;
                getline(cin, name);
                KhoaHoc deleted = deleteKhoaHoc(dsKhoaHoc, name);
                if (deleted.Name != "")
                    cout << "Da xoa khoa hoc thanh cong!\n";
                system("cls");
                break;
            }
            case 3:
                system("cls");
                cout << "===== SUA THONG TIN KHOA HOC =====\n";
                change_infKhoaHoc(dsKhoaHoc);
                system("cls");
                break;
            case 4:
                system("cls");
                cout << "===== DANH SACH KHOA HOC =====\n";
                HTQLKH(dsKhoaHoc);
                cout << "Nhan phim bat ky de tiep tuc...\n";
                cin.get();
                system("cls");
                break;
            case 0:
                cout << "Quay lai menu quan ly.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}

void quanLyGiaoVien() {
    int choice;
    do {
        system("cls");
        cout << "\n===== QUAN LY GIAO VIEN =====\n";
        cout << "1. Them giao vien moi\n";
        cout << "2. Chinh sua/Xoa thong tin giao vien\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                system("cls");
                cout << "===== THEM GIAO VIEN =====\n";
                Teacher newTeacher;
                cout << "Nhap ID giao vien: ";
                getline(cin, newTeacher.ID);
                if (searchTeacher(dsKhoaHoc->all, newTeacher.ID) != nullptr) {
                    cout << "ID giao vien da ton tai! Vui long nhap ID khac.\n";
                    break;
                }
                cout << "Nhap ten giao vien: ";
                getline(cin, newTeacher.name);
                cout << "Nhap trinh do giao vien: ";
                getline(cin, newTeacher.exp);
                cout << "Nhap so nam kinh nghiem: ";
                cin >> newTeacher.wexp;
                cin.ignore();
                addTeacher(dsKhoaHoc->all, newTeacher);
                cout << "Da them giao vien thanh cong!\n";
                break;
            }
            case 2:
                system("cls");
                TeacherManagement(dsKhoaHoc);
                break;
            case 0:
                cout << "Quay lai menu quan ly.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
        system("cls");
    } while (choice != 0);
}

void quanLyLopHoc() {
    if (dsKhoaHoc == nullptr) {
        cout << "Chua co khoa hoc nao. Hay them khoa hoc truoc!\n";
        return;
    }
    cout << "Danh sach cac khoa hoc hien co:\n";
    HTQLKH(dsKhoaHoc);
    cout << "Nhap ten khoa hoc de quan ly lop: ";
    string name;
    getline(cin, name);
    QLKH* kh = seachKhoaHoc(dsKhoaHoc, name);
    if (kh == nullptr) {
        cout << "Khong tim thay khoa hoc!\n";
        return;
    }
    classManagement(kh);
}
void quanLyHocVien() {
    if (dsKhoaHoc == nullptr) {
        cout << "Chua co khoa hoc nao. Hay them khoa hoc truoc!\n";
        return;
    }
    cout << "Nhap ten khoa hoc: ";
    string name;
    cin.ignore();
    getline(cin, name);
    QLKH* kh = seachKhoaHoc(dsKhoaHoc, name);
    if (kh == nullptr) {
        cout << "Khong tim thay khoa hoc!\n";
        return;
    }
    cout << "Nhap ten lop: ";
    string tenLop;
    getline(cin, tenLop);
    NodeClass* lop = searchClass(kh->data.classes, tenLop);
    if (lop == nullptr) {
        cout << "Khong tim thay lop!\n";
        return;
    }
    changeClassInfo(lop);
}

int main() {
    menu();
    return 0;
}

