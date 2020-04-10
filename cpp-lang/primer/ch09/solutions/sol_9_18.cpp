/*
 * Exercise 9.18:
 * Write a program to read a sequence of strings from the standard input into
 * a deque. Use iterators to write a loop to print the elements in the deque.
 */

#include <iostream>
using std::cin;

#include <string>
using std::string;

#include <deque>
using std::deque;

int main() {
    string word;
    deque<string> words;
    auto it = words.begin();
    while (cin >> word) {
	it = words.insert(it, word);
    }
    return 0;
}
