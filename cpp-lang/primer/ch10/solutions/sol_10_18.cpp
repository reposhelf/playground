/*
 * Exercise 10.18:
 * Rewrite biggies to use partition instead of find_if.
 */

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::unique;
using std::stable_sort;
using std::for_each;
using std::partition;

void error(const char *msg)
{
    cerr << msg << endl;
    exit(1);
}

void elimDups(vector<string> &v)
{
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);

    stable_sort(words.begin(), words.end(),
        [] (const string &s1, const string &s2)
            { return s1.size() < s2.size(); });

    auto it = partition(words.begin(), words.end(),
        [sz] (const string &s) { return s.size() < sz; });

    for_each(it, words.end(), [] (const string &s) { cout << s << " "; });
    cout << endl;
}

int main()
{
    ifstream in("sol_10_9_data");
    if (!in.is_open())
        error("Falied to open file.");

    vector<string> words;
    string word;
    while (in >> word)
        words.push_back(word);

    biggies(words, 5);

    return 0;
}