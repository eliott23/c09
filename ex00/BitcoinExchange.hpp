#pragma once
#include <iostream>
#include <ios>
#include <map>
#include <utility>
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
double   search_db(std::map<long long, double> &db, long long k, double v);