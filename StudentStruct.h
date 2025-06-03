#pragma once
#include "StudentStruct.cpp"

void initStudent(NodeStudent*& S);

NodeStudent* createNodeStudent(Student data);

void addStudent(NodeStudent*& S, Student data);

NodeStudent* searchStudent(NodeStudent* &S, string data);

Student deleteStudent(NodeStudent*& S, string data);

void displayStudentInfo(NodeStudent*& S);