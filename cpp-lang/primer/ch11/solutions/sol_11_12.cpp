/*
 * Exercise 11.12:
 * Write a program to read a sequence of strings and ints,
 * storing each into a pair. Store the pairs in a vector.
 */

#include "chapter11.h"

#include <fstream>
#include <sstream>

using namespace std;

void read_pairs(const string &file_name,
		vector<pair<string, int>> &pairs)
{
    ifstream in(file_name);
    if (!in.is_open())
	error("Failed to open file.");

    string line;
    while (getline(in, line)) {
	istringstream str_in(line);
	string word, num;
	str_in >> word >> num;
	pairs.push_back({word, stoi(num)});

        // other ways to make mairs
	//pairs.push_back(make_pair(word, stoi(num)));
	//pairs.push_back(pair<string, int>(word, stoi(num)));
    }
}

void sol_11_12()
{
    vector<pair<string, int>> pairs;
    read_pairs("data/sol_11_12_data", pairs);

    for (const auto &p : pairs) {
	cout << p.first << ": ";
	cout << p.second << endl;
    }
}
