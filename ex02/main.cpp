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

void    merge_sort(std::deque<unsigned int> &deq, size_t b, size_t m, size_t e)
{
    int *fh = new int[m - b + 1];
    int *sh = new int[e - m];

    size_t i = 0;
    size_t t = b;
    while (i <= m - b)
    {
        fh[i] = deq[t];
        t++;
        i++;
    }
    i = 0;
    t = m + 1;
    while (i < e - m)
    {
        sh[i] = deq[t];
        t++;
        i++;
    }
    t = b;
    i = 0;
    size_t j = 0;
    while (j < e - m && i <= m - b)
    {
        if (fh[i] <= sh[j])
        {
            deq[t] = fh[i];
            i++;
        }
        else
        {
            deq[t] = sh[j];
            j++;
        }
        t++;
    }
    while (j < e - m)
    {
            deq[t] = sh[j];
            j++;
            t++;
    }
    while (i <= m - b)
    {
            deq[t] = fh[i];
            i++;
            t++;
    }
}

void    merge(std::deque<unsigned int> &deq, size_t b, size_t e)
{
    if (e - b + 1 > 30)
    {
        size_t m = ((e - b + 1) / 2) - 1;
        merge (deq, b, m);
        merge (deq, m + 1, e);
        merge_sort(b, m, e);
    }
    else
        insert(deq, b, e);
}

void    insert(std::deque<unsigned int> &deq, size_t b, size_t e)
{
    size_t i = b + 1;
    size_t j;
    unsigned int temp;
    while (i <= e)
    {
        j = i;
        while (j > b && deq[j] < deq[j - 1])
        {
                temp = deq[j];
                deq[j] = deq[j - 1];
                deq[j - 1] = temp;
                j--;
        }
        i++;
    }
}

void    insert(std::deque<unsigned int> &deq, size_t b, size_t e)
{
    size_t i = b + 1;
    size_t j;
    unsigned int temp;
    while (i <= e)
    {
        j = i;
        while (j > b && deq[j] < deq[j - 1])
        {
                temp = deq[j];
                deq[j] = deq[j - 1];
                deq[j - 1] = temp;
                j--;
        }
        i++;
    }
}

void    pcont(std::deque<unsigned int> &deq, size_t l)
{
    size_t i = 0;
    for (; i < l; i++)
        std::cout << deq[i] << std::endl;
}

int main(int ac, char *av[])
{
    if (ac < 2)
        rexit();
    std::deque<unsigned int> deq;
    unsigned int temp;
    int i = 0;
    while (av[++i])
    {
        std::istringstream ss(av[i]);
        if (ss >> temp && !ss.rdbuf()->in_avail())
        {
            deq.push_back(temp);
            // std::cout << temp << std::endl;
        }
        else
            rexit();
    }
    insert(deq, 0, ac - 2);
    pcont(deq, ac - 1);
    deq[0];
}