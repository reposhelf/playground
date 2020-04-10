/*
 * Exercise 3.20:
 * Read a set of integers into a vector. Print the sum of each
 * pair of adjacent elements. Change your program so that it prints the sum of
 * the first and last elements, followed by the sum of the second and second-to-
 * last, and so on.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main()
{
    vector<int> numbers;
    int number;
    while (cin >> number)
        numbers.push_back(number);

    for (decltype(numbers.size()) i = 0, j = i + 1;
         i < numbers.size() && j < numbers.size();
         i += 2, j += 2) {
        cout << numbers[i] + numbers[j] << endl;
    }

    for (decltype(numbers.size()) i = 0, j = numbers.size() - 1;
         i != j && i < j; ++i, --j) {
        cout << numbers[i] + numbers[j] << endl;
    }
    return 0;
}