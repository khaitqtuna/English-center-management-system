﻿#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "ClassStruct.h"

void exportClassToFile(NodeClass* C, string& ClassFile) {
    ofstream outfile(ClassFile, ios::out | ios::trunc);
    if (!outfile.is_open()) {
        std::cout << "File dang duoc mo, khong the ghi vao file!" << endl;
        return;
    }
    NodeClass* current = C;
    while (current != nullptr) {
        outfile << current->data.ID << ","
            << current->data.name << ","
            << current->data.studentCount << endl;
        current = current->next;
    }
    outfile.close();
}

NodeClass* importClassFromFile(const string& ClassFile) {
    ifstream infile(ClassFile);
    if (!infile.is_open()) {
        cout << "File dang duoc mo, khong the doc vao file!" << endl;
        return NULL;
    }
    NodeClass* newList = NULL;
    string line;
    Class data;
    while (getline(infile, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() == 3) {
            data.ID = tokens[0];
            data.name = tokens[1];
            stringstream studentCountStream(tokens[2]); studentCountStream >> data.studentCount;
            addStudent(newList, data);
        }
    }
    infile.close();
    return newList;
}
