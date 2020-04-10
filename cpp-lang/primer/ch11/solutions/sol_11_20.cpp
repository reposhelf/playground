/*
 * Exercise 11.20:
 * Rewrite the word-counting program from § 11.1 (p. 421) to
 * use insert instead of subscripting. Which program do you think is easier to
 * write and read? Explain your reasoning.
 */

#include "chapter11.h"

using namespace std;

void sol_11_20()
{
    map<string, size_t> word_count;
    string word;
    /*
    while (cin >> word) {
	auto ret = word_count.insert({word, 1});
	if (!ret.second)
	    ++ret.first->second;
    }
    */
    while (cin >> word)
	++word_count.insert({word, 0}).first->second;

    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second 
	     << (w.second > 1 ? " times" : " time") << endl;
}

