#include <iostream>
#include <string>
using namespace std;

#include "StudentStruct.h"

struct Student {
	string ID;
	string name;
	int age;
	string level;
	string gender;
};

struct NodeStudent {
    Student data;
    NodeStudent* next;
};

void initStudent(NodeStudent*& S) {
	S = NULL;
}

NodeStudent* createNodeStudent(Student data) {
	NodeStudent* NS = new NodeStudent;//NewStudent
    NS->data = data;
	NS->next = NULL;
	return NS;
}

void addStudent(NodeStudent*& S, Student data) {
	NodeStudent* NNS = createNodeStudent(data);//NewNodeStudent
    if(S->next == NULL){
        S = NNS;
        return;
    }
    NNS->next = S;
	S = NNS;
}

NodeStudent* searchStudent(NodeStudent* &S, string data) {
    NodeStudent* ptr = S;
    while (ptr != NULL) {
        if (ptr->data.ID == data)
            return ptr;
        else if(ptr->data.name == data)
            return ptr; 
        else
            ptr = ptr->next;
    }
    return NULL;
}

Student deleteStudent(NodeStudent*& S, string data) {
    if(S == NULL){
        cout<< "Danh sach hoc sinh trong" << endl;
        return;
    }

    NodeStudent* ptr = searchStudent(S, data);
    if(ptr == NULL){
        cout<< "Khong co hoc sinh can tim" << endl;
        return;
    }

    NodeStudent *ptr1 = S;
    while(ptr1 != NULL && ptr1->next != ptr)        //tra ve phan tu truoc cai can tim
        ptr1 = ptr1->next;
    
    Student temp;
    temp = ptr1->next->data;
    ptr1->next = ptr->next;
    delete ptr;
    return temp;
}

void displayStudentInfo(NodeStudent*& S) {
    cout<< "1. Ho va ten: " << S->data.name << endl;
    cout<< "2. Gioi tinh: " << S->data.gender << endl;
    cout<< "3. ID: " << S->data.ID << endl;
    cout<< "4. Trinh do: " << S->data.level << endl;
    cout<< "5. Tuoi: " << S->data.age << endl;
}


//void changeStudentInfo(NodeStudent* S, int ID) {
//    NodeStudent* target = searchStudent(S, ID);
//    if (target == NULL) {
//        cout << "No ID: " << ID << endl;
//        return;
//    }
//    cout << "insert ID " << ID << ":\n";
//    cout << "name: "; cin.ignore(); getline(cin, target->name);
//    cout << "age: "; cin >> target->age;
//    int newstring;    //ko gan duoc truc tiep enum nen su dung mot thong so trung gian
//    cout << "string: "; cin >> newstring;
//    target->L = static_cast<string>(newstring);
//
//    int newGender; cout << "Gender: "; cin >> newGender;//ko gan duoc truc tiep enum nen su dung mot thong so trung gian
//    target->G = static_cast<gender>(newGender);
//
//    cout << "update! New ID: " << ID << endl;
//}




