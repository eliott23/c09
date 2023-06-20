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
    if (f.empty())
        exiterr();
    std::istringstream ss(f);
    std::istream &k = ss;
    std::string str;
    std::string oper = "+*-/";
    int calc;
    int i;
    char c;
    while (getline(k, str, ' '))
    {
        if(!str.size() || (oper.find(str.front()) != std::string::npos && str.size() != 1)\
        || ((oper.find(str.front())) == std::string::npos && !std::isdigit(str.front())))
            exiterr();
        std::istringstream sss(str);
        if (sss >> std::noskipws >> i)
        {
            if (i >= 100 || i < 0)
                exiterr();
            else if (i >= 10)
            {
                s.push(i / 10);
                calc++;
                if (calc > 2)
                    exiterr();
            }
            s.push(i % 10);
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
    }
    if ((std::ios_base::badbit && !std::ios_base::eofbit) || s.size() > 1 || str.empty())
        exiterr();
    std::cout << s.top() << std::endl;
}