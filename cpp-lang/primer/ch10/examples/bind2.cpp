#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;
using namespace std::placeholders;

ostream &print(ostream &os, const string &s, char separ)
{
    return os << s << separ;
}

int main()
{
    string s;
    vector<string> words;
    while (cin >> s)
        words.push_back(s);
    for_each(words.begin(), words.end(), bind(print, ref(cout), _1, ' '));
    cout << endl;

    ofstream os("outFile1");
    for_each(words.begin(), words.end(), bind(print, ref(os), _1, ' '));
    os << endl;

    ifstream in("outFile1");
    istream_iterator<string> it(in), eof;
    for_each(it, eof, bind(print, ref(cout), _1, ' '));
    cout << endl;

    return 0;
}