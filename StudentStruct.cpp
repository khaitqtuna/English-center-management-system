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

    cout << "\nBan co muon thay doi thong tin hoc sinh?\n";
    cout << "1. Co\n";
    cout << "2. Khong\n";
    cout << "Nhap lua chon cua ban: ";
    int check;
    cin >> check;
    cin.ignore();
    system("cls");

    while (check == 1) {
        cout << "Nhap ID hoac Ten hoc sinh can thay doi thong tin: ";
        string input;
        getline(cin, input);

        NodeStudent* target = searchStudent(S, input);
        if (target == NULL) {
            cout << "Khong tim thay hoc sinh \"" << input << "\".\n";
        } else {
            displayStudentInfo(target);
            cout << "\nBan muon thay doi thong tin gi?\n";
            cout << "1. Ho va ten\n";
            cout << "2. Tuoi\n";
            cout << "3. Gioi tinh\n";
            cout << "4. Trinh do\n";
            cout << "5. Tat ca\n";
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
                case 5:
                    cout << "Nhap ho va ten moi: ";
                    getline(cin, target->data.name);
                    cout << "Nhap tuoi moi: ";
                    cin >> target->data.age;
                    cin.ignore();
                    cout << "Nhap gioi tinh moi: ";
                    getline(cin, target->data.gender);
                    cout << "Nhap trinh do moi: ";
                    getline(cin, target->data.level);
                    break;
                default:
                    cout << "Lua chon khong hop le.\n";
                    break;
            }

            cout << "Thong tin da duoc cap nhat!\n";
        }

        cout << "\nBan co muon thay doi thong tin khac khong?\n";
        cout << "1. Co\n";
        cout << "2. Khong\n";
        cout << "Nhap lua chon: ";
        cin >> check;
        cin.ignore();
        system("cls");
    }
} 

