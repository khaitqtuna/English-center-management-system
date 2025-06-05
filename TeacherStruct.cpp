#include <iostream>
#include <string>
#include "Teacher.h"
#include "Class.h"
#include "KHstruct.h"

void initTeacherDS(NodeTeacher* &gv){
    gv = nullptr;
}

NodeTeacher* createNodeTeacher(Teacher data){
    NodeTeacher* newNode = new NodeTeacher;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->classmanage = nullptr;
    return newNode;
}

void addTeacher(NodeTeacher* &gv, Teacher data){
    NodeTeacher *newNode = createNodeTeacher(data);
    if(gv == nullptr){
        gv = newNode;
        return;
    }
    newNode->next = gv;
    gv = newNode;
}

NodeTeacher* searchTeacher(NodeTeacher* &gv, std::string data){       //tìm bằng cả tên và ID
    NodeTeacher* ptr = gv;
    while(ptr != nullptr){
        if(ptr->data.ID == data || ptr->data.name == data)
            return ptr;
        else 
            ptr = ptr->next;
    }
    return nullptr;
}

NodeTeacher* deleteTeacher(NodeTeacher* &gv, std::string data){
    if(gv == nullptr){
        std::cout<< "Danh sach giao vien trong" << std::endl;
        return nullptr;
    }

    NodeTeacher* ptr = searchTeacher(gv, data);
    if(ptr == nullptr){
        std::cout<< "Khong co giao vien can tim" << std::endl;
        return nullptr;
    }

    NodeTeacher *ptr1 = gv;
    while(ptr1 != nullptr && ptr1->next != ptr)        //tra ve phan tu truoc cai can tim
        ptr1 = ptr1->next;
    
    NodeTeacher* temp;
    temp = ptr1->next;
    ptr1->next = ptr->next;
    delete ptr;
    return temp;
}

void displayTeacherInfo(NodeTeacher* gv){
    std::cout<< "1. Ho va ten: " << gv->data.name << std::endl;
    std::cout<< "2. ID: " << gv->data.ID << std::endl;
    std::cout<< "3. Trinh do: " << gv->data.exp << std::endl;
    std::cout<< "4. So nam kinh nghiem: " << gv->data.wexp << std::endl;
}

void displayTeacherList(NodeTeacher* gv){
    if (gv == nullptr) {
        std::cout << "Danh sach giao vien rong." << std::endl;
        return;
    }
    NodeTeacher* ptr = gv;
    std::cout<< "Danh sach giao vien:" << std::endl;
    while(ptr != nullptr){
        std::cout<< ptr->data.name << std::endl;
        ptr = ptr->next;
    }
}

void changeTeacherInfoForCourse(NodeTeacher*& gv){
    int check = 1;
    std::system("cls");

    while (check == 1) {
    	displayTeacherList(gv);
        std::cout << "Nhap ten/ID giao vien ban muon thay doi thong tin: ";
        std::string name;
        std::cin.ignore();  
        std::getline(std::cin, name);  

        NodeTeacher* t = searchTeacher(gv, name);
        if (t == nullptr) 
            std::cout << "Danh sach giao vien rong." << std::endl;
        
        else {
            displayTeacherInfo(t);
            std::cout << "Ban muon thay doi thong tin gi?\n";
            std::cout<< "1. Ten giao vien" << std::endl;
            std::cout<< "2. ID" << std::endl;
            std::cout<< "3. Trinh do" << std::endl;
            std::cout<< "4. So nam kinh nghiem" << std::endl;
            std::cout << "Nhap lua chon: ";
            int choice;
            std::cin >> choice;
            std::cin.ignore();
            switch (choice) {
                case 1: {
                    std::cout << "Nhap ten moi: ";
                    std::string newName;
                    std::getline(std::cin, newName);
                    t->data.name = newName;
                    std::cout << "Thuc hien thanh cong!" << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "Nhap ID moi: ";
                    std::string newID;
                    std::getline(std::cin, newID);
                    t->data.ID = newID;
                    std::cout << "Thuc hien thanh cong!" << std::endl;
                    break;
                }
                case 3: {
                    std::cout << "Nhap trinh do moi: ";
                    std::string newType;
                    std::getline(std::cin, newType);
                    t->data.exp = newType;
                    std::cout << "Thuc hien thanh cong!" << std::endl;
                    break;
                }
                case 4: {
                    std::cout << "Nhap so nam kinh nghiem moi: ";
                    int n;
                    std::cin >> n;
                    t->data.wexp = n;
                    std::cout << "Thuc hien thanh cong!" << std::endl;
                    break;
                }
                default : {
                    std::cout << "Lua chon khong hop le.\n";
                    break;
                }
            }
        }
       
        std::cout << "Ban co muon thay doi thong tin khac khong?" << std::endl;
        std::cout << "1. Co" << std::endl;
        std::cout << "2. Khong" << std::endl;
        std::cout << "Nhap lua chon:";
        std::cin >> check;
        std::system("cls");  
    }
}

void changeTeacherInfo(NodeTeacher*& gv){
    int k = 0;
    do{
        system("cls");
        std::cout << "===== SUA THONG TIN GIAO VIEN =====\n";
        std::cout << "---------------------------------\n";
        std::cout << "Ban muon thay doi thong tin gi?\n";
        std::cout<< "1. Ten giao vien" << std::endl;
        std::cout<< "2. ID" << std::endl;
        std::cout<< "3. Trinh do" << std::endl;
        std::cout<< "4. So nam kinh nghiem" << std::endl;
        std::cout << "Nhap lua chon:";
        int choice;
        std::cin >> choice;
        while(choice < 1 || choice > 4){
            std::cout<< "Lua chon khong hop le, hay nhap lai";
            std::cin>> choice;
        }
        if(choice == 1){
            std::cout << "Nhap ten moi: ";
            std::string newName;
            std::cin.ignore();
            std::getline(std::cin, newName);
            gv->data.name = newName;
        }
        else if(choice == 2){
            std::cout << "Nhap ID moi: ";
            std::string newID;
            std::cin.ignore();
            std::getline(std::cin, newID);
            gv->data.ID = newID;
        }
        else if(choice == 3){
            std::cout << "Nhap trinh do moi: ";
            std::string newType;
            std::cin.ignore();
            std::getline(std::cin, newType);
            gv->data.exp = newType;
        }
        else if(choice == 4){
            std::cout << "Nhap so nam kinh nghiem moi: ";
            int n;
            std::cin >> n;
            gv->data.wexp = n;
        }
        
        std::cout << "Thuc hien thanh cong!" << std::endl;
        std::system("cls");
        std::cout << "\nBan co muon tiep tuc sua thong tin khac khong?" << std::endl;
        std::cout << "1. Co" << std::endl;
        std::cout << "2. Khong"<< std::endl;
        std::cout << "Nhap lua chon:";
        std::cin >> k;
    }
    while(k == 1);
}

void TeacherManagement(QLKH* &course){
    int m = 0;
    do{
        displayTeacherList(course->all);
        std::string k;
        std::cout << "Nhap ten/ID:";
        std::getline(std::cin, k);
        NodeTeacher *key = searchTeacher(course->all, k);

        if(key == nullptr){
            std::cout<< "Khong tim thay giao vien" << std::endl;
            continue;
        }
        std::system("cls");
        std::cout << "===== CHINH SUA THONG TIN GIAO VIEN =====\n";
        displayTeacherInfo(key);
        int choice = 0;
        std::cout<< "Nhap lua chon:" << std::endl;
        std::cout<< "1. Sua thong tin giao vien" << std::endl;
        std::cout<< "2. Xoa thong tin giao vien" << std::endl;
        std::cout<< "3. Quay lai" << std::endl;
        std::cin>> choice;
        while(choice != 1 && choice != 2 && choice != 3){
            std::cout<< "Lua chon khong hop le, hay nhap lai:";
            std::cin>> choice;
        }
        if(choice == 1)
            system("cls"),
            changeTeacherInfo(key);
        else if(choice == 2)
            deleteTeacher(course->all, k);
        else if(choice == 3)
            continue;
        std::system("cls");
        std::cout << "\nBan co muon tiep tuc quan ly giao vien khong?" << std::endl;
        std::cout << "1. Co" << std::endl;
        std::cout << "2. Khong"<< std::endl;
        std::cout << "Nhap lua chon:";
        std::cin >> m;
    }
    while(m == 1);
}
