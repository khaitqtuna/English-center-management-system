#pragma once
#include "ClassStruct.cpp"
#include "StudentStruct.h"

struct Class {
    string ID;
    string name;
    int studentCount;
    NodeStudent* listStudent;
};

struct NodeClass {
    Class data;
    NodeClass* next;
    NodeTeacher* managedBy;
};

void initNodeClass(NodeClass*& s);

NodeClass* createNodeClass(Class data);

void addClass(NodeClass*& s, Class data);

NodeClass* searchClass(NodeClass* s, string data);

Class deleteClass(NodeClass*& s, string data);

void displayClassInfo(NodeClass* cl);

void displayClassList(NodeClass* cl);

void changeClassInfoForCourse(NodeClass* s, string ID);

void TeacherClassManagement(QLKH *&course)
