#include <iostream>
using namespace std;

struct Teacher{
    string ID;
    string name;
    int exp;  //kinh nghiệm
};

struct NodeTeacher{
    Teacher teacher;
    NodeTeacher *next;
    NodeClass *classmanage;         //con trỏ quản lý các lớp cùng gv dạy
};

void initTeacherDS(NodeTeacher *gv){
    gv = NULL;
}
