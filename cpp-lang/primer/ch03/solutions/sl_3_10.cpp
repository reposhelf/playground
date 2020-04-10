#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::ispunct;

#include <string>
using std::string;

int main()
{
    string line;
    string text;
    // read data
    while (getline(cin, line)) {
        text += line;
    }
    // modify data
    string::iterator it = text.begin();
    while (it != text.end()) {
        if (ispunct(*it)) {
            it = text.erase(it);
        } else {
            ++it;
        }
    }
    // print modified data
    cout << text << endl;
    return 0;
}