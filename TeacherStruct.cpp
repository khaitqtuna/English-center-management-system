#include <iostream>
#include <string>
using namespace std;

#include "TeacherStruct.h"
#include "ClassStruct.h"

struct Teacher{
    string ID;
    string name;
    string exp;  //trình độ
    int wexp;  //năm kinh nghiệm
};

struct NodeTeacher{
    Teacher data;
    NodeTeacher *next;
    NodeClass *classmanage;         //con trỏ quản lý các lớp cùng gv dạy
};

void initTeacherDS(NodeTeacher* &gv){
    gv = NULL;
}

NodeTeacher* createNodeTeacher(Teacher data){
    NodeTeacher* newNode = new NodeTeacher;
    newNode->data = data;
    newNode->next = NULL;
    newNode->classmanage = NULL;
    return newNode;
}

void addTeacher(NodeTeacher* &gv, Teacher data){
    NodeTeacher *newNode = createNodeTeacher(data);
    if(gv->next == NULL){
        gv = newNode;
        return;
    }
    newNode->next = gv;
    gv = newNode;
}

NodeTeacher* searchTeacher(NodeTeacher* &gv, string data){       //tìm bằng cả tên và ID
    NodeTeacher* ptr = gv;
    while(ptr != NULL){
        if(ptr->data.ID == data)
            return ptr;
        else if(ptr->data.name == data)
            return ptr;
        else 
            ptr = ptr->next;
    }
    return NULL;
}

Teacher deleteTeacher(NodeTeacher* &gv, string data){
    if(gv == NULL){
        cout<< "Danh sach giao vien trong" << endl;
        return;
    }

    NodeTeacher* ptr = searchTeacher(gv, data);
    if(ptr == NULL){
        cout<< "Khong co giao vien can tim" << endl;
        return;
    }

    NodeTeacher *ptr1 = gv;
    while(ptr1 != NULL && ptr1->next != ptr)        //tra ve phan tu truoc cai can tim
        ptr1 = ptr1->next;
    
    Teacher temp;
    temp = ptr1->next->data;
    ptr1->next = ptr->next;
    delete ptr;
    return temp;
}

void displayTeacherInfo(NodeTeacher* gv){
    cout<< "1. Ho va ten: " << gv->data.name << endl;
    cout<< "2. ID: " << gv->data.ID << endl;
    cout<< "3. Trinh do: " << gv->data.exp << endl;
    cout<< "4. So nam kinh nghiem: " << gv->data.wexp << endl;
}

void displayTeacherList(NodeTeacher* gv){
    if (gv == NULL) {
        cout << "Danh sach giao vien rong." << endl;
        return;
    }
    NodeTeacher* ptr = gv;
    cout<< "Danh sach giao vien:" << endl;
    while(ptr != NULL){
        cout<< ptr->data.name << endl;
        ptr = ptr->next;
    }
}

void changeTeacherInfo(NodeTeacher*& gv){
    int check = 1;
    system("cls");

    while (check == 1) {
    	displayTeacherList(gv);
        cout << "Nhap ten/ID giao vien ban muon thay doi thong tin: ";
        string name;
        cin.ignore();  
        getline(cin, name);  

        NodeTeacher* t = searchTeacher(gv, name);
        if (t == NULL) 
            cout << "Danh sach giao vien rong." << endl;
        
        else {
            displayTeacherInfo(t);
            cout << "Ban muon thay doi thong tin gi?\n";
            cout<< "1. Ten giao vien" << endl;
            cout<< "2. ID" << endl;
            cout<< "3. Trinh do" << endl;
            cout<< "4. So nam kinh nghiem" << endl;
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
                    cout << "Nhap trinh do moi: ";
                    string newType;
                    cin.ignore();
                    getline(cin, newType);
                    t->data.exp = newType;
                    break;
                }
                case 4: {
                    cout << "Nhap so nam kinh nghiem moi: ";
                    int n;
                    cin.ignore();
                    cin>> n;
                    t->data.wexp = n;
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



void TeacherManagement(QLKH* &course){
    string k;
    cout<< "Nhap ten/ID:";
    cin>> k;
    NodeTeacher* ptr = searchTeacher(course.data->);
    displayTeacherInfo(ptr);
    cout << endl << 

}