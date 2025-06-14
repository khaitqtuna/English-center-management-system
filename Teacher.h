#pragma once
#include <string>

struct NodeClass; // Forward declarat

struct QLKH;

struct Teacher{
    std::string ID;
    std::string name;
    std::string exp;  //trình độ
    int wexp;  //năm kinh nghiệm
};

struct NodeTeacher{
    Teacher data;
    NodeTeacher *next;
    NodeClass *classmanage;         //con trỏ quản lý các lớp cùng gv dạy
};

void initTeacherDS(NodeTeacher* &gv);
NodeTeacher* createNodeTeacher(Teacher data);
void addTeacher(NodeTeacher* &gv, Teacher data);
NodeTeacher* searchTeacher(NodeTeacher* &gv, std::string data);
NodeTeacher* deleteTeacher(NodeTeacher* &gv, std::string data);
void displayTeacherInfo(NodeTeacher* gv);
void displayTeacherList(NodeTeacher* gv);
void addTeacherInfo(Teacher data);
void changeTeacherInfo(NodeTeacher*& gv);
void TeacherManagement(QLKH *&course);
void TeacherCLManagement(QLKH* &course);


inline void ensureInitTeacherList(NodeTeacher*& gv) {
    if (gv == nullptr) gv = nullptr;
}