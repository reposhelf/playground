#include <iostream>
using std::cout;
using std::endl;
using std::cin;

std::istream &read(std::istream &is) {
    char ch;
    while (is >> ch) {
	cout << ch;
    }
    cout << endl;

    is.clear();

    return is;
}

int main() {
    read(cin);
    return 0;
}
