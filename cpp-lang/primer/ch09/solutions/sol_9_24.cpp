/*
 * Exercise 9.24: Write a program that fetches the first element in a vector
 * using at, the subscript operator, front, and begin. Test your program on
 * an empty vector.
 */

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main() {
    vector<int> ivec = {777};

    cout << ivec.at(0) << endl;
    cout << ivec[0] << endl;
    cout << ivec.front() << endl;
    cout << *ivec.begin() << endl;

    return 0;
}
