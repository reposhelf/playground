/*
 * Exercise 9.19:
 * Rewrite the program from exercise 9.18 to use a list.
 */

#include <iostream>
using std::cin;

#include <string>
using std::string;

#include <list>
using std::list;

int main() {
    string word;
    list<string> words;
    auto it = words.begin();
    while (cin >> word) {
	it = words.insert(it, word);
    }
    return 0;
}
