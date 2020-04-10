/*
 * Exercise 10.20:
 * The library defines an algorithm named count_if. Like find_if, this function takes
 * a pair of iterators denoting an input range and a predicate that it applies to each
 * element in the given range. count_if returns a count of how often the predicate is
 * true. Use count_if to rewrite the portion of our program that counted how many words
 * are greater than length 6.
 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <algorithm>
using std::sort;
using std::unique;
using std::for_each;
using std::stable_sort;
using std::find_if;
using std::count_if;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

void error(const char *msg)
{
    cout << msg << endl;
    exit(1);
}

void elimDups(vector<string> &v)
{
    sort(v.begin(), v.end());
    auto unique_end = unique(v.begin(), v.end());
    v.erase(unique_end, v.end());
}

string make_plural(size_t count, const string &word, const string &ending)
{
    return (count > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
        [] (const string &s1, const string &s2)
            { return s1.size() < s2.size(); });
    auto it = find_if(words.begin(), words.end(),
        [sz] (const string &s) { return s.size() >= sz; });

    auto count = count_if(words.begin(), words.end(),
        [sz] (const string &s) { return s.size() >= sz; });
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;

    for_each(it, words.end(), [] (const string &s) { cout << s << " "; });
    cout << endl;
}

int main()
{
    ifstream in("sol_10_9_data");
    if (!in.is_open())
        error("Failed to open file.");

    string word;
    vector<string> words;
    while (in >> word)
        words.push_back(word);

    biggies(words, 5);

    return 0;
}