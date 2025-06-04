#pragma once
#include "TeacherStruct.cpp"
#include "ClassStruct.h"

struct Teacher{
    string ID;
    string name;
    string exp;  //trình độ
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

NodeTeacher* searchTeacher(NodeTeacher* &gv, string data);

NodeTeacher* deleteTeacher(NodeTeacher* &gv, string data);

void displayTeacherInfo(NodeTeacher* gv);

void displayTeacherList(NodeTeacher* gv);

void addTeacherInfo(Teacher data);

void changeTeacherInfoForCourse(NodeTeacher*& gv);

void changeTeacherInfo(NodeTeacher*& gv);

void TeacherManagement(QLKH *&course);

