/*
 * Exercise 3.17:
 * Read a sequence of words from cin and store the values a
 * vector. After you’ve read all the words, process the vector and change
 * each word to uppercase. Print the transformed elements, eight words to a
 * line.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::toupper;

int main()
{
    vector<string> words;
    string word;
    while (cin >> word)
        words.push_back(word);

    for (auto &w : words) {
        for (auto &c : w)
            c = toupper(c);
    }

    const int max_word_count_per_line = 8;
    int word_count = 0;
    for (auto w : words) {
        cout << w << " ";
        if (++word_count % max_word_count_per_line == 0)
            cout << endl;
    }
    cout << endl;

    return 0;
}