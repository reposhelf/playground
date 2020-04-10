/*
 *
 * Exercise 8.10.
 *
 * Write a program to store each line from a file in a vector<string>.
 * Now use an istringstream to read each element from the vector a word
 * at a time.
 *
 */

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char **argv) {
    vector<string> lines;

    ifstream input(argv[1]);

    string line;

    while (std::getline(input, line)) {
	lines.push_back(line);
    }

    for (const auto &ln : lines) {
	istringstream record(ln);

	string word;

	while (record >> word) {
	    cout << word << endl;
	}
    }

    return 0;
}
