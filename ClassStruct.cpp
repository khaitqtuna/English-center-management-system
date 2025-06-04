#include <iostream>
#include <string>
using namespace std;

#include "ClassStruct.h"

void initNodeClass(NodeClass*& s) {
    s = nullptr;
    s->managedBy = nullptr; // Initialize managedBy to nullptr
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
        return nullptr;
    }

    NodeClass* ptr = searchClass(s, data);
    if(ptr == NULL){
        cout<< "Khong co lop can tim" << endl;
        return nullptr;
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

void changeTeacherInfoForCourse(NodeClass* cl){
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

void TeacherClassManagement(QLKH *&course)
{
    int m = 0;
    do
    {
        QLKH *temp = course;
        while (temp->data.classes != NULL){
            displayClassList(temp->data.classes);
            temp = temp->next;
        }
        string k;
        cout << "Nhap ten/ID lop:";
        cin >> k;

        NodeClass *key = NULL;
        QLKH *ptr = course;
        while (ptr != NULL)
        {
            key = searchClass(ptr->data.classes, k);
            if (key != NULL)
                break;
            else
                ptr = ptr->next;
        }

        if (key == NULL)
        {
            cout << "Khong tim thay lop" << endl;
            continue;
        }

        displayClassInfo(key);
        displayTeacherList(ptr->data.teachers);
        int choice = 0;
        cout << "Nhap lua chon:" << endl;
        cout << "1. Them giao vien vao lop" << endl;
        cout << "2. Xoa giao vien khoi lop" << endl;
        cin >> choice;
        while (choice != 1 || choice != 2)
        {
            cout << "Lua chon khong hop le, hayh nhap lai:";
            cin >> choice;
        }
        if (choice == 1){
            string search;
            cout << "Nhap ten/ID giao vien can them: ";
            cin.ignore();
            getline(cin, search);
            NodeTeacher* t = searchTeacher(ptr->data.teachers, search);
            addClass(t->classmanage, key->data);
            addTeacher(key->managedBy, t->data);
            cout << "Da them giao vien vao lop thanh cong!" << endl;
        }
            
        else if (choice == 2)
            deleteTeacher(temp->data.teachers, k);

        cout << "\nBan co muon tiep tuc quan ly giao vien cua lop khong?" << endl;
        cout << "1. Co" << endl;
        cout << "2. Khong" << endl;
        cout << "Nhap lua chon:";
        cin >> m;
    } while (m == 1);
}
