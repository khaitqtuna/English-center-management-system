#include <iostream>
#include <cstdlib>
#include "KHstruct.h"
using namespace std;


void initQLKH(QLKH*& k) {
    k = NULL;
    k->all = NULL;
}

QLKH* createKhoaHoc(KhoaHoc Data) {
    QLKH* k = new QLKH; 
    k->data = Data;
    k->next = NULL;
    return k;
}
void addKhoaHoc(QLKH*& k , KhoaHoc Data){
	QLKH* newNode = createKhoaHoc(Data);
	if (k == NULL){
		k = newNode;
		return;
	}
	QLKH* temp = k;
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

QLKH* seachKhoaHoc (QLKH*& k , string name){
	QLKH* temp = k;
	while(temp != NULL){
		if (temp->data.Name == name) return temp;
		temp = temp->next;
	}
	return NULL;
}
KhoaHoc deleteKhoaHoc(QLKH*& k , string name){
	QLKH* t = seachKhoaHoc(k , name);
	if (t == NULL) {
	    std::cout<<"khong tim thay khoa hoc "<<name<<" de xoa.";
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
	std::cout<<"Ten khoa hoc : "<<Data.Name<<endl;
	std::cout<<"Trinh do yeu cau : "<<Data.type<<endl;
}
void HTQLKH(QLKH* k) {
    if (k == NULL) {
        std::cout << "Danh sach khoa hoc rong." << endl;
        return;
    }

    QLKH* temp = k;
    while (temp != NULL) {
        HTKhoaHoc(temp->data);
        std::cout << endl;
        temp = temp->next;
    }
}
void change_infKhoaHoc(QLKH*& k) {
    int check = 1;
    std::system("cls");

    while (check == 1) {
    	HTQLKH(k);
        std::cout << "Nhap ten/ID lop ban muon thay doi thong tin: ";
        string name;
        std::cin.ignore();  
        getline(std::cin, name);  

        QLKH* t = seachKhoaHoc(k, name);
        if (t == NULL) 
            std::cout << "Khong tim thay khoa hoc ten \"" << name << "\".\n";
        
        else {
            HTKhoaHoc(t->data);
            std::cout << "Ban muon thay doi thong tin gi?\n";
            std::cout << "1. Ten Khoa hoc\n";
            std::cout << "2. Trinh do yeu cau\n";
            std::cout << "Nhap lua chon: ";
            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    std::cout << "Nhap ten moi: ";
                    string newName;
                    std::cin.ignore();
                    getline(std::cin, newName);
                    t->data.Name = newName;
                    break;
                }
                case 2: {
                    std::cout << "Nhap trinh do yeu cau moi: ";
                    string newType;
                    std::cin.ignore();
                    getline(std::cin, newType);
                    t->data.type = newType;
                    break;
                }
				default : {
                    std::cout << "Lua chon khong hop le.\n";
                    break;
                }
            }
        }
       
        std::cout << "\nBan co muon thay doi thong tin khac khong?\n";
        std::cout << "1. Co\n";
        std::cout << "2. Khong\n";
        std::cout << "Nhap lua chon: ";
        std::cin >> check;
        std::system("cls");  
    }
}
void KHClassManagement(QLKH*& course) {
    int m = 0;
    do {
        displayClassList(course->data.classes);
        string k;
        if (course->data.classes == NULL) {
            cout << "Khong co lop nao trong khoa hoc nay.\n";
            return;
        }
        cout << "1. Them lop moi\n";
        cout << "2. Xoa lop\n";
        cout << "3. Sua thong tin lop\n";
        cout << "Nhap lua chon: ";
        cin >> m;
        cin.ignore(); 
        switch (m) {
            case 1: {
                Class newClass;
                std::cout << "Nhap ID lop: "; std::getline(std::cin, newClass.ID);
                std::cout << "Nhap ten lop: "; std::getline(std::cin, newClass.name);
                newClass.studentCount = 0;
                newClass.listStudent = NULL;
                addClass(course->data.classes, newClass);
                std::cout << "Da them lop thanh cong!\n";
                break;  
            }
            case 2: {
                std::cout << "Nhap ten hoac ID lop can xoa: ";
                std::string key; 
                std::getline(std::cin, key);
                Class deleted = deleteClass(course->data.classes, key);
                if (deleted.ID != "" || deleted.name != "") {
                    std::cout << "Da xoa lop thanh cong!\n";
                } else {
                    std::cout << "Khong tim thay lop \"" << key << "\" de xoa.\n";
                }
                break;
            }
            case 3: {
                std::cout << "Nhap ten hoac ID lop can sua: ";
                std::string key; 
                std::getline(std::cin, key);
                NodeClass* target = searchClass(course->data.classes, key);
                if (target == NULL) {
                    std::cout << "Khong tim thay lop \"" << key << "\".\n";
                } else {
                    displayClassInfo(target);
                    changeClassInfo(target);
                }
                break;
            }
            default: {
                std::cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
            }
        }
    } while (m == 1);
}



