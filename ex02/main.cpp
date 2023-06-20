#include "PmergeMe.hpp"

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