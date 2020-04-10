/*
 * Exercise 10.42:
 * Reimplement the program that eliminated duplicate words
 * that we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.
 */

#include <fstream>
#include <iterator>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ifstream file("sol_10_9_data");
    istream_iterator<string> it(file), eof;
    list<string> lst(it, eof);
    lst.sort();
    lst.unique();
    for_each(lst.begin(), lst.end(), [] (const string &s) { cout << s << ' '; });
    cout << endl;
    return 0;
}