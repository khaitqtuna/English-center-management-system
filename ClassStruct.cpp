#include <iostream>
#include <string>
using namespace std;

#include "ClassStruct.h"

void initNodeClass(NodeClass*& s) {
    s = nullptr;
}


NodeClass* createNodeClass(Class data) {
    NodeClass* node = new NodeClass;
    node->data = data;
    node->next = nullptr;
    return node;
}


void addClass(NodeClass*& s, Class data) {
    NodeClass* newNode = createNodeClass(data);
    if(s->next == NULL){
        s = newNode;
        return;
    }
    newNode->next = s;
    s = newNode;
}

NodeClass* searchClass(NodeClass* s, string data) {
    NodeClass* ptr = s;
    while (s != nullptr) {
        if(ptr->data.ID == data)
            return ptr;
        else if(ptr->data.name == data)
            return ptr;
        else 
            ptr = ptr->next;
    }
    return nullptr;
}

Class deleteClass(NodeClass*& s, string data) {
    if(s == NULL){
        cout<< "Danh sach lop trong" << endl;
        return;
    }

    NodeClass* ptr = searchClass(s, data);
    if(ptr == NULL){
        cout<< "Khong co lop can tim" << endl;
        return;
    }

    NodeClass *ptr1 = s;
    while(ptr1 != NULL && ptr1->next != ptr)        //tra ve phan tu truoc cai can tim
        ptr1 = ptr1->next;
    
    Class temp;
    temp = ptr1->next->data;
    ptr1->next = ptr->next;
    delete ptr;
    return temp;
}

void displayClassInfo(NodeClass* cl){
    cout<< "1. Ten lop: " << cl->data.name << endl;
    cout<< "2. ID: " << cl->data.ID << endl;
    cout<< "3. Si so: " << cl->data.studentCount << endl;
}

void displayClassList(NodeClass* cl){
    if (cl == NULL) {
        cout << "Danh sach lop rong." << endl;
        return;
    }
    NodeClass* ptr = cl;
    cout<< "Danh sach lop:" << endl;
    while(ptr != NULL){
        cout<< ptr->data.name << " - Si so: ";
        cout<< ptr->data.studentCount << endl;
        ptr = ptr->next;
    }
}

void changeTeacherInfo(NodeClass* cl){
    int check = 1;
    system("cls");

    while (check == 1) {
    	displayClassList(cl);
        cout << "Nhap ten/ID giao vien ban muon thay doi thong tin: ";
        string name;
        cin.ignore();  
        getline(cin, name);  

        NodeClass* t = searchClass(cl, name);
        if (t == NULL) 
            cout << "Danh sach lop rong." << endl;
        
        else {
            displayClassInfo(t);
            cout << "Ban muon thay doi thong tin gi?\n";
            cout<< "1. Ten giao vien" << endl;
            cout<< "2. ID" << endl;
            cout<< "3. Si so" << endl;
            cout << "Nhap lua chon: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1: {
                    cout << "Nhap ten moi: ";
                    string newName;
                    cin.ignore();
                    getline(cin, newName);
                    t->data.name = newName;
                    break;
                }
                case 2: {
                    cout << "Nhap ID moi: ";
                    string newID;
                    cin.ignore();
                    getline(cin, newID);
                    t->data.ID = newID;
                    break;
                }
                case 3: {
                    cout << "Nhap si so moi: ";
                    int n;
                    cin.ignore();
                    cin >> n;
                    t->data.studentCount = n;
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
