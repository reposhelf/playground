/*
 * 
 * Exercise 8.4.
 *
 * Write a function to open a file for input and read its contents into a vector
 * of strings, storing each line as a separate element in the vector.
 *
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
    std::ifstream input(argv[1]);

    if (input) {
	std::vector<std::string> lines;
	std::string line;

	while (std::getline(input, line)) {
	    lines.push_back(line);
	}

	// test
	for (const auto &s : lines) {
	    std::cout << s << std::endl;
	}
    } else {
	std::cerr << "couldn't open file: " + std::string(argv[1]) << std::endl;
    }

    return 0;
}
