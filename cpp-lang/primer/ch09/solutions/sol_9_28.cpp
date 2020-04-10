/*
 * Exercise 9.28:
 * Write a function that takes a forward_list<string> and two additional string
 * arguments. The function should find the first string and insert the second 
 * immediately following the first. If the first string is not found, then
 * insert the second string at the end of the list.
 */

#include <forward_list>
using std::forward_list;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::cin;

void error(const char *msg) {
    cerr << msg << endl;
    exit(1);
}

forward_list<string> &insert_after_occurrence(forward_list<string> &flist,
					      const string &occurrence,
					      const string &value) {
    auto prev = flist.before_begin();
    auto curr = flist.begin();
    auto last = flist.end();
    while (curr != last) {
	if (*curr == occurrence) {
	    flist.insert_after(curr, value);
	    return flist;
	}
	prev = curr;
	++curr;
    }
    flist.insert_after(prev, value);
    return flist;
}

forward_list<string> &read_file(const string &file_name,
				forward_list<string> &flist) {
    ifstream in(file_name);
    if (!in.is_open())
	error("Cann't open file");

    auto it = flist.before_begin();
    string value;
    while (in >> value)
	it = flist.insert_after(it, value);

    return flist;
}

void print_forward_list(const forward_list<string> &flist) {
    for (auto i : flist)
	cout << i << " ";
    cout << endl;
}

int main() {
    forward_list<string> flist;
    flist = read_file("sol_9_28_data", flist);

    string occurrence;
    string value;
    while (true) {
	cin >> occurrence >> value;
	flist = insert_after_occurrence(flist, occurrence, value);
	print_forward_list(flist);

	char c;
	do {
	    cout << "Do you want to continue? (y/n): ";
	    cin >> c;
	} while (c != 'y' && c != 'n');

	if (c == 'n')
	    break;
    }
    
    return 0;
}
