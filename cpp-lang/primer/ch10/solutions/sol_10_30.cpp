/*
 * Exercise 10.30:
 * Use stream iterators, sort, and copy to read a sequence
 * of integers from the standard input, sort them, and then write them back to
 * the standard output.
 */

#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    vector<int> vec(in, eof);
    sort(vec.begin(), vec.end());
    ostream_iterator<int> out(cout, " ");
    copy(vec.begin(), vec.end(), out);
    cout << endl;
    return 0;
}