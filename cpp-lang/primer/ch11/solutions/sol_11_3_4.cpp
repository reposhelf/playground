/*
 * Exercise 11.3 - 11.4:
 * Write your own version of the word-counting program.
 * Extend your program to ignore case and punctuation. For
 * example, “example.” “example,” and “Example” should all increment the same
 * counter.
 */

#include "chapter11.h"

#include <fstream>
#include <set>
#include <cctype>

using namespace std;

void read_word_count(const string &file_name, map<string, size_t> &dest)
{
    static const set<string> exclude = {
        "The", "And", "Or", "But", "A", "An", "Vs"
        "the", "and", "or", "but", "a", "an", "vs"
    };

    ifstream in(file_name);
    if (!in.is_open())
        error("Failed to open file.");

    string word;
    while (in >> word) {
        if (exclude.find(word) != exclude.end())
            continue;

        if (ispunct(word.back()))
            word.pop_back();

        for (auto &w : word)
	    w = tolower(w);

        ++dest[word];
    }
}

void sol_11_3_4()
{
    map<string, size_t> word_count;
    read_word_count("data/sol_11_3_4_data", word_count);
    for (const auto &w : word_count) {
        cout << w.first << " occurs " << w.second
             << (w.second > 1 ? " times" : " time") << endl;
    }
}
