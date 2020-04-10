#include <string>
using std::string;
using std::getline;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

string::size_type find_char(const string s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

int main()
{
    string s;
    char c;
    string::size_type occurs = 0;

    if (!getline(cin, s)) return 1;
    if (!(cin >> c)) return 1;
    
    cout << "first occur of " << c << ": " << find_char(s, c, occurs) << endl;
    cout << c << " occured " << occurs << " times" << endl;
}