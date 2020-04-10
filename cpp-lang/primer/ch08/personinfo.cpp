#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <sstream>
using std::istringstream;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string line;
    vector<PersonInfo> people;

    while (std::getline(cin, line)) {
	istringstream record(line);

	PersonInfo person;

	record >> person.name;

	string phone;
	while (record >> phone) {
	    person.phones.push_back(phone);
	}

	people.push_back(person);
    }

    // test
    for (auto person : people) {
	cout << person.name << ":" << endl;

	for (auto phone : person.phones) {
	    cout << "\t" << phone << endl;
	}
    }

    return 0;
}
