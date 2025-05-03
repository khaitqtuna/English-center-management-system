#include<iostream>
#include<string>

using namespace std;

enum level {
	A1,A2,B1,B2,C1,C2
};
string displayLevel(level L) {
    switch (L){
    case A1: return "A1";
    case A2: return "A2";
    case B1: return "B1";
    case B2: return "B2";
    case C1: return "C1";
    case C2: return "C2";
    default: return "Unknown";
    }
}

enum gender {
	Male,Female
};
string displayGender(gender G) {
    return G == Male ? "Male" : "Female";
}

struct Student {
	string ID;
	string Name;
	int Age;
	level L;
	gender G;
};

struct NodeStudent {
    Student data;
    NodeStudent* next;
};


typedef NodeStudent* PS;
typedef NodeStudent* LLS;

void initStudent(LLS& S) {
	S = NULL;
}

NodeStudent* createStudent(string ID, string Name, int Age, level L, gender G) {
	PS NS = new NodeStudent;//NewStudent
    NS->data.ID = ID;
	NS->data.Name = Name;
	NS->data.Age = Age;
	NS->data.L = L;
	NS->data.G = G;
	NS->next = NULL;
	return NS;
}

void addStudent(LLS& S, string ID, string Name, int Age, level L, gender G) {
	PS NNS = createStudent(ID, Name, Age, L, G);//NewNodeStudent
	NNS->next = S;
	S = NNS;
}

PS searchStudentByID(LLS S, string ID) {
    PS ptr = S;
    while (ptr != NULL) {
        if (ptr->data.ID == ID)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void deleteStudent(LLS& S, string ID) {
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

void Display(LLS& S, string ID) {
    PS target = searchStudentByID(S, ID);
    if (target == NULL) {
        cout << "No ID: " << ID << endl;
        return;
    }
    else {
        cout << "ID: " << target->data.ID << endl;
        cout << "Name: " << target->data.Name << endl;
        cout << "Level: " << displayLevel(target->data.L) << endl;
        cout << "Age: " << target->data.Age << endl;
        cout << "Gender: " << displayGender(target->data.G) << endl;
    }
}
//void changeStudentInfo(LLS S, int ID) {
//    PS target = searchStudentByID(S, ID);
//    if (target == NULL) {
//        cout << "No ID: " << ID << endl;
//        return;
//    }
//    cout << "insert ID " << ID << ":\n";
//    cout << "Name: "; cin.ignore(); getline(cin, target->Name);
//    cout << "Age: "; cin >> target->Age;
//    int newLevel;    //ko gan duoc truc tiep enum nen su dung mot thong so trung gian
//    cout << "Level: "; cin >> newLevel;
//    target->L = static_cast<level>(newLevel);
//
//    int newGender; cout << "Gender: "; cin >> newGender;//ko gan duoc truc tiep enum nen su dung mot thong so trung gian
//    target->G = static_cast<gender>(newGender);
//
//    cout << "update! New ID: " << ID << endl;
//}




