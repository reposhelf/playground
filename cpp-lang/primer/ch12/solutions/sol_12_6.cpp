/*
 * Exercise 12.6:
 * Write a function that returns a dynamically allocated vector
 * of ints. Pass that vector to another function that reads the standard input
 * to give values to the elements. Pass the vector to another function to print
 * the values that were read. Remember to delete the vector at the
 * appropriate time.
 */

#include "chapter12.h"

#include <string>

using namespace std;

vector<int> *createVectorOfInt()
{
    return new vector<int>();
}

void readVectorOfInt(istream &in, vector<int>* &vi)
{
    string s;
    while (in >> s)
        vi->push_back(stoi(s));
}

void printVectorOfInt(ostream &out, vector<int>* &vi)
{
    for (const auto &i : *vi)
        out << i << ' ';
    out << endl;
}

