#include <iostream>
#include <fstream>
using namespace std;

#include "KHstruct.h"
#include "Class.h"
#include "Teacher.h"
#include "Student.h"

bool isFileEmpty(const string& filename) {
    ifstream infile(filename, ios::ate);  // ios::ate mở file và đưa con trỏ về cuối file

    if (!infile.is_open()) {
        cout << "Không thể mở file!" << endl;
        return false;  // hoặc có thể throw lỗi tuỳ tình huống
    }

    // Kiểm tra vị trí con trỏ ở cuối file, nếu bằng 0 thì file rỗng
    return infile.tellg() == 0;
}

void
