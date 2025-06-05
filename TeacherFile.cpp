﻿#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "TeacherStruct.h"

void exportTeacherToFile(TeacherStudent* T, string& TeacherFile) {
    ofstream outfile(TeacherFile, ios::out | ios::trunc);
    if (!outfile.is_open()) {
        std::cout << "File dang duoc mo, khong the ghi vao file!" << endl;
        return;
    }
    NodeTeacher* current = T;
    while (current != nullptr) {
        outfile << current->data.ID << ","
            << current->data.name << ","
            << current->data.exp << ","
            << current->data.wexp << endl;
        current = current->next;
    }
    outfile.close();
}

NodeTeacher* importTeacherFromFile(const string& TeacherFile) {
    ifstream infile(TeacherFile);
    if (!infile.is_open()) {
        cout << "File dang duoc mo, khong the doc vao file!" << endl;
        return NULL;
    }
    NodeTeacher* newList = NULL;
    Teacher data;
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() == 4) {
            data.ID = tokens[0];
            data.name = tokens[1];
            data.exp = tokens[2];            
            stringstream wexpStream(tokens[3]); wexpStream >> data.wexp;
            addStudent(newList, data);
        }
    }
    infile.close();
    return newList;
}
