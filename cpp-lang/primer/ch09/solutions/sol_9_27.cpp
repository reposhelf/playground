/*
 * Exercise 9.27:
 * Write a program to find and remove the odd-valued elements in a
 * forward_list<int>.
 */

#include <forward_list>
using std::forward_list;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

forward_list<int> &remove_odds(forward_list<int> &flist) {
    auto prev = flist.before_begin();
    auto curr = flist.begin();
    auto last = flist.end();

    while (curr != last) {
	if (*curr % 2) {
	    curr = flist.erase_after(prev);
	} else {
	    prev = curr;
	    ++curr;
	}
    }

    return flist;
}

void error(const char *msg) {
    cerr << msg << endl;
    exit(1);
}

int main() {
    ifstream in("sol_9_27_data");
    if (!in.is_open())
	error("Cann't open file");

    forward_list<int> flist;
    auto it = flist.before_begin();
    int value;
    while (in >> value)
	it = flist.insert_after(it, value);

    flist = remove_odds(flist);

    for (auto i : flist)
	cout << i << " ";
    cout << endl;

    return 0;
}
