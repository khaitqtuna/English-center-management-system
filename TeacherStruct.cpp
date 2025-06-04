#include <iostream>
#include <string>
using namespace std;

#include "TeacherStruct.h"
#include "ClassStruct.h"
#include "KHstruct.h"

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

NodeTeacher* deleteTeacher(NodeTeacher* &gv, string data){
    if(gv == NULL){
        std::cout<< "Danh sach giao vien trong" << endl;
        return nullptr;
    }

    NodeTeacher* ptr = searchTeacher(gv, data);
    if(ptr == NULL){
        std::cout<< "Khong co giao vien can tim" << endl;
        return nullptr;
    }

    NodeTeacher *ptr1 = gv;
    while(ptr1 != NULL && ptr1->next != ptr)        //tra ve phan tu truoc cai can tim
        ptr1 = ptr1->next;
    
    NodeTeacher* temp;
    temp = ptr1->next;
    ptr1->next = ptr->next;
    delete ptr;
    return temp;
}

void displayTeacherInfo(NodeTeacher* gv){
    std::cout<< "1. Ho va ten: " << gv->data.name << endl;
    std::cout<< "2. ID: " << gv->data.ID << endl;
    std::cout<< "3. Trinh do: " << gv->data.exp << endl;
    std::cout<< "4. So nam kinh nghiem: " << gv->data.wexp << endl;
}

void displayTeacherList(NodeTeacher* gv){
    if (gv == NULL) {
        std::cout << "Danh sach giao vien rong." << endl;
        return;
    }
    NodeTeacher* ptr = gv;
    std::cout<< "Danh sach giao vien:" << endl;
    while(ptr != NULL){
        std::cout<< ptr->data.name << endl;
        ptr = ptr->next;
    }
}

void changeTeacherInfoForCourse(NodeTeacher*& gv){
    int check = 1;
    std::system("cls");

    while (check == 1) {
    	displayTeacherList(gv);
        std::cout << "Nhap ten/ID giao vien ban muon thay doi thong tin: ";
        string name;
        std::cin.ignore();  
        getline(std::cin, name);  

        NodeTeacher* t = searchTeacher(gv, name);
        if (t == NULL) 
            std::cout << "Danh sach giao vien rong." << endl;
        
        else {
            displayTeacherInfo(t);
            std::cout << "Ban muon thay doi thong tin gi?\n";
            std::cout<< "1. Ten giao vien" << endl;
            std::cout<< "2. ID" << endl;
            std::cout<< "3. Trinh do" << endl;
            std::cout<< "4. So nam kinh nghiem" << endl;
            std::cout << "Nhap lua chon: ";
            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    std::cout << "Nhap ten moi: ";
                    string newName;
                    std::cin.ignore();
                    getline(std::cin, newName);
                    t->data.name = newName;
                    break;
                }
                case 2: {
                    std::cout << "Nhap ID moi: ";
                    string newID;
                    std::cin.ignore();
                    getline(std::cin, newID);
                    t->data.ID = newID;
                    break;
                }
                case 3: {
                    std::cout << "Nhap trinh do moi: ";
                    string newType;
                    std::cin.ignore();
                    getline(std::cin, newType);
                    t->data.exp = newType;
                    break;
                }
                case 4: {
                    std::cout << "Nhap so nam kinh nghiem moi: ";
                    int n;
                    std::cin.ignore();
                    std::cin>> n;
                    t->data.wexp = n;
                    break;
                }
				default : {
                    std::cout << "Lua chon khong hop le.\n";
                    break;
                }
            }
        }
       
        std::cout << "Ban co muon thay doi thong tin khac khong?" << endl;
        std::cout << "1. Co" << endl;
        std::cout << "2. Khong" << endl;
        std::cout << "Nhap lua chon:";
        std::cin >> check;
        std::system("cls");  
    }
}

void changeTeacherInfo(NodeTeacher*& gv){
    int k = 0;
    do{
        std::cout << "Ban muon thay doi thong tin gi?\n";
        std::cout<< "1. Ten giao vien" << endl;
        std::cout<< "2. ID" << endl;
        std::cout<< "3. Trinh do" << endl;
        std::cout<< "4. So nam kinh nghiem" << endl;
        std::cout << "Nhap lua chon:";
        int choice;
        std::cin >> choice;
        while(choice < 1 || choice > 4){
            std::cout<< "Lua chon khong hop le, hay nhap lai";
            std::cin>> choice;
        }
        if(choice == 1){
            std::cout << "Nhap ten moi: ";
            string newName;
            std::cin.ignore();
            getline(std::cin, newName);
            gv->data.name = newName;
        }
        else if(choice == 2){
            std::cout << "Nhap ID moi: ";
            string newID;
            std::cin.ignore();
            getline(std::cin, newID);
            gv->data.ID = newID;
        }
        else if(choice == 3){
            std::cout << "Nhap trinh do moi: ";
            string newType;
            std::cin.ignore();
            getline(std::cin, newType);
            gv->data.exp = newType;
        }
        else if(choice == 4){
            std::cout << "Nhap so nam kinh nghiem moi: ";
            int n;
            std::cin.ignore();
            std::cin>> n;
            gv->data.wexp = n;
        }

        std::cout << "\nBan co muon tiep tuc sua thong tin khac khong?" << endl;
        std::cout << "1. Co" << endl;
        std::cout << "2. Khong"<< endl;
        std::cout << "Nhap lua chon:";
        std::cin >> k;
    }
    while(k == 1);
}

void TeacherManagement(QLKH* &course){
    int m = 0;
    do{
        displayTeacherList(course->all);
        string k;
        cout << "Nhap ten/ID:";
        cin >> k;

        QLKH *temp = course;
        NodeTeacher *key = NULL;
        while (temp->all != NULL)
        {
            key = searchTeacher(temp->all, k);
            if (key != NULL)
                break;
            else
                temp->all = temp->all->next;
        }

        if(key == NULL){
            std::cout<< "Khong tim thay giao vien" << endl;
            continue;
        }

        displayTeacherInfo(key);
        int choice = 0;
        std::cout<< "Nhap lua chon:" << endl;
        std::cout<< "1. Sua thong tin giao vien" << endl;
        std::cout<< "2. Xoa thong tin giao vien" << endl;
        std::cin>> choice;
        while(choice != 1 || choice!= 2){
            std::cout<< "Lua chon khong hop le, hayh nhap lai:";
            std::cin>> choice;
        }
        if(choice == 1)
            changeTeacherInfo(key);
        else if(choice == 2)
            deleteTeacher(temp->data.teachers, k);

        std::cout << "\nBan co muon tiep tuc quan ly giao vien khong?" << endl;
        std::cout << "1. Co" << endl;
        std::cout << "2. Khong"<< endl;
        std::cout << "Nhap lua chon:";
        std::cin >> m;
        }
    while(m == 1);
}
