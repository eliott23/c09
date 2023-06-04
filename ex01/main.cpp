#include <stack>
#include <iostream>
#include <istream>
#include <sstream>

int main(int ac, char *av[])
{
    std::pair<int, char> p;
    std::stack<std::pair<int, char> > s;
    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        exit(0);
    }
    std::string f(av[1]);
    std::istringstream ss(f);
    std::string str;
    unsigned int n = 0;
    while (ss >> n) 
    {
            // std::cout << n << std::endl;
    }
    std::cout << ss.rdbuf() << std::endl;
    // std::cout << ss.rdbuf() << std::endl;
    if (std::ios_base::badbit && !std::ios_base::eofbit)
        std::cout << "Error" << std::endl;
}