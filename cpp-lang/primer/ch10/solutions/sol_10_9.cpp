/*
 * Exercise 10.9:
 * Implement your own version of elimDups. Test your program by printing the vector
 * after you read the input, after the call to unique, and after the call to erase.
 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout; using std::endl; using std::cerr;

#include <algorithm>
using std::sort; using std::unique;

void print(const vector<string> &vec)
{
    for (const string &s : vec)
        cout << s << " ";
    cout << endl;
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto unique_end = unique(words.begin(), words.end());
    print(words);
    words.erase(unique_end, words.end());
    print(words);
}

int main()
{
    ifstream in("sol_10_9_data");
    if (!in.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    vector<string> words;
    string word;
    while (in >> word)
        words.push_back(word);

    print(words);
    elimDups(words);

    return 0;
}