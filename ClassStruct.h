#pragma once
#include "ClassStruct.cpp"

struct Class {
    string ID;
    string name;
    int studentCount;
};

struct NodeClass {
    Class data;
    NodeClass* next;
};

void initNodeClass(NodeClass*& s);

NodeClass* createNodeClass(Class data);

void addClass(NodeClass*& s, Class data);

NodeClass* searchClass(NodeClass* s, string data);

Class deleteClass(NodeClass*& s, string data);

void displayClassInfo(NodeClass* cl);

void displayClassList(NodeClass* cl);

void changeClassInfo(NodeClass* s, string ID);