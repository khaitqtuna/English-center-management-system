#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

void exportCoursesToFile(KhoaHoc K, string& KhoaHocFile) {
    ofstream outfile(KhoaHocFile, ios::out | ios::trunc);
    if (!outfile..is_open()) {
        std::cout << "File dang duoc mo, khong the ghi vao file!" << endl;
        return;
    }
    QLKH* current = K;
    while (current != nullptr) {
        outfile << current->data.Name << "," 
            << current->data.ID << ","
            << current->data.type << "endl";
        current = current->next;
    }
    outfile.close();
}

QLKH* importCoursesFromFile(const string& KhoaHocFile) {
    ifstream infile(KhoaHocFile);
    QLKH* newList = NULL;
    if (!infile.is_open()) {
        cout << "File dang duoc mo, khong the doc vao file!" << endl;
        return NULL;
    }
    KhoaHoc data;
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() == 3) {
            data.Name = tokens[0];
            data.ID = tokens[1];
            data.type = tokens[2];
            addKhoaHoc(newList, data);
        }
    }
    infile.close();
    return newList;
}
