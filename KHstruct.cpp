#include <iostream>
#include <cstdlib>
#include "KHstruct.h"
using namespace std;


void initQLKH(QLKH*& k) {
    k = NULL;
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

QLKH* seachKhoaHoc (QLKH*& k , string ID){
	QLKH* temp = k;
	while(temp != NULL){
		if (temp->data.ID == ID) return temp;
		temp = temp->next;
	}
	return NULL;
}
KhoaHoc deleteKhoaHoc(QLKH*& k , string ID){
	QLKH* t = seachKhoaHoc(k , ID);
	if (t == NULL) {
	    cout<<"khong tim thay khoa hoc "<<ID<<" de xoa.";
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
	cout<<"        ID        : "<<Data.ID<<endl;
	cout<<"   Ten khoa hoc   : "<<Data.Name<<endl;
	cout<<" Trinh do yeu cau : "<<Data.type<<endl;
}
void HTQLKH(QLKH* k) {
    if (k == NULL) {
        cout << "Danh sach khoa hoc rong." << endl;
        return;
    }

    QLKH* temp = k;
    while (temp != NULL) {
        HTKhoaHoc(temp->data);
        cout << endl;
        temp = temp->next;
    }
}
void change_infKhoaHoc(QLKH*& k) {
    HTQLKH(k);
    int check = 1; 
    cin >> check;
    system("cls");
    while (check == 1) {
    	HTQLKH(k);
        cout << "Chon ID khoa hoc ban muon thay doi thong tin: ";
        string ID;
        cin.ignore();  
        getline(cin, ID);  

        QLKH* t = seachKhoaHoc(k, ID);
        if (t == NULL) {
            cout << "Khong tim thay khoa hoc ID \"" << ID << "\".\n";
        } else {
            HTKhoaHoc(t->data);
            cout << "Ban muon thay doi thong tin gi?\n";
            cout << "1. Ten Khoa hoc\n";
            cout << "2. Trinh do yeu cau\n";
            cout << "Nhap lua chon: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1: {
                    cout << "Nhap ten moi: ";
                    string newName;
                    cin.ignore();
                    getline(cin, newName);
                    t->data.Name = newName;
                    break;
                }
                case 2: {
                    cout << "Nhap trinh do yeu cau moi: ";
                    string newType;
                    cin.ignore();
                    getline(cin, newType);
                    t->data.type = newType;
                    break;
                }
                case 3 : {
                	cout << "Nhap ID moi : ";
					string newID;
					cin.ignore();
					getline(cin, newID);
					t->data.ID = newID; 
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
        system("cls");
    }
}



