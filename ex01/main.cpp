# include "RPN.hpp"
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
    int f;
    int i;
    char c;
    while (getline(k, str, ' '))
    {
        if(str.size() > 1 || ((oper.find(str.front())) == std::string::npos && !std::isdigit(str.front())))
        {
            std::cout << "Error" << std::endl;
            exit(0);
        }
        std::cout << str << std::endl;
        std::istringstream sss(str);
        if (sss >> i)
        {
            sss.clear();
            s.push(i);
            if (s.size() > 2)
                std::cout << "Error" << std::endl;
        }
        else
        {
            sss >> c;
        }
        str.clear();
    }
    if (std::ios_base::badbit && !std::ios_base::eofbit)
        std::cout << "Error3" << std::endl;
}