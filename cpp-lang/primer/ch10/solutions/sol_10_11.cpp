/*
 * Exercise 10.11:
 * Write a program that uses stable_sort and isShorter to sort a vector passed to your
 * version of elimDups. Print the vector to verify that your program is correct.
 */

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout; using std::endl; using std::cerr;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::stable_sort; using std::unique; using std::sort;

void print(const vector<string> &words)
{
    for (const string &w : words)
        cout << w << " ";
    cout << endl;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
    std::sort(words.begin(), words.end());
    auto it = unique(words.begin(), words.end());
    words.erase(it, words.end());
    stable_sort(words.begin(), words.end(), isShorter);
}

int main()
{
    ifstream in("sol_10_9_data");
    if (!in.is_open()) {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    vector<string> words;
    string word;
    while (in >> word)
        words.push_back(word);

    elimDups(words);
    print(words);

    return 0;
}