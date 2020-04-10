#include "textquery.h"

#include <sstream>

using namespace std;

TextQuery::TextQuery(ifstream &input)
    : _lines_ptr(new map<size_t, string>())
{
    string line;
    while (getline(input, line))
        _text.push_back(line);
}

QueryResult TextQuery::query(const string &word) const
{
    size_t word_count = 0;
    _lines_ptr->clear();
    for (size_t i = 0; i < _text.size(); i++) {
        istringstream iss(_text[i]);
        string t;
        while (iss >> t) {
            if (t == word) {
                ++word_count;
                _lines_ptr->insert({i + 1, _text[i]});
            }
        }
    }

    return QueryResult(word_count, word, _lines_ptr);
}
