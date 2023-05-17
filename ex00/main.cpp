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

bool operator<(const std::tm& lhs, const std::tm& rhs) {
    return lhs.tm_sec < rhs.tm_sec &&
           lhs.tm_min < rhs.tm_min &&
           lhs.tm_hour < rhs.tm_hour &&
           lhs.tm_mday < rhs.tm_mday &&
           lhs.tm_mon < rhs.tm_mon &&
           lhs.tm_year < rhs.tm_year &&
           lhs.tm_wday < rhs.tm_wday &&
           lhs.tm_yday < rhs.tm_yday &&
           lhs.tm_isdst < rhs.tm_isdst;
}

void    isValidDate(const std::tm& date)
{
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

std::vector<std::pair<std::tm , float> > parse_db(std::ifstream &h) 
{
    char    c;
    float    j;
    std::string line;
    std::pair<std::tm, float> p;
    std::vector<std::pair<std::tm , float> > k;
    std::tm tm  = {};

    while (getline(h, line))
    {
        std::cout << "up" << std::endl;
        std::istringstream ss(line);
        std::cout << "this is the line |" << line  << "|" << std::endl;
        ss >> std::get_time(&tm, "%Y-%m-%d");
        if (ss.fail())
            std::cout << "Error unvalid date" << std::endl;
        else
        {
            tm.tm_year += 1900;
            isValidDate(tm);
            std::cout << tm.tm_year << "-"\
            << tm.tm_mon << "-" << tm.tm_mday << std::endl;
            ss >> c;
            if (c != ',')
            {
                std::cout << "Error unvalid format ==> " << line  << std::endl;
                exit(0);
            }
            if (ss >> j)
            { 
                p.first = tm;
                p.second = j;
                k.push_back(p);
            }
            else
            {
                std::cout << "Error unvalid bitcoin format ==> " << line  << std::endl;
                exit(0);
            }
        }
    }
    return k;
}

void op_f(std::ifstream &h) 
{
    char    c;
    float    j;
    std::string line;
    std::pair<std::tm, float> p;
    std::vector<std::pair<std::tm , float> > k;
    std::tm tm  = {};

    while (getline(h, line))
    {
        std::cout << "up" << std::endl;
        std::istringstream ss(line);
        std::cout << "this is the line |" << line  << "|" << std::endl;
        ss >> std::get_time(&tm, "%Y-%m-%d");
        if (ss.fail())
            std::cout << "Error unvalid date" << std::endl;
        else
        {
            tm.tm_year += 1900;
            isValidDate(tm);
            std::cout << tm.tm_year << "-"\
            << tm.tm_mon << "-" << tm.tm_mday << std::endl;
            ss >> c;
            if (c != ',')
            {
                std::cout << "Error unvalid format ==> " << line  << std::endl;
                exit(0);
            }
            if (ss >> j)
            { 
                p.first = tm;
                p.second = j;
                k.push_back(p);
            }
            else
            {
                std::cout << "Error unvalid bitcoin format ==> " << line  << std::endl;
                exit(0);
            }
        }
    }
}

int main(int ac, char **av)
{
    std::vector<std::pair<std::tm , float> > db;
    if (ac != 2)
    {
        std::cout << "Error: could not open file" << std::endl;
        exit(0);
    }
    (void)av;
    std::ifstream h("data.csv");
    if (!h.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        exit(0);
    }
    db = parse_db(h);
    std::vector<std::pair<std::tm, float> >::iterator b = db.begin();
    for(b = db.begin(); b != db.end(); b++)
        std::cout << b->second << std::endl;
}