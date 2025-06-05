#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "StudentStruct.h"

void exportStudentToFile(NodeStudent* S, string& StudentFile) {
    ofstream outfile(StudentFile, ios::out | ios::trunc);
    if (!outfile.is_open()) {
        std::cout << "File dang duoc mo, khong the ghi vao file!" << endl;
        return;
    }
    NodeStudent* current = S;
    while (current != nullptr) {
        outfile << current->data.ID << ","
            << current->data.name << ","
            << current->data.age << ","
            << current->data.level << ","
            << current->data.gender << endl;
        current = current->next;
    }
    outfile.close();
}

NodeStudent* importStudentsFromFile(const string& StudentFile) {
    ifstream infile(StudentFile);
    if (!infile.is_open()) {
        cout << "File dang duoc mo, khong the doc vao file!" << endl;
        return NULL;
    }
    NodeStudent* newList = NULL;
    Student data;
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() == 5) {
            data.ID = tokens[0];
            data.name = tokens[1];
            stringstream ageStream(tokens[2]); ageStream >> data.age;
            data.level = tokens[3];
            data.gender = tokens[4];
            addStudent(newList, data);
        }
    }
    infile.close();
    return newList;
}

void addStudentFromFile(QLKH *&qlkh, const string& StudentFile){
    NodeStudent* newStudents = importStudentsFromFile(StudentFile);
    if (newStudents == NULL) {
        cout << "Khong co du lieu trong file!" << endl;
        return;
    }
    if (qlkh->S == NULL) {
        qlkh->S = newStudents;
    } else {
        NodeStudent* current = qlkh->S;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudents;
    }
    cout << "Da them sinh vien tu file thanh cong!" << endl;
}
