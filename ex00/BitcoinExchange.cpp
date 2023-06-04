#include "BitcoinExchange.hpp"

bool operator==(const std::tm& lhs, const std::tm& rhs) {
    if (lhs.tm_year != rhs.tm_year || lhs.tm_mon != rhs.tm_mon || lhs.tm_mday != rhs.tm_mday)
        return false;
    return true;
}

bool operator<(const std::tm& lhs, const std::tm& rhs) {
    if (lhs.tm_year < rhs.tm_year)
        return true;
    else if (lhs.tm_year == rhs.tm_year)
    {
        if (lhs.tm_mon < rhs.tm_mon)
            return true;
        else if (lhs.tm_mon == rhs.tm_mon)
        {
            if (lhs.tm_mday < rhs.tm_mday)
                return true;
            return false;
        }
        return false;
    }
    return false;
}

bool operator>(const std::tm& lhs, const std::tm& rhs) {
    if (lhs.tm_year > rhs.tm_year)
        return true;
    else if (lhs.tm_year == rhs.tm_year)
    {
        if (lhs.tm_mon > rhs.tm_mon)
            return true;
        else if (lhs.tm_mon == rhs.tm_mon)
        {
            if (lhs.tm_mday > rhs.tm_mday)
                return true;
            return false;
        }
        return false;
    }
    return false;
}

bool operator<=(const std::tm& lhs, const std::tm& rhs) {
    return (lhs < rhs || lhs == rhs);
}

bool operator>=(const std::tm& lhs, const std::tm& rhs) {
    return (lhs > rhs || lhs == rhs);
}