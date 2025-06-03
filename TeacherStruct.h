#pragma once
#include "TeacherStruct.cpp"

void initTeacherDS(NodeTeacher* &gv);

NodeTeacher* createNodeTeacher(Teacher data);

void addTeacher(NodeTeacher* &gv, Teacher data);

NodeTeacher* searchTeacher(NodeTeacher* &gv, string data);

Teacher deleteTeacher(NodeTeacher* &gv, string data);

void displayTeacherInfo(NodeTeacher* gv);

void changeTeacherInfo(NodeTeacher*& gv);

