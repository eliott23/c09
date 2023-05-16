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

void    isValidDate(const std::tm& date) {

    // Check if the month has a valid number of days
    static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysInCurrentMonth = daysInMonth[date.tm_mon];


    if (date.tm_mday > daysInCurrentMonth)
    {
    // Account for leap years (February has 29 days)
        if (date.tm_mon == 1 && ((date.tm_year % 4 == 0 && date.tm_year % 100 != 0) || date.tm_year % 400 == 0))
        {
            if (date.tm_mday > 29)
            {
                std::cout << "Error: unvalid date" << std::endl;
                exit(0);
            }
        }
        else
        {
            std::cout << "Error: unvalid date" << std::endl;
            exit(0);
        }
    }
}

int main(int ac, char **av)
{
    char    c;
    float    j;
    std::exception e;
    std::string line;
    std::vector<std::pair<int, int> > k;
    if (ac != 2)
    {
        std::cout << "Error: could not open file" << std::endl;
        exit(0);
    }
    std::ifstream h(av[1]);
    if (!h.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        exit(0);
    }
    getline(h, line);
    line.clear();
    getline(h, line);
    std::istringstream ss(line);
    std::tm tm  = {};
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail())
        std::cout << "Error unvalid date" << std::endl;
    else
    {
        tm.tm_year += 1900;
        isValidDate(tm);
        std::cout << tm.tm_year << "-"\
        << tm.tm_mon << "-" << tm.tm_mday << std::endl;
        if (ss >> c) 
            std::cout << "hh" << std::endl;
        if (c != ',')
            std::cout << "Error unvalid format ==> " << line  << std::endl;
        if (ss >> j)
            std::cout << j << std::endl;
    }
}