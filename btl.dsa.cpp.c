#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void saveClassToFile(NodeClass* head, const string& filename) {
    ofstream out(filename);
    if (!out) {
        cout << "Khong the mo file de ghi!\n";
        return;
    }

    NodeClass* p = head;
    while (p != nullptr) {
        out << p->data.ID << "," << p->data.name << "," << p->data.studentCount << endl;
        p = p->next;
    }

    out.close();
    cout << "Da ghi danh sach lop vao file: " << filename << endl;
}
void loadClassFromFile(NodeClass*& head, const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Khong the mo file de doc!\n";
        return;
    }

    string id, name;
    int count;

    while (getline(in, id, ',') && getline(in, name, ',') && in >> count) {
        in.ignore(); 
        Class c = { id, name, count };
        addClass(head, c);
    }

    in.close();
    cout << "Da doc danh sach lop tu file: " << filename << endl;
}
void saveTeacherToFile(NodeTeacher* head, const string& filename) {
    ofstream out(filename);
    if (!out) {
        cout << "Khong the mo file!\n";
        return;
    }

    NodeTeacher* p = head;
    while (p != nullptr) {
        out << p->data.ID << "," << p->data.name << "," << p->data.exp << "," << p->data.wexp << endl;
        p = p->next;
    }

    out.close();
    cout << "Da ghi danh sach giao vien vao file.\n";
}
void loadTeacherFromFile(NodeTeacher*& head, const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Khong the mo file!\n";
        return;
    }

    string id, name;
    int exp, wexp;

    while (getline(in, id, ',') && getline(in, name, ',') && in >> exp && in.get() && in >> wexp) {
        in.ignore();  
        Teacher t = { id, name, static_cast<Level>(exp), wexp };
        addTeacher(head, t);
    }

    in.close();
    cout << "Da doc danh sach giao vien tu file.\n";
}
void saveStudentToFile(LLS head, const string& filename) {
    ofstream out(filename);
    if (!out) {
        cout << "Khong the mo file!\n";
        return;
    }

    PS p = head;
    while (p != nullptr) {
        out << p->data.ID << "," << p->data.Name << "," << p->data.Age << ","
            << p->data.L << "," << p->data.G << endl;
        p = p->next;
    }

    out.close();
    cout << "Da ghi danh sach hoc vien vao file.\n";
}
void loadStudentFromFile(LLS& head, const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Khong the mo file!\n";
        return;
    }

    string id, name, ageStr;
    int age, levelInt, genderInt;

    while (getline(in, id, ',') && getline(in, name, ',') &&
           getline(in, ageStr, ',') && in >> levelInt && in.get() &&
           in >> genderInt) {
        in.ignore();
        age = stoi(ageStr);
        addStudent(head, id, name, age, static_cast<level>(levelInt), static_cast<gender>(genderInt));
    }

    in.close();
    cout << "Da doc danh sach hoc vien tu file.\n";
}
int main() {
    NodeClass* classList;
    NodeTeacher* teacherList;
    LLS studentList;

    initNodeClass(classList);
    initTeacherDS(teacherList);
    initStudent(studentList);

    // Ghi ví dụ
    saveClassToFile(classList, "class.txt");
    saveTeacherToFile(teacherList, "teacher.txt");
    saveStudentToFile(studentList, "student.txt");

    // Đọc lại
    loadClassFromFile(classList, "class.txt");
    loadTeacherFromFile(teacherList, "teacher.txt");
    loadStudentFromFile(studentList, "student.txt");

    return 0;
}
