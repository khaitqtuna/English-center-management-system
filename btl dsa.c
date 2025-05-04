#include <iostream>
#include <string>
using namespace std;


struct Class {
    string ID;
    string name;
    int studentCount;
};

struct NodeClass {
    Class data;
    NodeClass* next;
};


void initNodeClass(NodeClass*& s) {
    s = nullptr;
}


NodeClass* createNodeClass(Class data) {
    NodeClass* node = new NodeClass;
    node->data = data;
    node->next = nullptr;
    return node;
}


void addClass(NodeClass*& s, Class data) {
    NodeClass* newNode = createNodeClass(data);
    newNode->next = s;
    s = newNode;
}
NodeClass* SearchClass(NodeClass* s, Class data) {
    while (s != nullptr) {
        if (s->data.ID == data.ID)
            return s;
        s = s->next;
    }
    return nullptr;
}
Class deleteClass(NodeClass*& s, Class data) {
    NodeClass* target = SearchClass(s, data); 

    if (target == nullptr) {
        cout << "Class not found.\n";
        return {"", "", 0}; 
    }

    // Nếu node cần xóa là node đầu
    if (target == s) {
        s = s->next;
        Class deleted = target->data;
        delete target;
        return deleted;
    }

    // Tìm node trước node cần xóa
    NodeClass* prev = s;
    while (prev->next != nullptr && prev->next != target) {
        prev = prev->next;
    }

    if (prev->next == target) {
        prev->next = target->next;
        Class deleted = target->data;
        delete target;
        return deleted;
    }

    // Trường hợp không tìm thấy lại (không nên xảy ra)
    return {"", "", 0};
}


void changeClassInfo(NodeClass* s, string ID) {
    while (s != nullptr) {
        if (s->data.ID == ID) {
            cout << "Nhap ten moi: ";
            getline(cin >> ws, s->data.name);
            cout << "Nhap so luong hoc vien moi: ";
            cin >> s->data.studentCount;
            return;
        }
        s = s->next;
    }
    cout << "Khong tim thay lop co ID: " << ID << endl;
}
