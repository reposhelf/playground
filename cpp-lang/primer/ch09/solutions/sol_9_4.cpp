/*
 * Exercise 9.4:
 * Write a function that takes a pair of iterators to a vector<int> and an int
 * value. Look for that value in the range and return a bool indicating whether
 * it was found.
 */

#include <cstdlib>
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

bool includes(vector<int>::const_iterator first,
	      vector<int>::const_iterator last,
	      int value) {
    for (; first != last; ++first) {
	if (*first == value) {
	    return true;
	}
    }
    return false;
}

int main(int argc, char **argv) {
    vector<int> i_vec{1, 2, 5, 78, 35, 46, 52, 89};
    cout << includes(i_vec.begin(), i_vec.end(), atoi(argv[1])) << endl;
    return 0;
}
