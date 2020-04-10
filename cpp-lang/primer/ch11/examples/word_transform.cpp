#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

void error(const char *msg)
{
    cout << msg << endl;
    exit(1);
}

map<string, string> build_map(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)) {
	if (value.size() > 1)
	    trans_map[key] = value.substr(1);
	else
	    throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
	return map_it->second;
    return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = build_map(map_file);
    string text;
    while (getline(input, text)) {
	istringstream stream(text);
	string word;
	bool firstword = true;
	while (stream >> word) {
	    if (firstword)
		firstword = false;
	    else
		cout << ' ';
	    cout << transform(word, trans_map);
	}
	cout << endl;
    }
}

int main()
{
    ifstream map_file("data/rules");
    if (!map_file.is_open())
	error("Filed to open 'data/rules' file");

    ifstream input("data/text");
    if (!input.is_open())
	error("Failed to open 'data/text' file");

    word_transform(map_file, input);

    return 0;
}
