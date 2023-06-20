#include <iostream>
#include <map>
#include <unistd.h>
#include <istream>
#include <sstream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <sys/time.h>

void    rexit()
{
    std::cout << "Error" << std::endl;
    exit(0);
}

void    merge_sort(std::vector<unsigned int> &deq, size_t b, size_t m, size_t e)
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

void    insert(std::vector<unsigned int> &deq, size_t b, size_t e)
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

void    merge_insert(std::vector<unsigned int> &deq, size_t b, size_t e)
{
    if (e - b + 1 > 30)
    {
        size_t m = ((e - b + 1) / 2) - 1 + b;
        merge_insert (deq, b, m);
        merge_insert (deq, m + 1, e);
        merge_sort(deq, b, m, e);
    }
    else
        insert(deq, b, e);
}

void    pcont(std::vector<unsigned int> &deq, size_t l, int f)
{
    size_t i = 0;
    if (f)
        std::cout << "After :" << std::endl;
    else
        std::cout << "Before :" << std::endl;
    for (; i < l; i++)
        std::cout << " " << deq[i];
    std::cout << std::endl;
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

void    merge_insert(std::deque<unsigned int> &deq, size_t b, size_t e)
{
    if (e - b + 1 > 30)
    {
        size_t m = ((e - b + 1) / 2) - 1 + b;
        merge_insert (deq, b, m);
        merge_insert (deq, m + 1, e);
        merge_sort(deq, b, m, e);
    }
    else
        insert(deq, b, e);
}

void    pcont(std::deque<unsigned int> &deq, size_t l, int f)
{
    size_t i = 0;
    if (f)
        std::cout << "After :" << std::endl;
    else
        std::cout << "Before :" << std::endl;
    for (; i < l; i++)
        std::cout << " " << deq[i];
    std::cout << std::endl;
}

long long	get_timestamp(struct timeval start)
{
	struct timeval	end;

    gettimeofday(&end, NULL);

    long long seconds = end.tv_sec - start.tv_sec;
    long long microseconds = end.tv_usec - start.tv_usec;
    long long elapsed = seconds * 1000000 + microseconds;
	return (elapsed);
}

int main(int ac, char *av[])
{
    if (ac < 2)
        rexit();
    struct timeval  s;
	gettimeofday(&s, NULL);

    std::deque<unsigned int> deq;
    std::vector<unsigned int> v;
    long long f_d,f_v,s_v,s_d;
    unsigned int temp;
    int i = 0;
    while (av[++i])
    {
        std::istringstream ss(av[i]);
        if (ss >> temp && !ss.rdbuf()->in_avail())
            deq.push_back(temp);
        else
            rexit();
    }
    f_d = get_timestamp(s);
    pcont(deq, ac - 1, 0);
	gettimeofday(&s, NULL);
    i = 0;
    while (av[++i])
    {
        std::istringstream ss(av[i]);
        if (ss >> temp && !ss.rdbuf()->in_avail())
            v.push_back(temp);
        else
            rexit();
    };
    f_v = get_timestamp(s);
	gettimeofday(&s, NULL);
    merge_insert(v, 0, ac - 2);
    s_v = get_timestamp(s);
	gettimeofday(&s, NULL);
    merge_insert(deq, 0, ac - 2);
    s_d = get_timestamp(s);
    pcont(v, ac - 1, 1);
    std::cout << "after filling deq : " << f_d << " us" << std::endl;
    std::cout << "after filling vec : " << f_v << " us" << std::endl;
    std::cout << "time to process a range of " << ac - 1 << " std::vector elements " << s_v << " us" << std::endl;
    std::cout << "time to process a range of " << ac - 1 << " std::deque elements " << s_d << " us" << std::endl;
}