#include <iostream>
#include <string>
using namespace std;

void menu(){
    cout<< "1. Gioi thieu ve trung tam" << endl;
    cout<< "2. Quan ly" << endl;
    cout<< "3. Thong ke" << endl;
    cout<< endl << "Lua chon:";
    int choice = 0;
    cin>> choice;

    if(choice == 1)
        //hàm txt giới thiệu 
    else if(choice == 2)
        //systemManagement()
    else if(choice == 3)
        //ham thong ke txt
    else
        do{
            cout<< endl << "Chu so khong hop le, moi nhap lai:";
            cin >> choice;
        }
        while(choice < 1 || choice > 3);
}

void systemManagement(QLKH* ql){
    cout<< "1. Khoa hoc" << endl;
    cout<< "2. Giao vien" << endl;
    cout<< "3. Lop hoc" << endl;
    cout<< endl << "Lua chon:";
}

void

int main(){

}