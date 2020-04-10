/*
 * Exercise 10.34:
 * Use reverse_iterators to print a vector in reverse order.
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for_each(v.crbegin(), v.crend(), [] (int i) { cout << i << ' '; });
    cout << endl;
    return 0;
}