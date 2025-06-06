#pragma once
#include <string>
#include "Student.h"
#include "Teacher.h"

struct Class {
    std::string ID;
    std::string name;
    int studentCount;
    NodeStudent* listStudent;
    Teacher teacher;
};

struct NodeClass {
    Class data;
    NodeClass* next;
};

void initNodeClass(NodeClass*& s);
NodeClass* createNodeClass(Class data);
void addClass(NodeClass*& s, Class data);
NodeClass* searchClass(NodeClass* s, std::string data);
Class deleteClass(NodeClass*& s, std::string data);
void displayClassInfo(NodeClass* cl);
void displayClassList(NodeClass* cl);
void changeClassInfo(NodeClass*& cl);






