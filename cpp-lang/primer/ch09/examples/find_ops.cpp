#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string numbers = "0123456789";
    string name = "r2d2";
    string::size_type pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
	cout << "Found number at index: " << pos
	     << " element is " << name[pos] << endl;
	++pos;
    }
    return 0;
}
