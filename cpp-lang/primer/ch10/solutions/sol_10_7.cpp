/*
 * Exercise 10.7:
 * Determine if there are any errors in the following programs
 * and, if so, correct the error(s):
 *
 * (a)
 * vector<int> vec; list<int> lst; int i;
 * while (cin >> i)
 *     lst.push_back(i);
 * copy(lst.cbegin(), lst.cend(), vec.begin());
 *
 * (b)
 * Program is correct.
 * vector<int> vec;
 * vec.reserve(10);
 * fill_n(vec.begin(), 10, 0);
 */

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <algorithm>
using std::copy;

#include <iterator>
using std::back_inserter;

int main()
{
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);
    copy(lst.begin(), lst.end(), back_inserter(vec));

    for (const int &i : vec)
        cout << i << " ";
    cout << endl;
    
    return 0;
}