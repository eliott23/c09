# include "RPN.hpp"

void    exiterr()
{
    std::cout << "Error" << std::endl;
    exit(0);
}

int main(int ac, char *av[])
{
    std::pair<int, char> p;
    std::stack<int> s;
    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        exit(0);
    }
    std::string f(av[1]);
    std::istringstream ss(f);
    std::istream &k = ss;
    std::string str;
    std::string oper = "+*-/";
    int calc;
    int i;
    char c;
    while (getline(k, str, ' '))
    {
        if(str.size() > 1 || ((oper.find(str.front())) == std::string::npos && !std::isdigit(str.front())))
            exiterr();
        // std::cout << str << std::endl;
        std::istringstream sss(str);
        if (sss >> i)
            {
                s.push(i);
                calc++;
                if (calc > 2)
                    exiterr();
            }
            else if (s.size() >= 2)
            {
                sss.clear();
                c = str.front();
                Op(c, s, calc);
            }
            else
                exiterr();
            str.clear();
    }
    if ((std::ios_base::badbit && !std::ios_base::eofbit) || s.size() > 1)
        exiterr();
    std::cout << s.top() << std::endl;
}