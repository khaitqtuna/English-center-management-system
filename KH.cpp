#include <iostream>
#include <string>
#include "KHstruct.h"
#include "Class.h"
#include "Teacher.h"
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
        if (temp->data.ID == name || temp->data.Name == name) return temp;
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
    cout << "ID khoa hoc : " << Data.ID << endl;
    cout << "Ten khoa hoc : " << Data.Name << endl;
    cout << "Trinh do yeu cau : " << Data.type << endl;
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
        cout << "Nhap ID hoac ten khoa hoc ban muon thay doi thong tin: ";
        string name;
        getline(cin, name);
        QLKH* t = seachKhoaHoc(k, name);
        if (t == nullptr) 
            cout << "Khong tim thay khoa hoc ten/ID \"" << name << "\".\n";
        else {
            HTKhoaHoc(t->data);
            cout << "Ban muon thay doi thong tin gi?\n";
            cout << "1. ID Khoa hoc\n";
            cout << "2. Ten Khoa hoc\n";
            cout << "3. Trinh do yeu cau\n";
            cout << "4. Quan ly giao vien khoa hoc\n";
            cout << "Nhap lua chon: ";
            int choice;
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: {
                    cout << "Nhap ID moi: ";
                    string newID;
                    getline(cin, newID);
                    t->data.ID = newID;
                    break;
                }
                case 2: {
                    cout << "Nhap ten moi: ";
                    string newName;
                    getline(cin, newName);
                    t->data.Name = newName;
                    break;
                }
                case 3: {
                    cout << "Nhap trinh do yeu cau moi: ";
                    string newType;
                    getline(cin, newType);
                    t->data.type = newType;
                    break;
                }
                case 4: {
                    KHTeacherManagement(t);
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
        cin.ignore(); // Ch? g?i 1 l?n sau khi nh?p s?
        switch (m) {
            case 1: {
                system("cls");
                cout << "===== THEM LOP =====\n";
                Class newClass;
                cout << "Nhap ID lop: ";
                getline(cin, newClass.ID);
                if (searchClass(course->data.classes, newClass.ID) != nullptr) {
                    cout << "ID lop da ton tai! Vui long nhap ID khac.\n";
                    break;
                }
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
void KHTeacherManagement(QLKH*& course) {
    if (course == nullptr) {
        cout << "Khong co khoa hoc nao de quan ly giao vien.\n";
        return;
    }
    int choice;
    do {
        system("cls");
        cout << "===== QUAN LY GIAO VIEN TRONG KHOA HOC =====\n";
        displayTeacherList(course->data.teachers);
        cout << "1. Them giao vien\n";
        cout << "2. Sua thong tin giao vien\n";
        cout << "3. Xoa giao vien\n";
        cout << "4. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1: {
                system("cls");  
                cout << "===== THEM GIAO VIEN =====\n";
                string ID;  
                displayTeacherList(course->all);
                if (course->all == nullptr) {
                    cout << "Vui long them giao vien vao danh sach truoc.\n";
                    cout << "Quay lai menu quan ly khoa hoc.\n";
                    cout << "Nhap bat ki de quay lai: ";
                    string temp;
                    getline(cin, temp);                     
                    return;
                }
                cout << "Nhap ID giao vien: ";
                getline(cin,ID);    
                NodeTeacher * temp = searchTeacher(course->all, ID);
                addTeacher(course->data.teachers, temp->data);
                cout << "Da them giao vien thanh cong!\n";
                break;
            }
            case 2: {
                system("cls");
                changeTeacherInfoForCourse(course->data.teachers);
                break;
            }
            case 3: {
                system("cls");
                cout << "===== XOA GIAO VIEN =====\n";
                cout << "Nhap ten hoac ID giao vien can xoa: ";
                string key;
                getline(cin, key);
                NodeTeacher* deleted = deleteTeacher(course->data.teachers, key);
                if (deleted != nullptr) {
                    cout << "Da xoa giao vien thanh cong!\n";
                } else {
                    cout << "Khong tim thay giao vien de xoa.\n";
                }
                break;
            }
            case 4:
                cout << "Quay lai menu quan ly.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 4);
}
void changeTeacherInfoForCourse(NodeTeacher*& head) {
    if (head == nullptr) {
        cout << "Khong co giao vien nao trong khoa hoc nay.\n";
        return;
    }
    cout << "===== SUA THONG TIN GIAO VIEN TRONG KHOA HOC =====\n";
    displayTeacherList(head);
    cout << "Nhap ID hoac ten giao vien can sua: ";
    string key;
    getline(cin, key);
    NodeTeacher* teacher = searchTeacher(head, key);
    if (teacher == nullptr) {
        cout << "Khong tim thay giao vien voi ID/ten nay.\n";
        return;
    }
    cout << "Thong tin hien tai:\n";
    displayTeacherInfo(teacher);
    cout << "Chon thong tin muon sua:\n";
    cout << "1. ID\n2. Ten\n3. Trinh do\n4. So nam kinh nghiem\n";
    cout << "Nhap lua chon: ";
    int choice;
    cin >> choice;
    cin.ignore();
    switch (choice) {
        case 1: {
            cout << "Nhap ID moi: ";
            getline(cin, teacher->data.ID);
            break;
        }
        case 2: {
            cout << "Nhap ten moi: ";
            getline(cin, teacher->data.name);
            break;
        }
        case 3: {
            cout << "Nhap trinh do moi: ";
            getline(cin, teacher->data.exp);
            break;
        }
        case 4: {
            cout << "Nhap so nam kinh nghiem moi: ";
            cin >> teacher->data.wexp;
            cin.ignore();
            break;
        }
        default:
            cout << "Lua chon khong hop le!\n";
    }
    cout << "Da cap nhat thong tin giao vien.\n";
}

