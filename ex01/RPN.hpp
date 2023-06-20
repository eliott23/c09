# pragma once

#include <stack>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

void Op(char op, std::stack<unsigned int> &stk, int &calc);
void    exiterr();