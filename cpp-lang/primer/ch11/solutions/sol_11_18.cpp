/*
 * Exercise 11.18:
 * Write the type of map_it from the loop on page 430
 * without using auto or decltype.
 */

#include "chapter11.h"

using namespace std;

void sol_11_18()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    
    map<string, size_t>::iterator map_it = word_count.begin();
    while (map_it != word_count.end()) {
        cout << map_it->first << " occurs " << map_it->second 
	     << (map_it->second > 1 ? " times" : " time") << endl;
	++map_it;
    }
}
