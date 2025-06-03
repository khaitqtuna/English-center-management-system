#include <iostream>
#include <string>
using namespace std;

#include "ClassStruct.h"

struct Class {
    string ID;
    string name;
    int studentCount;
};

struct NodeClass {
    Class data;
    NodeClass* next;
};


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

void changeClassInfo(NodeClass* s, string ID) {
    while (s != nullptr) {
        if (s->data.ID == ID) {
            cout << "Nhap ten moi: ";
            getline(cin >> ws, s->data.name);
            cout << "Nhap so luong hoc vien moi: ";
            cin >> s->data.studentCount;
            return;
        }
        s = s->next;
    }
    cout << "Khong tim thay lop co ID: " << ID << endl;
}
