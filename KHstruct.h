#pragma once
#include <string>
#include "Teacher.h"
#include "KHstruct.h"

struct NodeTeacher;      
struct NodeClass;       


struct KhoaHoc {
    std::string Name;
    std::string ID;
    NodeTeacher* teachers;
    NodeClass*   classes;
    std::string  type;
};

struct QLKH {
    KhoaHoc data;
    NodeTeacher* all;
    QLKH*   next;
};


void   initQLKH        (QLKH*& k);
QLKH*  createKhoaHoc   (KhoaHoc Data);
void   addKhoaHoc      (QLKH*& k, KhoaHoc Data);
QLKH*  seachKhoaHoc    (QLKH*& k, std::string name);
KhoaHoc deleteKhoaHoc  (QLKH*& k, std::string name);

void   HTKhoaHoc       (KhoaHoc Data);
void   HTQLKH          (QLKH* k);
void   change_infKhoaHoc(QLKH*& k);
void classManagement(QLKH*& course);
void   HTKhoaHoc       (KhoaHoc Data);
void   HTQLKH          (QLKH* k);
void   change_infKhoaHoc(QLKH*& k);

