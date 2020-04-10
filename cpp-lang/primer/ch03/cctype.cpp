#include <string>
using std::string;

#include <cctype>
using std::ispunct;
using std::toupper;
using std::isspace;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    // print count of punctuation characters
    string s = "Hello World!!!";
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s) {
        if (ispunct(c))
            ++punct_cnt;
    }
    cout << punct_cnt << " punctuation characters in " << s << endl;

    // convert s to upper case
    string orig = s;
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;

    // convert first character of s to upper case
    s = "some string";
    if (!s.empty())
        s[0] = toupper(s[0]);
    cout << s << endl;

    // convert first word of sto upper case
    // (using indexes)
    s = "some string";
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]);
    cout << s << endl;
    return 0;
}