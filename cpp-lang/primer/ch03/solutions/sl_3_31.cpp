/*
 * Exercise 3.31:
 * Write a program to define an array of ten ints. Give each
 * element the same value as its position in the array.
 */
#include <iostream>
using std::cout;
using std::endl;

 int main()
 {
    constexpr size_t size = 10;
    int array[size];
    for (size_t i = 0; i < size; ++i)
        array[i] = i;
    for (int i : array)
        cout << i << endl;
    return 0;
 }
