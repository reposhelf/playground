/*
 * Exercise 12.28:
 * Write a program to implement text queries without defining
 * classes to manage the data. Your program should take a file and interact
 * with a user to query for words in that file. Use vector, map, and set
 * containers to hold the data for the file and to generate the results for the
 * queries.
 */

#include "chapter12.h"

#include <vector>
#include <fstream>
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

void sol_12_28()
{
    ifstream infile("storyDataFile");
    assert(infile.is_open());

    vector<string> text;
    string t;
    while (getline(infile, t))
        text.push_back(t);

    string word;
    do {
        cout << "Enter word to look for, or q to quit: ";
        if (!(cin >> word) || word == "q")
            break;
        
        map<size_t, string> lines;
        size_t word_count = 0;
        for (size_t i = 0; i < text.size(); ++i) {
            istringstream iss(text[i]);
            string s;
            while (iss >> s) {
                if (s == word) {
                    ++word_count;
                    lines.insert({i + 1, text[i]});
                }
            }
        }

        cout << word << " occurs " << word_count << " times" << endl;
        for (const auto &p : lines) {
            cout << string(4, ' ');
            cout << "(line " << p.first << ") ";
            cout << p.second << endl;
        }
    } while (true);
}
