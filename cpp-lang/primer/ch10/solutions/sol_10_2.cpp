/*
 * Exercise 10.2:
 * Repeat the previous program, but read values into a list of strings.
 */

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <algorithm>

int main()
{
    ifstream in("sol_10_2_data");
    if (!in.is_open()) {
	cerr << "Cannot open file" << endl;
	exit(1);
    }

    list<string> lst;
    string word;
    while (in >> word)
	lst.push_back(word);

    cout << std::count(lst.cbegin(), lst.cend(), "Dynamo") << endl;

    return 0;
}
