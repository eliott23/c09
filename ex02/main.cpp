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

void    pcont(std::vector<unsigned int> &deq, size_t l)
{
    size_t i = 0;
    for (; i < l; i++)
        std::cout << deq[i] << std::endl;
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

void    pcont(std::deque<unsigned int> &deq, size_t l)
{
    size_t i = 0;
    for (; i < l; i++)
        std::cout << deq[i] << std::endl;
}

double	get_timestamp(struct timeval start)
{
	struct timeval	end;

	// gettimeofday(&t, NULL);
	// v = ((t.tv_sec * 1000000) \
	// 		+ t.tv_usec - (start.tv_sec * 1000000) - start.tv_usec);
        gettimeofday(&end, NULL);

    double seconds = end.tv_sec - start.tv_sec;
    double microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds * 1000000 + microseconds;
	return (elapsed / 1000);
}

int main(int ac, char *av[])
{
    if (ac < 2)
        rexit();
    struct timeval  s;
	gettimeofday(&s, NULL);
    std::cout << "after one line " << get_timestamp(s) << std::endl;

    std::deque<unsigned int> deq;
    std::vector<unsigned int> v;
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
    std::cout << "after filling deq : " << get_timestamp(s) << std::endl;
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
    std::cout << "after filling vec : " << get_timestamp(s) << std::endl;
	gettimeofday(&s, NULL);
    merge_insert(v, 0, ac - 2);
    std::cout << "time to process a range of " << ac - 1 << " elements " << get_timestamp(s) << std::endl;
	gettimeofday(&s, NULL);
    merge_insert(deq, 0, ac - 2);
    std::cout << "time to process a range of " << ac - 1 << " elements " << get_timestamp(s) << std::endl;
    pcont(v, ac - 1);
    pcont(deq, ac - 1);
}