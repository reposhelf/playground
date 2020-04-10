/*
 * Exercise 11.8:
 * Write a program that stores the excluded words in a vector
 * instead of in a set. What are the advantages to using a set?
 */

#include "chapter11.h"

#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

void read_word_count_2(const std::string &file_name,
		       std::map<std::string, size_t> &dest)
{
    static const vector<string> exclude = {
        "The", "And", "Or", "But", "A", "An", "Vs"
        "the", "and", "or", "but", "a", "an", "vs"
    };

    ifstream in(file_name);
    if (!in.is_open())
        error("Failed to open file.");

    string word;
    while (in >> word) {
        if (find(exclude.cbegin(), exclude.cend(), word) != exclude.end())
            continue;

        if (ispunct(word.back()))
            word.pop_back();

        for (auto &w : word)
	    w = tolower(w);

        ++dest[word];
    }
}

void sol_11_8()
{
    map<string, size_t> word_count;
    read_word_count("data/sol_11_8_data", word_count);
    for (const auto &w : word_count) {
        cout << w.first << " occurs " << w.second
             << (w.second > 1 ? " times" : " time") << endl;
    }
}
