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
    NodeTeacher* ptr = gv;
    cout<< "Danh sach giao vien:" << endl;
    while(ptr->next != NULL){
        cout<< ptr->data.name;
        ptr = ptr->next;
    }
}

void changeTeacherInfo(NodeTeacher*& gv){
    int k = 1;
    do{
        displayTeacherInfo(gv);
        int c = 0;
        cout<< endl << "Nhap chu so tuong ung voi thong tin can sua:";
        cin >> c;
        while(c < 1 || c > 4){
            cout<< endl << "Chu so khong hop le, moi nhap lai:";
            cin >> c;
        }
        switch (c){
            case 1:
                cout<< endl << "Nhap du lieu moi:";
                cin >> gv->data.name;
                break;
            
            case 2:
                cout<< endl << "Nhap du lieu moi:";
                cin >> gv->data.ID;
                break;

            case 3:
                cout<< endl << "Nhap du lieu moi:";
                cin >> gv->data.exp;
                break;

            case 4:
                cout<< endl << "Nhap du lieu moi:";
                cin >> gv->data.wexp;
                break;

            default:
                break;
        }

        cout<< endl << "Tiep tuc sua thong tin ?";
        cout<< endl << "1. Co";
        cout<< endl << "2. Khong";
        cin>> k;
    }
    while(k == 1);
}



void TeacherManagement(QLKH* &course){
    string k;
    cout<< "Nhap ten/ID:";
    cin>> k;
    NodeTeacher* ptr = searchTeacher(course.data->);
    displayTeacherInfo(ptr);
    cout << endl << 

}