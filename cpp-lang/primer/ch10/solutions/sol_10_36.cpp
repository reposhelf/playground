/*
 * Exercise 10.36:
 * Use find to find the last element in a list of ints with value 0.
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {0, 1, 8, 0, 7, 9, 5, 0, 13, 21, 9};
    cout << *++(find(v.crbegin(), v.crend(), 0)) << endl;
    return 0;
}