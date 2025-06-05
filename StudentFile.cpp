#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

void exportStudentToFile(Student S, string& StudentFile) {
    ofstream outfile(StudentFile);
    if (!outfile) {
        std::cout << "ERROR: khong the viet vao file!" << endl;
        return;
    }
    NodeStudent* current = S;
    while (current != nullptr) {
        outfile << current->data.ID << ","
            << current->data.Name << ","
            << current->data.Age << ","
            << current->data.Level << ","
            << current->data.Gender << "\n";
        current = current->next;
    }
    outfile.close();
}

NodeStudent* importStudentsFromFile(const string& StudentFile) {
    ifstream infile(StudentFile);
    NodeStudent* newList = NULL;
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
        if (tokens.size() == 5) {
            string ID = tokens[0];
            string Name = tokens[1];
            int Age; stringstream ageStream(tokens[2]); ageStream >> Age;
            string Level = tokens[3];
            string Gender = tokens[4];
            addStudent(newList, ID, Name, Age, Level, Gender);
        }
    }
    infile.close();
    return newList;
}
