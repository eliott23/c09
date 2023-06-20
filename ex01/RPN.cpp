# include "RPN.hpp"

void Op(char op, std::stack<int> &stk, int &calc)
{
    int t = stk.top();
    stk.pop();
    int p = stk.top();
    stk.pop();
    int result = 0;
    switch (op) {
        case '+':
            result = p + t;
            break;
        case '-':
            result = p - t;
            break;
        case '*':
            result = p * t;
            break;
        case '/':
            if (!t)
            {
                std::cout << "Invalid operator." << std::endl;
                exit(0);
            }
            result = p / t;
            break;
        default:
            std::cout << "Invalid operator." << std::endl;
    }
    stk.push(result);
    calc = 0;
}

