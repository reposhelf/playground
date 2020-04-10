/*
 * Exercise 12.7:
 * Redo the previous exercise (12.6), this time using shared_ptr.
 */

#include "chapter12.h"

using namespace std;

shared_ptr<vector<int>> createSharedPtrVectorOfInt()
{
    return make_shared<vector<int>>();
}

void readVectorOfInt(istream &in, shared_ptr<vector<int>> &vi)
{
    string s;
    while (in >> s)
        vi->push_back(stoi(s));
}

void printVectorOfInt(ostream &out, shared_ptr<vector<int>> &vi)
{
    for (const auto &i : *vi)
        out << i << ' ';
    out << endl;
}
