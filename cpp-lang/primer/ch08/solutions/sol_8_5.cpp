/*
 * 
 * Exercise 8.5.
 *
 * Rewrite exercise 8.4 to store each word in a separate element.
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

	while (input >> line) {
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
