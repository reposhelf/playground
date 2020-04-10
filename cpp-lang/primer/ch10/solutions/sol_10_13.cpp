/*
 * Exercise 10.13:
 * The library defines an algorithm named partition that takes a predicate and
 * partitions the container so that values for which the predicate is true appear in the
 * first part and those for which the predicate is false appear in the second part. The
 * algorithm returns an iterator just past the last element for which the predicate
 * returned true. Write a function that takes a string and returns a bool indicating
 * whether the string has five characters or more. Use that function to partition
 * words. Print the elements that have five or more characters.
 */

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout; using std::cerr; using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::partition;

bool hasFiveOrMoreCharacters(const string &str)
{
    return str.size() >= 5;
}

int main()
{
    ifstream in("sol_10_13_data");
    if (!in.is_open()) {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    vector<string> words;
    string word;
    while (in >> word)
        words.push_back(word);

    auto it_end = partition(words.begin(), words.end(), hasFiveOrMoreCharacters);
    for (auto it = words.begin(); it != it_end; ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}