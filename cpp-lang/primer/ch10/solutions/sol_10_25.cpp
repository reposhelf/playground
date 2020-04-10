/*
 * Exercise 10.25:
 * In the exercises for § 10.3.2 (p. 392) you wrote a version of biggies that uses
 * partition. Rewrite that function to use check_size and bind.
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

#include <functional>
using std::bind;

using namespace std::placeholders;

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

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);

    stable_sort(words.begin(), words.end(),
        [] (const string &s1, const string &s2)
            { return s1.size() < s2.size(); });

    auto it = partition(words.begin(), words.end(), bind(check_size, _1, sz));

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