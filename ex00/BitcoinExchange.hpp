#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <istream>
#include <ctime>
#include <cwchar>
#include <time.h>
#include <sstream>
#include <iomanip>

bool operator==(const std::tm& lhs, const std::tm& rhs);
bool operator<(const std::tm& lhs, const std::tm& rhs);
bool operator>(const std::tm& lhs, const std::tm& rhs);
bool operator<=(const std::tm& lhs, const std::tm& rhs);
bool operator>=(const std::tm& lhs, const std::tm& rhs);
float   search_db(std::vector<std::pair<std::tm, float> > &db, std::pair<std::tm, float> &p);
void    res(std::vector<std::pair<std::tm , float> > &db, std::vector<std::pair<std::tm , float> > &k);