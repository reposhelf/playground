/*
 * Exercise 10.29:
 * Write a program using stream iterators to read a text file
 * into a vector of strings.
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream file("sol_10_9_data");
    istream_iterator<string> in(file), eof;
    vector<string> svec(in, eof);

    ostream_iterator<string> out(cout, " ");
    copy(svec.begin(), svec.end(), out);
    cout << endl;
    return 0;
}