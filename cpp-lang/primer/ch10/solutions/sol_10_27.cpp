/*
 * Exercise 10.27:
 * In addition to unique (§ 10.2.3, p. 384), the library defines function named
 * unique_copy that takes a third iterator denoting a destination into which to copy the
 * unique elements. Write a program that uses unique_copy to copy the unique elements
 * from a vector into an initially empty list.
 */

#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
    std::vector<int> ivec = {1, 2, 2, 3, 4, 5, 5};
    std::list<int> ilst;
    std::unique_copy(ivec.begin(), ivec.end(), std::inserter(ilst, ilst.begin()));
    for (int i : ilst)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}