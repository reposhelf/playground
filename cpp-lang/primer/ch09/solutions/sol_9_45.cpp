/*
 * Exercise 9.45:
 * Write a funtion that takes a string representing a name and two other
 * strings representing a prefix, such as “Mr.” or “Ms.” and a suffix, such as
 * “Jr.” or “III”. Using iterators and the insert and append functions,
 * generate and return a new string with the suffix and prefix added to the
 * given name.
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

string &format(string &s, const string &suffix, const string &prefix) {
    s.insert(s.begin(), suffix.begin(), suffix.end());
    s.append(prefix);
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
