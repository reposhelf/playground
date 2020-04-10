/*
 * Exercise 9.41:
 * Write a program that initializes a string from a vector<char>.
 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main() {
    vector<char> cvec = {'H', 'e', 'l', 'l', 'o', '!'};
    string str(cvec.cbegin(), cvec.cend());
    cout << str << endl;
    return 0;
}
