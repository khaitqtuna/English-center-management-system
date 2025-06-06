#pragma once
#include <string>

struct Student {
    std::string ID;
    std::string name;
    int age;
    std::string level;
    std::string gender;
};

struct NodeStudent {
    Student data;
    NodeStudent* next;
};

void initStudent(NodeStudent*& S);
NodeStudent* createNodeStudent(Student data);
void addStudent(NodeStudent*& S, Student data);
NodeStudent* searchStudent(NodeStudent*& S, std::string data);
Student deleteStudent(NodeStudent*& S, std::string data);
void displayStudentInfo(NodeStudent* S);
void changeStudentInfo(NodeStudent*& S);
void displayStudentList(NodeStudent* S);


