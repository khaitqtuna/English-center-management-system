#include <iostream>
#include <string>
#include "Student.h"
using namespace std;



void initStudent(NodeStudent*& S) {
    S = NULL;
}

NodeStudent* createNodeStudent(Student data) {
    NodeStudent* NS = new NodeStudent;
    NS->data = data;
    NS->next = NULL;
    return NS;
}

void addStudent(NodeStudent*& S, Student data) {
    NodeStudent* NNS = createNodeStudent(data);
    if (S == NULL) {
        S = NNS;
        return;
    }
    NNS->next = S;
    S = NNS;
}

NodeStudent* searchStudent(NodeStudent*& S, string data) {
    NodeStudent* ptr = S;
    while (ptr != NULL) {
        if (ptr->data.ID == data || ptr->data.name == data)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

Student deleteStudent(NodeStudent*& S, string data) {
    if (S == NULL) {
        cout << "Danh sach hoc sinh trong" << endl;
        return Student();
    }

    if (S->data.ID == data || S->data.name == data) {
        NodeStudent* del = S;
        Student temp = del->data;
        S = S->next;
        delete del;
        return temp;
    }

    NodeStudent* prev = S;
    NodeStudent* curr = S->next;
    while (curr != NULL && !(curr->data.ID == data || curr->data.name == data)) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Khong co hoc sinh can tim" << endl;
        return Student();
    }

    Student temp = curr->data;
    prev->next = curr->next;
    delete curr;
    return temp;
}

void displayStudentInfo(const NodeStudent* S) {
    cout << "1. Ho va ten: " << S->data.name << endl;
    cout << "2. Gioi tinh: " << S->data.gender << endl;
    cout << "3. ID: " << S->data.ID << endl;
    cout << "4. Trinh do: " << S->data.level << endl;
    cout << "5. Tuoi: " << S->data.age << endl;
}

void displayStudentList(NodeStudent *st){
    if (st == NULL) {
        cout << "Danh sach hoc sinh rong." << endl;
        return;
    }
    NodeStudent* ptr = st;
    cout<< "Danh sach hoc sinh:" << endl;
    while(ptr != NULL){
        cout<< ptr->data.name << " - "<< ptr->data.ID<< endl;
        ptr = ptr->next;
    }
}

void changeStudentInfo(NodeStudent*& S){
    int check = 1;
    system("cls");

    while (check == 1) {
    	displayStudentList(S);
        cout << "Nhap ten/ID hoc sinh ban muon thay doi thong tin: ";
        string name;
        cin.ignore();  
        getline(cin, name);  

        NodeStudent* t = searchStudent(S, name);
        if (t == NULL) 
            cout << "Danh sach hoc sinh rong." << endl;
        
        else {
            displayStudentInfo(t);
            cout << "Ban muon thay doi thong tin gi?\n";
            cout<< "1. Ten hoc sinh" << endl;
            cout<< "2. ID" << endl;
            cout<< "3. Tuoi" << endl;
            cout<< "4. Gioi tinh" << endl;
            cout<< "5. Trinh do" << endl;
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
                    cout << "Nhap so tuoi moi: ";
                    int n;
                    cin.ignore();
                    cin>> n;
                    t->data.age = n;
                    break;
                case 4: {
                    cout << "Nhap gioi tinh moi: ";
                    string newType;
                    cin.ignore();
                    getline(cin, newType);
                    t->data.gender = newType;
                    break;
                }
                case 5: {
                    cout << "Nhap trinh do moi: ";
                    string newType;
                    cin.ignore();
                    getline(cin, newType);
                    t->data.level = newType;
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
