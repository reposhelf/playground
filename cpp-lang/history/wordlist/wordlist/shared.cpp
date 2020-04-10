#include "shared.h"

#include <iostream>

using namespace std;

void error(const string &msg)
{
    cerr << msg << endl;
    exit(1);
}

void remove_punct(string &s)
{
    if (ispunct(s.back()))
        s.pop_back();
}

void make_upper_case(string &s)
{
    for (auto &c : s)
        c = toupper(c);
}

void reformat(string &s)
{
    remove_punct(s);
    make_upper_case(s);
}
