/*
 * Exercise 11.9:
 * Define a map that associates words with a list of line
 * numbers on which the word might occur.
 */

#include "chapter11.h"

#include <fstream>
#include <sstream>

using namespace std;

void read_words_occurrence(const string &file_name,
			   map<string, list<int>> &words_occur)
{
    ifstream in(file_name);
    if (!in.is_open())
	error("Failed to open file.");

    string line;
    int line_num = 0;
    while (getline(in, line)) {
	++line_num;
	istringstream str_in(line);
	string word;
	while (str_in >> word)
	    words_occur[word].push_back(line_num);
    }
}

void sol_11_9()
{
    map<string, list<int>> words_occurrence;
    read_words_occurrence("data/sol_11_9_data", words_occurrence);

    for (const auto & w : words_occurrence) {
	cout << w.first << ": ";
	for (const int &i : w.second)
	    cout << i << ", ";
	cout << endl;
    }
}
