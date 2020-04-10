/*
 * Exercise 9.31:
 * The program on page 354 to remove even-valued elements and duplicate odd
 * ones will not work on a list or forward_list. Why? Revise the program so
 * that it works on these types as well.
 */

#include <list>
using std::list;

#include <forward_list>
using std::forward_list;

#include <iostream>
using std::cout;
using std::endl;

void do_list() {
    list<int> il = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto it = il.begin();
    auto end = il.end();

    while (it != end) {
	if (*it % 2) {
	    it = il.insert(it, *it);
	    ++it;
	    ++it;
	} else {
	    it = il.erase(it);
	}
    }

    for (auto i : il)
	cout << i << " ";
    cout << endl;
}

void do_forward_list() {
    forward_list<int> ifl = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = ifl.before_begin();
    auto curr = ifl.begin();
    auto end = ifl.end();

    while (curr != end) {
	if (*curr % 2) {
	    curr = ifl.insert_after(curr, *curr);
	    prev = curr;
	    ++curr;
	} else {
	    curr = ifl.erase_after(prev);
	}
    }

    for (auto i : ifl)
	cout << i << " ";
    cout << endl;
}

int main() {
    do_list();
    do_forward_list();
    return 0;
}
