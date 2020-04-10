/*
 * Exercise 11.38:
 * Rewrite the word-counting (§ 11.1, p. 421) and word-
 * transformation (§ 11.3.6, p. 440) programs to use an unordered_map.
 */

#include "chapter11.h"

#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

unordered_map<string, string> build_map(ifstream &map_file)
{
    unordered_map<string, string> map_transform;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)) {
	if (value.size() >1)
	    map_transform[key] = value.substr(1);
	else
	    throw runtime_error("failed value for key " + key);
    }
    return map_transform;
}

const string &transform(const string &s, const unordered_map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
	return map_it->second;
    return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto map_transform = build_map(map_file);
    string text;
    while (getline(input, text)) {
	istringstream stream(text);
	string word;
	bool first_word = true;
	while (stream >> word) {
	    if (first_word)
		first_word = false;
	    else
		cout << ' ';
	    cout << transform(word, map_transform);
	}
	cout << endl;
    }
}

void sol_11_38_2()
{
    ifstream map_file("data/rules");
    if (!map_file.is_open())
	error("Falied to open 'rules' file");

    ifstream input("data/text");
    if (!input.is_open())
	error("Failed to open 'text' file");

    word_transform(map_file, input);
}
