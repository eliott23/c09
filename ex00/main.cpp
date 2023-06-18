#include "BitcoinExchange.hpp"

//check later foran empty database
long long   time_to_key(std::tm date)
{
    return (32 * date.tm_mon + date.tm_mday + 1500 * date.tm_year);
}

double   search_db(std::map<long long, double> &db, long long k, double v)
{
    std::map<long long, double>::iterator r = db.upper_bound(k);
    if (r == db.begin())
    {
        std::cout << "Bitcoin was the first cryptocurrency created and is now the most valuable and well-known. It was first launched \
        in JANNUARY 2009 by a computer programmer or group of programmers under the pseudonym Satoshi Nakamoto, whose actual identity has never been verified."\
        << std::endl;
        std::exception e;
        throw e;
    }
    r--;
    return (r->second * v);
}

void    isValidDate(const std::tm& date)
{
    std::exception e;
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
                throw e;
            }
        }
        else
        {
            std::cout << "Error: unvalid date" << std::endl;
            throw e;
        }
    }
}

void extract_check(std::istringstream &ss, char &c, std::string &line)
{
    std::exception e;
        if (!(ss >> std::noskipws >> c)) //check later
        {
            std::cout << "Error unvalid format ==> " << line  << std::endl;
            throw e; 
        }
}

std::map<long long, double>   parse_db(std::ifstream &h) 
{
    char    c;
    double    j;
    std::string targ = ",";
    std::string form;
    std::string line;
    std::map<long long, double> k;
    std::tm tm  = {};
    std::exception e;

    while (getline(h, line))
    {
        try{
            std::istringstream ss(line);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            if (ss.fail())
            {
                if (line.empty())
                    std::cout << "Error empty line" << line  << std::endl;
                else
                    std::cout << "Error unvalid date" << std::endl;
                throw e;
            }
            else
            {
                tm.tm_year += 1900;
                isValidDate(tm);
                extract_check(ss, c, line); 
                form.push_back(c);
                if (form != targ)
                {
                    std::cout << "Error unvalid format ==>" << line  << std::endl;
                    throw e;
                }
                form.clear();
                if (ss >> j)
                    k[time_to_key(tm)] = j;
                else
                {
                    if (!(ss.rdbuf()->in_avail()))
                        std::cout << "Error unvalid bitcoin value ==> " << line  << std::endl;
                    else
                        std::cout << "Error unvalid format ==> " << line  << std::endl;
                    throw e;
                }
                if (ss.rdbuf()->in_avail())
                {
                    std::cout << "Error unvalid format ==>" << line  << std::endl;
                    throw e;
                }
            }
        }
        catch (std::exception &e)
        {
            exit(0);
        }
    }
    return k;
}

void op_f(std::ifstream &h, std::map<long long, double> &db) 
{
    char    c;
    double    j;
    std::string targ = " | ";
    std::string form;
    std::string line;
    std::pair<std::tm, double> p;
    std::tm tm  = {};
    std::exception e;

    while (getline(h, line))
    {
        try
        {
            std::istringstream ss(line);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            if (ss.fail())
            {
                if (line.empty())
                    std::cout << "Error empty line" << line  << std::endl;
                else
                    std::cout << "Error unvalid date" << std::endl;
                throw e;
            }
            else
            {
                tm.tm_year += 1900;
                isValidDate(tm);
                for (int i = 0; i < 3; i++)
                {
                    extract_check(ss, c, line); 
                    form.push_back(c);
                }
                if (form != targ)
                {
                    std::cout << "Error unvalid format ==>" << line  << std::endl;
                    throw e;
                }
                form.clear();
                if (ss >> j)
                {
                    if (j > 1000 || j < 0)
                    {
                        if (j > 1000)
                            std::cout << "Error bitcoin value too large" << std::endl;
                        else
                            std::cout << "Error not a positive number" << std::endl;
                        throw e;
                    }
                    p.first = tm;
                    p.second = j;
                }
                else
                {
                    if (!(ss.rdbuf()->in_avail()))
                        std::cout << "Error unvalid bitcoin value ==> " << line  << std::endl;
                    else
                        std::cout << "Error unvalid format ==> " << line  << std::endl;
                    throw e;
                }
                if (ss.rdbuf()->in_avail())
                {
                    std::cout << "Error unvalid format ==>" << line  << std::endl;
                    throw e;
                }
                std::cout << tm.tm_year << "-"\
                << tm.tm_mon + 1 << "-" << tm.tm_mday << " => " << p.second << " = ";
                std::cout << search_db(db, time_to_key(tm), j) << std::endl;
            }
        }
        catch (...)
        {
            form.clear();
        }
    }
    if (line.empty())
        std::cout << "Error empty line" << line  << std::endl;
}

int main(int ac, char **av)
{
    std::map<long long, double> db;
    if (ac != 2)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        exit(0);
    }
    std::ifstream h("data.csv");
    if (!h.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        exit(0);
    }
    std::ifstream f(av[1]);
    if (!f.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        exit(0);
    }
    std::string line;
    getline(h, line);
    db = parse_db(h);
    op_f(f, db);
}
