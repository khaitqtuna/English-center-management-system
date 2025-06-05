#pragma once
#include <string>
using namespace std;

struct Student {
    string ID;
    string name;
    int age;
    string level;
    string gender;
};

struct NodeStudent {
    Student data;
    NodeStudent* next;
};

void initStudent(NodeStudent*& S);

NodeStudent* createNodeStudent(Student data);

void addStudent(NodeStudent*& S, Student data);

NodeStudent* searchStudent(NodeStudent*& S, string data);

Student deleteStudent(NodeStudent*& S, string data);

void displayStudentInfo(const NodeStudent* S);

void displayStudentList(NodeStudent *st);

void changeStudentInfo(NodeStudent*& S);