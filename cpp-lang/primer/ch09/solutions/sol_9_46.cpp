/*
 * Exercise 9.46:
 * Rewrite exercise 9.45 using a position and length to manage the
 * strings. This time use only the insert function.
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

string &format(string &s, const string &suffix, const string &prefix) {
    s.insert(0, suffix, 0, suffix.size());
    s.insert(s.size(), prefix, 0, prefix.size());
    return s;
}

int main() {
    string name = "Michael Jordan";
    string suffix = "Mr. ";
    string prefix = " I";

    cout << name << endl;
    name = format(name, suffix, prefix);
    cout << name << endl;

    name = "Phillip";
    suffix = "Mr. ";
    prefix = " III";

    cout << name << endl;
    name = format(name, suffix, prefix);
    cout << name << endl;

    return 0;
}
