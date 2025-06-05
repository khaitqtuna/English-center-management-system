#include <iostream>
#include <string>
#include "KHstruct.h"
#include "Class.h"
using namespace std;

void initQLKH(QLKH*& k) {
    k = nullptr;
}

QLKH* createKhoaHoc(KhoaHoc Data) {
    QLKH* k = new QLKH; 
    k->data = Data;
    k->next = nullptr;
    k->all = nullptr;
    return k;
}
void addKhoaHoc(QLKH*& k , KhoaHoc Data){
    QLKH* newNode = createKhoaHoc(Data);
    if (k == nullptr){
        k = newNode;
        return;
    }
    QLKH* temp = k;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

QLKH* seachKhoaHoc (QLKH*& k , std::string name){
    QLKH* temp = k;
    while(temp != nullptr){
        if (temp->data.Name == name) return temp;
        temp = temp->next;
    }
    return nullptr;
}
KhoaHoc deleteKhoaHoc(QLKH*& k , std::string name){
    QLKH* t = seachKhoaHoc(k , name);
    if (t == nullptr) {
        cout<<"khong tim thay khoa hoc "<<name<<" de xoa.";
        return KhoaHoc();
    }
    if (t == k){
        k = k->next;
        KhoaHoc kh = t->data;
        delete t;
        return kh;
    }
    QLKH* temp = k;
    while (temp->next != t){
        temp = temp->next;
    }
    temp->next = t->next;
    KhoaHoc Data = t->data;
    delete t;
    return Data;
}
void HTKhoaHoc (KhoaHoc Data){
    cout<<"Ten khoa hoc : "<<Data.Name<<endl;
    cout<<"Trinh do yeu cau : "<<Data.type<<endl;
}
void HTQLKH(QLKH* k) {
    if (k == nullptr) {
        cout << "Danh sach khoa hoc rong." << endl;
        return;
    }

    QLKH* temp = k;
    while (temp != nullptr) {
        HTKhoaHoc(temp->data);
        cout << endl;
        temp = temp->next;
    }
}
void change_infKhoaHoc(QLKH*& k) {
    int check = 1;
    system("cls");

    while (check == 1) {
        HTQLKH(k);
        cout << "Nhap ten/ID lop ban muon thay doi thong tin: ";
        string name;
        cin.ignore();
        getline(cin, name);

        QLKH* t = seachKhoaHoc(k, name);
        if (t == nullptr) 
            cout << "Khong tim thay khoa hoc ten \"" << name << "\".\n";
        else {
            HTKhoaHoc(t->data);
            cout << "Ban muon thay doi thong tin gi?\n";
            cout << "1. Ten Khoa hoc\n";
            cout << "2. Trinh do yeu cau\n";
            cout << "Nhap lua chon: ";
            int choice;
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: {
                    cout << "Nhap ten moi: ";
                    string newName;
                    getline(cin, newName);
                    t->data.Name = newName;
                    break;
                }
                case 2: {
                    cout << "Nhap trinh do yeu cau moi: ";
                    string newType;
                    getline(cin, newType);
                    t->data.type = newType;
                    break;
                }
                default : {
                    cout << "Lua chon khong hop le.\n";
                    break;
                }
            }
        }
        cout << "\nBan co muon thay doi thong tin khac khong?\n";
        cout << "1. Co\n";
        cout << "2. Khong\n";
        cout << "Nhap lua chon: ";
        cin >> check;
        cin.ignore();
        system("cls");  
    }
}

void classManagement(QLKH*& course) {
    int m = 1;
    if (course == nullptr) {
        cout << "Khong co khoa hoc nao de quan ly lop.\n";
        return;
    }
    cout << "Quan ly lop cua khoa hoc: " << course->data.Name << endl;
    do {
        displayClassList(course->data.classes);
        if (course->data.classes == nullptr) {
            cout << "Khong co lop nao trong khoa hoc nay.\n";
        }
        cout << "1. Them lop moi\n";
        cout << "2. Xoa lop\n";
        cout << "3. Sua thong tin lop\n";
        cout << "4. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> m;
        cin.ignore(); // Chỉ gọi 1 lần sau khi nhập số
        switch (m) {
            case 1: {
                system("cls");
                cout << "===== THEM LOP =====\n";
                Class newClass;
                cout << "Nhap ID lop: ";
                getline(cin, newClass.ID);
                cout << "Nhap ten lop: ";
                getline(cin, newClass.name);
                newClass.studentCount = 0;
                newClass.listStudent = nullptr;
                addClass(course->data.classes, newClass);
                cout << "Da them lop thanh cong!\n";
                break;  
            }
            case 2: {
                system("cls");
                cout << "===== XOA LOP =====\n";
                cout << "Nhap ten hoac ID lop can xoa: ";
                string key;
                getline(cin, key);
                Class deleted = deleteClass(course->data.classes, key);
                if (deleted.ID != "" || deleted.name != "") {
                    cout << "Da xoa lop thanh cong!\n";
                } else {
                    cout << "Khong tim thay lop \"" << key << "\" de xoa.\n";
                }
                break;
            }
            case 3: {
                system("cls");
                cout << "===== SUA THONG TIN LOP =====\n";
                displayClassList(course->data.classes);
                cout << "Nhap ten hoac ID lop can sua: ";
                string key;
                getline(cin, key);
                NodeClass* target = searchClass(course->data.classes, key);
                if (target == nullptr) {
                    cout << "Khong tim thay lop \"" << key << "\".\n";
                } else {
                    system("cls");
                    cout << "===== SUA THONG TIN LOP =====\n";
                    cout << "Thong tin lop hien tai:\n";
                    displayClassInfo(target);
                    changeClassInfo(target);
                }
                break;
            }
            case 4: {
                cout << "Quay lai menu chinh.\n";
                m = 0;
                break;
            }
            default: {
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
            }
        }
    } while (m != 0);
}

