#include <fstream>
#include <iostream>
#include <sstream>
#include "KHstruct.h"
#include "Class.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;

// Luu toàn b? d? li?u vào file
void writeDataToFile(QLKH* dsKhoaHoc, const string& filename) {
    cout << "[DEBUG] Bat dau ghi file..." << endl;
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "[DEBUG] Mo file that bai!" << endl;
        return;
    }
    QLKH* kh = dsKhoaHoc;
    if (!kh) cout << "[DEBUG] dsKhoaHoc rong!" << endl;
    while (kh) {
        out << "KHOAHOC|" << kh->data.ID << '|' << kh->data.Name << '|' << kh->data.type << '\n';
        // Luu giáo viên c?a khoá h?c
        NodeTeacher* t = kh->data.teachers;
        while (t) {
            out << "TEACHER|" << t->data.ID << '|' << t->data.name << '|' << t->data.exp << '|' << t->data.wexp << '\n';
            t = t->next;
        }
        // Luu l?p h?c c?a khoá h?c
        NodeClass* c = kh->data.classes;
        while (c) {
            out << "CLASS|" << c->data.ID << '|' << c->data.name << '|' << c->data.studentCount << '|';
            out << c->data.teacher.ID << '\n';
            // Luu h?c viên c?a l?p
            NodeStudent* s = c->data.listStudent;
            while (s) {
                out << "STUDENT|" << s->data.ID << '|' << s->data.name << '|' << s->data.age << '|' << s->data.gender << '|' << s->data.level << '\n';
                s = s->next;
            }
            c = c->next;
        }
        // Luu danh sách giáo viên t?ng h?p
        NodeTeacher* all = kh->all;
        while (all) {
            out << "ALLTEACHER|" << all->data.ID << '|' << all->data.name << '|' << all->data.exp << '|' << all->data.wexp << '\n';
            all = all->next;
        }
        kh = kh->next;
    }
    out.close();
    cout << "[DEBUG] Ghi file xong!" << endl;
}

// Ð?c l?i toàn b? d? li?u t? file (gi? d?nh file dúng d?nh d?ng trên)
void readDataFromFile(QLKH*& dsKhoaHoc, const string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "[Thong bao] Khong tim thay file " << filename << "!\n";
        return;
    }
    string line;
    QLKH* lastKH = nullptr;
    NodeClass* lastClass = nullptr;
    while (getline(in, line)) {
        stringstream ss(line);
        string type;
        getline(ss, type, '|');
        if (type == "KHOAHOC") {
            KhoaHoc kh;
            getline(ss, kh.ID, '|');
            getline(ss, kh.Name, '|');
            getline(ss, kh.type, '|');
            kh.teachers = nullptr;
            kh.classes = nullptr;
            QLKH* node = createKhoaHoc(kh);
            if (!dsKhoaHoc) dsKhoaHoc = node;
            else lastKH->next = node;
            lastKH = node;
            lastClass = nullptr;
        } else if (type == "TEACHER" && lastKH) {
            Teacher t;
            getline(ss, t.ID, '|');
            getline(ss, t.name, '|');
            getline(ss, t.exp, '|');
            string wexp;
            getline(ss, wexp, '|');
            t.wexp = stoi(wexp);
            addTeacher(lastKH->data.teachers, t);
        } else if (type == "CLASS" && lastKH) {
            Class c;
            getline(ss, c.ID, '|');
            getline(ss, c.name, '|');
            string sc;
            getline(ss, sc, '|');
            c.studentCount = stoi(sc);
            string teacherID;
            getline(ss, teacherID, '\n');
            c.teacher.ID = teacherID;
            c.listStudent = nullptr;
            addClass(lastKH->data.classes, c);
            // Tìm node v?a add vào danh sách d? gán lastClass
            lastClass = lastKH->data.classes;
            while (lastClass->next) lastClass = lastClass->next;
        } else if (type == "STUDENT" && lastClass) {
            Student s;
            getline(ss, s.ID, '|');
            getline(ss, s.name, '|');
            string age;
            getline(ss, age, '|');
            s.age = stoi(age);
            getline(ss, s.gender, '|');
            getline(ss, s.level, '\n');
            addStudent(lastClass->data.listStudent, s);
        } else if (type == "ALLTEACHER" && lastKH) {
            Teacher t;
            getline(ss, t.ID, '|');
            getline(ss, t.name, '|');
            getline(ss, t.exp, '|');
            string wexp;
            getline(ss, wexp, '|');
            t.wexp = stoi(wexp);
            addTeacher(lastKH->all, t);
        }
    }
    in.close();
}

