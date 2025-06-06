#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
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

    // N?u ph?n t? �?u l� ph?n t? c?n x�a
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

void displayStudentInfo(NodeStudent* S) {
    if (S == NULL) {
        cout << "Khong co thong tin sinh vien de hien thi." << endl;
        return;
    }
    cout << "-----------------------------" << endl;
    cout << "ID         : " << S->data.ID << endl;
    cout << "Ho va ten  : " << S->data.name << endl;
    cout << "Tuoi       : " << S->data.age << endl;
    cout << "Gioi tinh  : " << S->data.gender << endl;
    cout << "Trinh do   : " << S->data.level << endl;
    cout << "-----------------------------" << endl;
}


void changeStudentInfo(NodeStudent*& S) {
    if (S == NULL) {
        cout << "Danh sach hoc sinh trong!" << endl;
        return;
    }

    NodeStudent* temp = S;
    cout << "Danh sach hoc sinh hien tai:\n";
    while (temp != NULL) {
        cout << "- " << temp->data.ID << " | " << temp->data.name << endl;
        temp = temp->next;
    }
    int check = 1;

    while (check == 1) {
        cout << "Nhap ID hoac Ten hoc sinh can thay doi thong tin: ";
        string input;
        getline(cin, input);

        NodeStudent* target = searchStudent(S, input);
        if (target == NULL) {
            cout << "Khong tim thay hoc sinh \"" << input << "\".\n";
        } else {
            displayStudentInfo(target);
            cout << "---------------------------------\n";
            cout << "\nBan muon thay doi thong tin gi?\n";
            cout << "1. Ho va ten\n";
            cout << "2. Tuoi\n";
            cout << "3. Gioi tinh\n";
            cout << "4. Trinh do\n";
            cout << "5. ID\n";
            cout << "6. Tat ca\n";
            cout << "0. Quay lai menu chinh\n";
            cout << "---------------------------------\n";
            cout << "Nhap lua chon: ";
            int choice;
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << "Nhap ho va ten moi: ";
                    getline(cin, target->data.name);
                    break;
                case 2:
                    cout << "Nhap tuoi moi: ";
                    cin >> target->data.age;
                    cin.ignore();
                    break;
                case 3:
                    cout << "Nhap gioi tinh moi: ";
                    getline(cin, target->data.gender);
                    break;
                case 4:
                    cout << "Nhap trinh do moi: ";
                    getline(cin, target->data.level);
                    break;
                case 5: {
                    cout << "Nhap ID moi: ";
                    string newID;
                    getline(cin, newID);
                    if(searchStudent(S, newID) != NULL) {
                        cout << "ID sinh vien da ton tai! Vui long nhap ID khac.\n";
                        break;
                    }
                    target->data.ID = newID;
                    break;
                }
                case 6:
                    cout << "Nhap ho va ten moi: ";
                    getline(cin, target->data.name);
                    cout << "Nhap tuoi moi: ";
                    cin >> target->data.age;
                    cin.ignore();
                    cout << "Nhap gioi tinh moi: ";
                    getline(cin, target->data.gender);
                    cout << "Nhap trinh do moi: ";
                    getline(cin, target->data.level);
                    cout << "Nhap ID moi: ";
                    {
                        string newID;
                        getline(cin, newID);
                        if(searchStudent(S, newID) != NULL) {
                            cout << "ID sinh vien da ton tai! Vui long nhap ID khac.\n";
                            break;
                        }
                        target->data.ID = newID;
                    }
                    break;
                case 0:
                    cout << "Quay lai menu chinh.\n";
                    return;
                default:
                    cout << "Lua chon khong hop le.\n";
                    break;
            }

            cout << "Thong tin da duoc cap nhat!\n";
        }
        system("cls");
    }
}

void displayStudentList(NodeStudent* S) {
    if (S == NULL) {
        system("cls");
        cout << "\n================ DANH SACH HOC VIEN ================\n";
        cout << "Danh sach hoc vien rong." << endl;
        cout << "===================================================\n";
        return;
    }
    system("cls");
    cout << "\n================ DANH SACH HOC VIEN ================\n";
    std::vector<NodeStudent*> students;
    NodeStudent* ptr = S;
    while(ptr != NULL){
        students.push_back(ptr);
        ptr = ptr->next;
    }
    std::sort(students.begin(), students.end(), [](NodeStudent* a, NodeStudent* b){
        return a->data.ID < b->data.ID;
    });
    cout << std::left << std::setw(10) << "ID"
         << std::setw(25) << "Ten"
         << std::setw(5) << "Tuoi"
         << std::setw(10) << "Gioi tinh"
         << std::setw(15) << "Trinh do" << endl;
    cout << std::setfill('-') << std::setw(65) << "" << std::setfill(' ') << endl;
    for (auto s : students) {
        cout << std::left << std::setw(10) << s->data.ID
             << std::setw(25) << s->data.name
             << std::setw(5) << s->data.age
             << std::setw(10) << s->data.gender
             << std::setw(15) << s->data.level << endl;
    }
    cout << "===================================================\n";
}

