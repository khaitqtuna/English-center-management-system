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


Class deleteClass(NodeClass*& s, Class data) {
    NodeClass* prev = nullptr;
    NodeClass* curr = s;

    while (curr != nullptr && curr->data.ID != data.ID) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Class not found.\n";
        return {"", "", 0}; // Trả về lớp rỗng
    }

    if (prev == nullptr) s = curr->next;
    else prev->next = curr->next;

    Class deleted = curr->data;
    delete curr;
    return deleted;
}


NodeClass* SearchClass(NodeClass* s, Class data) {
    while (s != nullptr) {
        if (s->data.ID == data.ID)
            return s;
        s = s->next;
    }
    return nullptr;
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
