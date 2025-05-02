#include <iostream>
using namespace std;

enum Level{
    A1, A2, B1, B2, C1, C2
};

struct Teacher{
    string ID;
    string name;
    Level exp;  //trình độ
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

void changeTeacherInfo(NodeTeacher*& gv){
    
}

