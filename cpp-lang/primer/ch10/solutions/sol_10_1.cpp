/*
 * Exercise 10.1:
 * The algorithm header defines a function named count that, like find, takes
 * a pair of iterators and a value. count returns a count of how often that
 * value appears. Read a sequence of ints into a vector and print the count of
 * how many elements have a given value.
 */

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <algorithm>

int main()
{
    ifstream in("sol_10_1_data");
    if (!in.is_open()) {
	cerr << "Cannot open file" << endl;
	exit(1);
    }

    vector<int> ivec;
    int num;
    while (in >> num)
	ivec.push_back(num);

    cout << std::count(ivec.cbegin(), ivec.cend(), 69);

    return 0;
}
