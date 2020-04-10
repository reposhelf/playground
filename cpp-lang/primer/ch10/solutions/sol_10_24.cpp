/*
 * Exercise 10.24:
 * Use bind and check_size to find the first element in a vector of ints that has a value
 * greater than the length of a specified string value.
 */

#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;

bool check_size(const std::string &s, std::string::size_type sz)
{
    return s.size() < sz;
}

int main()
{
    std::vector<std::string::size_type> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = std::find_if(vi.begin(), vi.end(), std::bind(check_size, "hello", _1));
    std::cout << *it << std::endl;
    return 0;
}