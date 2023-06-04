#include "BitcoinExchange.hpp"

//check later foran empty database
float   search_db(std::vector<std::pair<std::tm, float> > &db, std::pair<std::tm, float> &p)
{
    std::vector<std::pair<std::tm, float> >::iterator b = db.begin();
    std::vector<std::pair<std::tm, float> >::iterator btwo = b + 1;

    while (b != db.end())
    {
        btwo = b + 1;
        if (btwo != db.end() &&  b->first < p.first && btwo->first <= p.first)
            b++;
        else
            break;
    }
    return (b->second * p.second);
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

std::vector<std::pair<std::tm , float> > parse_db(std::ifstream &h) 
{
    char    c;
    float    j;
    std::string targ = ",";
    std::string form;
    std::string line;
    std::pair<std::tm, float> p;
    std::vector<std::pair<std::tm , float> > k;
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
                { 
                    p.first = tm;
                    p.second = j;
                    k.push_back(p);
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
            }
        }
        catch (std::exception &e)
        {
            exit(0);
        }
    }
    return k;
}

void op_f(std::ifstream &h, std::vector<std::pair<std::tm, float> > &db) 
{
    char    c;
    float    j;
    std::string targ = " | ";
    std::string form;
    std::string line;
    std::pair<std::tm, float> p;
    std::vector<std::pair<std::tm , float> > k;
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
                std::cout << search_db(db, p) << std::endl;
            }
        }
        catch (...)
        {
            form.clear();
        }
    }
    if (line.empty())
        std::cout << "Error empty line at end of file" << line  << std::endl;
}

int main(int ac, char **av)
{
    std::vector<std::pair<std::tm , float> > db;
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
