#pragma once
#include <string>
#include "Class.h"

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
void changeTeacherInfoForCourse(NodeTeacher*& gv);
void changeTeacherInfo(NodeTeacher*& gv);
void TeacherManagement(QLKH *&course);

inline void ensureInitTeacherList(NodeTeacher*& gv) {
    if (gv == nullptr) gv = nullptr;
}
void changeTeacherInfo(NodeTeacher*& gv);

void TeacherManagement(QLKH *&course);

