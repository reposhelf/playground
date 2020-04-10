/*
 * Exercise 10.3:
 * Use accumulate to sum the elements in a vector<int>.
 */

#include <vector>
using std::vector;

#include <numeric>
using std::accumulate;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5};
    // Output is 115:
    cout << accumulate(ivec.cbegin(), ivec.cend(), 100) << endl;
    return 0;
}
