#include <iostream>
#include <string>
#include "Teacher.h"
#include "Class.h"
#include "KHstruct.h"
#include <iomanip> // Thêm thư viện iomanip để sử dụng std::setw và std::left
#include <vector>
#include <algorithm>

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
    std::cout << std::left;
    std::cout << std::setw(20) << "1. Ho va ten:" << gv->data.name << std::endl;
    std::cout << std::setw(20) << "2. ID:" << gv->data.ID << std::endl;
    std::cout << std::setw(20) << "3. Trinh do:" << gv->data.exp << std::endl;
    std::cout << std::setw(20) << "4. So nam kinh nghiem:" << gv->data.wexp << std::endl;
}

void displayTeacherList(NodeTeacher* gv){
    if (gv == nullptr) {
        std::cout << "\n================ DANH SACH GIAO VIEN ================\n";
        std::cout << "Danh sach giao vien rong." << std::endl;
        std::cout << "====================================================\n";
        return;
    }
    // Thu thập dữ liệu vào vector để sắp xếp
    std::vector<NodeTeacher*> teachers;
    NodeTeacher* ptr = gv;
    while(ptr != nullptr){
        teachers.push_back(ptr);
        ptr = ptr->next;
    }
    std::sort(teachers.begin(), teachers.end(), [](NodeTeacher* a, NodeTeacher* b){
        return a->data.ID < b->data.ID;
    });
    std::cout << "\n================ DANH SACH GIAO VIEN ================\n";
    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(25) << "Ten"
              << std::setw(20) << "Trinh do"
              << std::setw(10) << "Nam KN" << std::endl;
    std::cout << std::setfill('-') << std::setw(65) << "" << std::setfill(' ') << std::endl;
    for (auto t : teachers) {
        std::cout << std::left << std::setw(10) << t->data.ID
                  << std::setw(25) << t->data.name
                  << std::setw(20) << t->data.exp
                  << std::setw(10) << t->data.wexp << std::endl;
    }
    std::cout << "====================================================\n";
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
        std::cout<< "---------------------------------\n";
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
            if(searchTeacher(gv, newID) != nullptr){
                std::cout << "ID giao vien da ton tai! Vui long nhap ID khac.\n";
                return;
            }
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
        std::cout<< "3. Quan ly lop cua giao vien" << std::endl;
        std::cout<< "---------------------------------\n";  
        std::cout<< "0. Quay lai" << std::endl;
        std::cin>> choice;
        std::cin.ignore();
        while(choice != 1 && choice != 2 && choice != 3 && choice != 0){
            std::cout<< "Lua chon khong hop le, hay nhap lai:";
            std::cin>> choice;
            std::cin.ignore();
        }
        if(choice == 1) {
            system("cls");
            changeTeacherInfo(key);
        } else if(choice == 2) {
            deleteTeacher(course->all, k);
        } else if(choice == 3) {
            TeacherCLManagement(course);
        } else if(choice == 0) {
            std::cout << "Quay lai menu quan ly giao vien." << std::endl;
            break;
        }
        std::system("cls");
        std::cout << "\nBan co muon tiep tuc quan ly giao vien khong?" << std::endl;
        std::cout << "1. Co" << std::endl;
        std::cout << "2. Khong"<< std::endl;
        std::cout << "Nhap lua chon:";
        std::cin >> m;
        std::cin.ignore();
    }
    while(m == 1);
}


void TeacherCLManagement(QLKH* &course) {
    if (course->all == nullptr) {
        std::cout << "Khong co giao vien nao de quan ly." << std::endl;
        return;
    }
    int choice;
    do {
        system("cls");
        displayTeacherList(course->all);
        std::cout << "1. Them lop cho giao vien\n";
        std::cout << "2. Xoa lop cua giao vien\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Nhap lua chon: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                system("cls");
                std::cout << "===== THEM LOP CHO GIAO VIEN =====\n";
                displayTeacherList(course->all); 
                if (course->all == nullptr) {
                    std::cout << "Khong co giao vien nao." << std::endl;
                    std::cout << "Nhap bat ki de quay lai menu quan ly giao vien." << std::endl;
                    std::string temp;
                    getline(std::cin, temp);
                    return;
                }

                std::cout << "Nhap ten hoac ID giao vien can them lop: ";
                std::string ID;
                getline(std::cin, ID);
                NodeTeacher* teacher = searchTeacher(course->all,ID);
                if (teacher == nullptr) {
                    std::cout << "Khong tim thay giao vien voi ID: " << ID << std::endl;
                    break;
                }
                Class newClass; 
                HTQLKH(course);
                std::string KHID;
                std::cout << "Nhap ID khoa hoc cua lop can them: ";
                getline(std::cin,KHID);
                QLKH* kh = seachKhoaHoc(course, KHID);
                system("cls");
                if (kh == nullptr) {
                    std::cout << "Khong tim thay khoa hoc voi ID: " << KHID << std::endl;
                    break;
                }
                if (kh->data.classes == nullptr) {
                    std::cout << "Khong co lop nao trong khoa hoc nay." << std::endl;
                    std::cout << "Nhap bat ki de quay lai menu quan ly giao vien." << std::endl;
                    std::string temp;
                    getline(std::cin, temp);
                    return;
                }
                std::string newClassID;
                displayClassList(kh->data.classes);
                std::cout << "Nhap ID lop: ";
                getline(std::cin, newClassID);
                NodeClass* find = searchClass(kh->data.classes, newClassID);
                if (find == nullptr) {
                    std::cout << "Khong tim thay lop voi ID: " << newClassID << std::endl;
                    break;
                }
                find->data.teacher = teacher->data; 
                NodeClass* newClass1 = createNodeClass(find->data);
                if (teacher->classmanage == nullptr) {
                    teacher->classmanage = newClass1;
                } else {
                    NodeClass* temp = teacher->classmanage;
                    while (temp->next != nullptr) {
                        temp = temp->next;
                    }
                    temp->next = newClass1;
                }
                newClass1->next = nullptr; // Đảm bảo nút mới là nút cuối cùng
                std::cout << "Da them lop \"" << newClassID << "\" vao giao vien \"" << teacher->data.name << "\"." << std::endl;
                std::cout << "Nhap bat ki de quay lai menu quan ly giao vien." << std::endl;
                break;
            }
            case 2: {
                system("cls");
                std::cout << "===== XOA LOP CUA GIAO VIEN =====\n";
                displayTeacherList(course->all);
                std::string ID;
                std::cout << "Nhap ID giao vien: ";
                getline(std::cin, ID);
                NodeTeacher* teacher = searchTeacher(course->all, ID);
                if (teacher == nullptr) {
                    std::cout << "Khong tim thay giao vien voi ID: " << ID << std::endl;
                    break;
                }
                std::cout << "Nhap ten hoac ID lop can xoa: ";
                std::string classID;
                getline(std::cin, classID); 
                NodeClass* classToDelete = searchClass(teacher->classmanage, classID);
                if (classToDelete == nullptr) {
                    std::cout << "Khong tim thay lop \"" << classID << "\" de xoa." << std::endl;
                    break;
                }
                if (teacher->classmanage == classToDelete) {
                    teacher->classmanage = classToDelete->next; // Xóa lớp đầu tiên
                    delete classToDelete;
                } else {
                    NodeClass* temp = teacher->classmanage;
                    while (temp->next != classToDelete && temp->next != nullptr) {
                        temp = temp->next;
                    }
                    if (temp->next == nullptr) {
                        std::cout << "Khong tim thay lop \"" << classID << "\" trong danh sach." << std::endl;
                        break;
                    }
                    temp->next = classToDelete->next; 
                    delete classToDelete;
                }
                break;
            }
            case 0:
                std::cout << "Quay lai menu quan ly." << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le!" << std::endl;
        }
    } while (choice != 0);
}

