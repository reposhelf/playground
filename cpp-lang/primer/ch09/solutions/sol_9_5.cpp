/*
 * Exercise 9.5:
 * Write a function that takes a pair of iterators to a vector<int> and an int
 * value. Look for that value in the range and return an iterator to the
 * requested element. Note that the program must handle the case where the 
 * element is not found.
 */

#include <cstdlib>
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

vector<int>::iterator includes(vector<int>::iterator first,
			       vector<int>::iterator last,
			       int value) {
    for (; first != last; ++first) {
	if (*first == value) {
	    return first;
	}
    }
    return last;
}

int main(int argc, char **argv) {
    vector<int> i_vec{1, 2, 5, 78, 35, 46, 52, 89};
    vector<int>::iterator it = includes(i_vec.begin(),
					i_vec.end(),
					atoi(argv[1]));
    if (it != i_vec.end())
	cout << *it << endl;

    return 0;
}
