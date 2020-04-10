/*
 * Exercise 10.37:
 * Given a vector that has ten elements, copy the elements
 * from positions 3 through 7 in reverse order to a list.
 */

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> iv = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> il(iv.crbegin() + 2, iv.crend() - 3);
    for_each(il.cbegin(), il.cend(), [] (int i) { cout << i << ' '; });
    cout << endl;
    return 0;
}