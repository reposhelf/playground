/*
 * Exercise 9.50:
 * Write a program to process a vector<string>s whose elements represent
 * integral values. Produce the sum of all the elements in that vector. Change
 * the program so that it sums of strings that represent floating-point values.
 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<string> svec = {"15.3", "21.4", "4.1", "12.4", "3.0"};
    double sum = .0;
    for (const string &s : svec)
	sum += stod(s);
    cout << sum << endl;
    return 0;
}
