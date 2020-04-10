#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string s("Some string");
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s << endl;

    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it);
    cout << s << endl;
    return 0;
}