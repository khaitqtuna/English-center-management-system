#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

void exportCoursesToFile(KhoaHoc K, string& KhoaHocFile) {
    ofstream outfile(KhoaHocFile);
    if (!outfile) {
        std::cout << "ERROR: khong the viet vao file!" << endl;
        return;
    }
    QLKH* current = K;
    while (current != nullptr) {
        outfile << current->data.Name << ","
            << current->data.type << "\n";
        current = current->next;
    }
    outfile.close();
}

QLKH* importCoursesFromFile(const string& KhoaHocFile) {
    ifstream infile(KhoaHocFile);
    QLKH* newList = NULL;
    if (!infile) {
        cout << "ERROR: khong the nhap vao file!" << endl;
        return NULL;
    }
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() == 2) {
            string Name = tokens[0];
            string type = tokens[1];
            addKhoaHoc(newList,Name, type);
        }
    }
    infile.close();
    return newList;
}
