/*
 * Exercise 11.38:
 * Rewrite the word-counting (§ 11.1, p. 421) and word-
 * transformation (§ 11.3.6, p. 440) programs to use an unordered_map.
 */

#include "chapter11.h"

#include <unordered_map>

using namespace std;

void sol_11_38_1()
{
    unordered_map<string, size_t> word_count;
    string word;
    while (cin >> word)
	++word_count[word];

    for (const auto &w : word_count) {
	cout << w.first << " occurs " << w.second
	     << (w.second > 1 ? " times" : " time") 
	     << endl;
    }
}
