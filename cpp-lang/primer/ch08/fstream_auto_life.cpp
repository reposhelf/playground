#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    for (auto p = argv + 1; p != argv + argc; ++p) {
	std::ifstream input(*p);

	if (input) {
	    std::cout << "file was opened: " << std::string(*p) << std::endl;
	} else {
	    std::cerr << "couldn't open: " + std::string(*p) << std::endl;
	}
    }
    return 0;
}
