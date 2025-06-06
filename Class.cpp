#include <iostream>
#include <string>
#include "Student.h" 
#include "Class.h"
#include "Teacher.h"
#include <vector>
#include <algorithm>
#include <iomanip>

void initNodeClass(NodeClass*& s) {
    s = nullptr;
}


NodeClass* createNodeClass(Class data) {
    NodeClass* node = new NodeClass;
    node->data = data;
    node->next = nullptr;
    node->data.listStudent = nullptr; // Initialize the student list to nullptr
    node->data.studentCount = 0; // Initialize student count to 0
    node->data.teacher = Teacher(); // Initialize teacher to default
    return node;
}


void addClass(NodeClass*& s, Class data) {
    NodeClass* newNode = createNodeClass(data);
    if(s == nullptr){
        s = newNode;
        return;
    }
    NodeClass* tail = s;
    while (tail->next != nullptr) tail = tail->next;
    tail->next = newNode;
}


NodeClass* searchClass(NodeClass* s, std::string data) {
    NodeClass* ptr = s;
    while (ptr != nullptr) {
        if(ptr->data.ID == data || ptr->data.name == data)
            return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}


Class deleteClass(NodeClass*& s, std::string data) {
    if(s == nullptr){
        std::cout<< "Danh sach lop trong" << std::endl;
        return Class();
    }

    if (s->data.ID == data || s->data.name == data) {
        NodeClass* del = s;
        Class temp = del->data;
        s = s->next;
        delete del;
        return temp;
    }

    NodeClass* prev = s;
    NodeClass* curr = s->next;
    while(curr != nullptr && !(curr->data.ID == data || curr->data.name == data)) {
        prev = curr;
        curr = curr->next;
    }

    if(curr == nullptr){
        std::cout<< "Khong co lop can tim" << std::endl;
        return Class();
    }

    Class temp = curr->data;
    prev->next = curr->next;
    delete curr;
    return temp;
}



void displayClassInfo(NodeClass* cl){
    std::cout << std::left;
    std::cout << std::setw(20) << "Ten lop:" << cl->data.name << std::endl;
    std::cout << std::setw(20) << "ID:" << cl->data.ID << std::endl;
    std::cout << std::setw(20) << "Si so:" << cl->data.studentCount << std::endl;
    std::cout << std::setw(20) << "Giao vien:" << cl->data.teacher.name << std::endl;
    displayStudentList(cl->data.listStudent);
}

void displayClassList(NodeClass* cl){
    if (cl == nullptr) {
        std::cout << "\n================ DANH SACH LOP ================\n";
        std::cout << "Danh sach lop rong." << std::endl;
        std::cout << "===============================================\n";
        return;
    }
    std::vector<NodeClass*> classes;
    NodeClass* ptr = cl;
    while(ptr != nullptr){
        classes.push_back(ptr);
        ptr = ptr->next;
    }
    std::sort(classes.begin(), classes.end(), [](NodeClass* a, NodeClass* b){
        return a->data.ID < b->data.ID;
    });
    std::cout << "\n================ DANH SACH LOP ================\n";
    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(25) << "Ten"
              << std::setw(10) << "Si so" << std::endl;
    std::cout << std::setfill('-') << std::setw(45) << "" << std::setfill(' ') << std::endl;
    for (auto c : classes) {
        std::cout << std::left << std::setw(10) << c->data.ID
                  << std::setw(25) << c->data.name
                  << std::setw(10) << c->data.studentCount << std::endl;
    }
    std::cout << "===============================================\n";
}

void changeClassInfo(NodeClass*& cl){
    int check = 1;
    system("cls");

    while (check == 1) {
        displayClassList(cl);

        if (cl == nullptr) {
            std::cout << "Khong tim thay lop." << std::endl;
        } else {
            displayClassInfo(cl);
            std::cout << "\nBan muon thay doi thong tin gi?\n";
            std::cout << "1. Ten lop" << std::endl;
            std::cout << "2. ID lop" << std::endl;
            std::cout << "3. Thay doi thong tin sinh vien" << std::endl;
            std::cout << "0. Quay lai" << std::endl;
            std::cout << "Nhap lua chon: ";
            int choice;
            std::cin >> choice;
            std::cin.ignore();
            switch (choice) {
                case 1: {
                    std::cout << "Nhap ten moi: ";
                    std::string newName;
                    std::getline(std::cin, newName);
                    cl->data.name = newName;
                    break;
                }
                case 2: {
                    std::cout << "Nhap ID moi: ";
                    std::string newID;
                    std::getline(std::cin, newID);
                    if (searchClass(cl, newID) != nullptr) {
                        std::cout << "ID lop da ton tai! Vui long nhap ID khac.\n";
                        break;
                    }
                    cl->data.ID = newID;
                    break;
                }
                case 3: {
                    int svChoice;
                    do {
                        system("cls");
                        std::cout << "\n--- QUAN LY SINH VIEN TRONG LOP ---\n";
                        std::cout << "1. Them sinh vien" << std::endl;
                        std::cout << "2. Sua thong tin sinh vien" << std::endl;
                        std::cout << "3. Xoa sinh vien" << std::endl;
                        std::cout << "0. Quay lai" << std::endl;
                        std::cout << "Nhap lua chon: ";
                        std::cin >> svChoice;
                        std::cin.ignore();
                        if (svChoice == 1) {
                            Student newStudentData;
                            std::cout << "Nhap ID sinh vien: ";
                            std::getline(std::cin, newStudentData.ID);
                            if (newStudentData.ID.empty()) {
                                std::cout << "ID khong duoc de trong!\n";
                                break;
                            }
                            if (searchStudent(cl->data.listStudent, newStudentData.ID) != nullptr) {
                                std::cout << "ID sinh vien da ton tai! Vui long nhap ID khac.\n";
                                break;  
                            }
                            std::cout << "Nhap ten sinh vien: ";
                            std::getline(std::cin, newStudentData.name);
                            std::cout << "Nhap tuoi sinh vien: ";
                            std::cin >> newStudentData.age;
                            std::cin.ignore();
                            std::cout << "Nhap gioi tinh sinh vien: ";
                            std::getline(std::cin, newStudentData.gender);
                            std::cout << "Nhap trinh do sinh vien: ";
                            std::getline(std::cin, newStudentData.level);
                            addStudent(cl->data.listStudent, newStudentData);
                            cl->data.studentCount++;
                            std::cout << "Da them sinh vien thanh cong!" << std::endl;
                        } else if (svChoice == 2) {
                            if (cl->data.listStudent == nullptr) {
                                std::cout << "Lop hien tai chua co sinh vien.\n";
                            } else {
                                changeStudentInfo(cl->data.listStudent);
                            }
                        } else if (svChoice == 3) {
                            if (cl->data.listStudent == nullptr) {
                                std::cout << "Lop hien tai chua co sinh vien.\n";
                            } else {
                                std::cout << "Nhap ID hoac ten sinh vien can xoa: ";
                                std::string stuKey;
                                std::getline(std::cin, stuKey);
                                Student deleted = deleteStudent(cl->data.listStudent, stuKey);
                                if (deleted.ID != "" || deleted.name != "") {
                                    cl->data.studentCount--;
                                    std::cout << "Da xoa sinh vien thanh cong!\n";
                                }
                            }
                        }
                        else if (svChoice == 0) {
                            std::cout << "Quay lai menu quan ly lop.\n";
                        } else {
                            std::cout << "Lua chon khong hop le. Vui long chon lai.\n";
                        }   
                    } while (svChoice != 0);
                    break;
                }
                case 0: {
                    std::cout << "Quay lai menu chinh.\n";
                    check = 0;
                    break;
                }
                default : {
                    std::cout << "Lua chon khong hop le.\n";
                    break;
                }
            }
        }
    }
}

