/*
 * Exercise 9.20:
 * Write a program to copy elements from a list<int> into two deques. The
 * even-valued elements should go into one deque and the odd ones into the
 * other.
 */

#include <list>
using std::list;

#include <deque>
using std::deque;

int main() {
    list<int> ilist;
    for (decltype(ilist.size()) i = 1; i <= 10; ++i) {
	ilist.push_back(i);
    }

    deque<int> even_vals;
    deque<int> odd_vals;

    for (auto i : ilist) {
	if (i % 2 == 0) {
	    odd_vals.push_back(i);
	} else {
	    even_vals.push_back(i);
	}
    }

    return 0;
}
