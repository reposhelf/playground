/*
 * Exercise 10.35:
 * Print the elements in reverse order using ordinary iterators.
 */

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = v.cend() - 1; it != v.cbegin() - 1; --it)
        cout << *it << ' ';
    cout << endl;
    return 0;
}