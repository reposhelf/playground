/*
 * Exercise 10.31:
 * Update the program from the previous exercise so that it
 * prints only the unique elements. Your program should use unqiue_copy (§
 * 10.4.1, p. 403).
 */

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    vector<int> vec(in, eof);
    sort(vec.begin(), vec.end());
    ostream_iterator<int> out(cout, " ");
    unique_copy(vec.begin(), vec.end(), out);
    cout << endl;
    return 0;
}