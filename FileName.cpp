#include<iostream>
#include<string>

using namespace std;

enum level {
	A1,A2,B1,B2,C1,C2
};
enum gender {
	Male,Female
};

struct NodeStudent {
	int ID;
	string Name;
	int Age;
	level L;
	gender G;
	NodeStudent* next;
};

typedef NodeStudent* PS;
typedef NodeStudent* LLS;

void initStudent(LLS& S) {
	S = NULL;
}

NodeStudent* createStudent(int ID, string Name, int Age, level L, gender G) {
	PS NS = new NodeStudent;//NewStudent
    NS->ID = ID;
	NS->Name = Name;
	NS->Age = Age;
	NS->L = L;
	NS->G = G;
	NS->next = NULL;
	return NS;
}

void addStudent(LLS& S, int ID, string Name, int Age, level L, gender G) {
	PS NNS = createStudent(ID, Name, Age, L, G);//NewNodeStudent
	NNS->next = S;
	S = NNS;
}

PS searchStudentByID(LLS S, int ID) {
    PS ptr = S;
    while (ptr != NULL) {
        if (ptr->ID == ID)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void deleteStudent(LLS& S, int ID) {
    PS target = searchStudentByID(S, ID);
    if (target == NULL) {
        cout << "No ID: " << ID << endl;
        return;
    }
    if (target == S) S = S->next;
    else {
        PS prev = S;
        while (prev->next != NULL && prev->next != target) {
            prev = prev->next;
        }
        if (prev->next == target) prev->next = target->next;
    }
    delete target;
    cout << "delete ID: " << ID << endl;
}

void changeStudentInfo(LLS S, int ID) {
    PS target = searchStudentByID(S, ID);
    if (target == NULL) {
        cout << "No ID: " << ID << endl;
        return;
    }
    cout << "insert ID " << ID << ":\n";
    cout << "Name: "; cin.ignore(); getline(cin, target->Name);
    cout << "Age: "; cin >> target->Age;
    int newLevel;    //ko gan duoc truc tiep enum nen su dung mot thong so trung gian
    cout << "Level: "; cin >> newLevel;
    target->L = static_cast<level>(newLevel);

    int newGender; cout << "Gender: "; cin >> newGender;//ko gan duoc truc tiep enum nen su dung mot thong so trung gian
    target->G = static_cast<gender>(newGender);

    cout << "update! New ID: " << ID << endl;
}




void printStudents(LLS S) {
    if (S == NULL) {
        cout << "Danh sách rỗng.\n";
        return;
    }
    PS ptr = S;
    cout << "\n--- Danh sách sinh viên ---\n";
    while (ptr != NULL) {
        cout << "ID: " << ptr->ID
            << ", Name: " << ptr->Name
            << ", Age: " << ptr->Age
            << ", Level: " << ptr->L
            << ", Gender: " << (ptr->G == Male ? "Male" : "Female")
            << endl;
        ptr = ptr->next;
    }
}
int main() {
    LLS studentList;
    initStudent(studentList);

    // Thêm sinh viên
    addStudent(studentList, 101, "An", 20, B1, Male);
    addStudent(studentList, 102, "Binh", 22, C1, Female);
    addStudent(studentList, 103, "Chi", 21, A2, Male);

    // In danh sách
    printStudents(studentList);

    // Tìm sinh viên
    PS found = searchStudentByID(studentList, 102);
    if (found != NULL) {
        cout << "\nTìm thấy sinh viên ID 102: " << found->Name << endl;
    }
    else {
        cout << "\nKhông tìm thấy sinh viên ID 102\n";
    }

    // Xóa sinh viên
    cout << "\n-- Xóa sinh viên ID 102 --\n";
    deleteStudent(studentList, 102);
    printStudents(studentList);

    // Cập nhật thông tin
    cout << "\n-- Cập nhật thông tin sinh viên ID 101 --\n";
    changeStudentInfo(studentList, 101);
    printStudents(studentList);

    // Thử xóa sinh viên không tồn tại
    cout << "\n-- Xóa sinh viên ID 999 (không tồn tại) --\n";
    deleteStudent(studentList, 999);

    return 0;
}
