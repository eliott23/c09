#pragma once

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
void    rexit();
long long	get_timestamp(struct timeval start);
void    pcont(std::deque<unsigned int> &deq, size_t l, int f);
void    merge_insert(std::deque<unsigned int> &deq, size_t b, size_t e);
void    insert(std::deque<unsigned int> &deq, size_t b, size_t e);
void    merge_sort(std::deque<unsigned int> &deq, size_t b, size_t m, size_t e);
void    pcont(std::vector<unsigned int> &deq, size_t l, int f);
void    merge_insert(std::vector<unsigned int> &deq, size_t b, size_t e);
void    insert(std::vector<unsigned int> &deq, size_t b, size_t e);
void    merge_sort(std::vector<unsigned int> &deq, size_t b, size_t m, size_t e);