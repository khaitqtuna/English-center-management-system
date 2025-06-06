#pragma once
#include <string>
#include "KHstruct.h"

void writeDataToFile(QLKH* dsKhoaHoc, const std::string& filename);
void readDataFromFile(QLKH*& dsKhoaHoc, const std::string& filename);