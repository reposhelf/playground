/*
 * Exercise 10.6:
 * Using fill_n, write a program to set a sequence of int values to 0.
 */

#include <vector>
using std::vector;

#include <algorithm>
using std::fill_n;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> vec = { 1, 1, 2, 3, 5, 8, 13, 21 };
    fill_n(vec.begin(), vec.size(), 0);
    for (const int &i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}