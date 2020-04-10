/*
 * Exercise 3.41:
 * Write a program to initialize a vector from an array of
 * ints.
 */
#include <vector>
using std::vector;

#include <iterator>
using std::begin;
using std::end;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int array[] = {1, 3, 5, 7, 9};

    vector<int> vec(begin(array), end(array));
    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}
