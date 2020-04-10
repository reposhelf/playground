/*
 * Exercise 11.28:
 * Define and initialize a variable to hold the result of calling
 * find on a map from string to vector of int.
 */

#include "chapter11.h"

using namespace std;

void sol_11_28()
{
    map<string, vector<int>> m;
    m.insert({"Oulu", vector<int>{-11, -17}});

    map<string, vector<int>>::iterator it = m.find("Oulu");
    if (it != m.end()) {
	cout << it->first << ": ";
	for (const auto &i : it->second)
	    cout << i << " ";
	cout << endl;
    }
}
