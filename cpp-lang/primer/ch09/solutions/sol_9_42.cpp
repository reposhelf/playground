/*
 * Exercise 9.42:
 * Given that you want to read a character at a time into a string, and you
 * know that you need to read at least 100 characters, how might you improve
 * the performance of your program?
 */

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

void error(const char *msg) {
    cerr << msg << endl;
    exit(1);
}

int main() {
    ifstream in("sol_9_42_data");
    if (!in.is_open())
	error("Cann't open file");

    string str;
    str.reserve(158);
    char ch;
    while (in >> ch)
	str.push_back(ch);

    cout << str << endl;
    cout << "size: " << str.size() << endl;
    cout << "capacity: " << str.capacity() << endl;

    return 0;
}
