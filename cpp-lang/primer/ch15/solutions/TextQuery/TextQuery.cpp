#include "TextQuery.h"
#include "QueryResult.h"

#include <sstream>
#include <algorithm>

using namespace std;

TextQuery::TextQuery(ifstream &is)
    : file(new vector<string>)
{
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;

        istringstream line(text);
        string word;
        while (line >> word) {
            word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    return QueryResult(sought, loc->second, file);
}
