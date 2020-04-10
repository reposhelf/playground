/*
 * Exercise 11.22:
 * Given a map<string, vector<int>>, write the types
 * used as an argument and as the return value for the version of insert that
 * inserts one element.
 */

#include "chapter11.h"

using namespace std;

void sol_11_22()
{
    map<string, vector<int>> m;
    pair<map<string, vector<int>>::iterator, bool> ret
	= m.insert({"Odessa", vector<int>{7, 13}});

    cout << ret.second << endl;
}
