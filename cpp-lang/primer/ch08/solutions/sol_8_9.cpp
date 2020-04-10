#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

std::istream &read(std::istream &is) {
    string word;
    while (is >> word) {
	cout << word << endl;
    }

    is.clear();

    return is;
}

int main() {
    string line("Hello, world!");

    istringstream stream(line);

    read(stream);

    return 0;
}
