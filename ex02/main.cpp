#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <array>
#include <list>
#include <deque>

void    rexit()
{
    std::cout << "Error" << std::endl;
    exit(0);
}

int main(int ac, char *av[])
{
    if (ac < 2)
        rexit();
    std::deque<int> deq;
    unsigned int temp;
    int i = 0;
    while (av[++i])
    {
        std::istringstream ss(av[i]);
        if (ss >> temp && !ss.rdbuf()->in_avail())
        {
            deq.push_back(temp);
            std::cout << temp << std::endl;
        }
        else
            rexit();
    }
}