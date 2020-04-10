/*
 * Exercise 10.28:
 * Copy a vector that holds the values from 1 to 9 inclusive, into three other
 * containers. Use an inserter, a back_inserter, and a front_inserter, respectivly to
 * add elements to these containers. Predict how the output sequence varies by the kind
 * of inserter and verify your predictions by running your programs.
 */

#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <iterator>
#include <iostream>

template<class Iter> void print(Iter first, Iter last)
{
    for (; first != last; ++first)
        std::cout << *first << ' ';
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::list<int> lst;
    std::copy(vec.begin(), vec.end(), std::inserter(lst, lst.begin()));

    std::deque<int> deq;
    std::copy(vec.begin(), vec.end(), std::back_inserter(deq));

    std::forward_list<int> fwd_lst;
    std::copy(vec.begin(), vec.end(), std::front_inserter(fwd_lst));

    print(lst.begin(), lst.end());
    print(deq.begin(), deq.end());
    print(fwd_lst.begin(), fwd_lst.end());

    return 0;
}