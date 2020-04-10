/*
 * Exercise 3.35:
 * Using pointers, write a program to set the elements in an
 * array to zero.
 */
#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::begin;
using std::end;

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Array before handling: ";
    for (auto i : array)
    {
        cout << i << " ";
    }
    cout << endl;

    // set the elements to zero
    for (auto b = begin(array), e = end(array); b != e; ++b)
    {
        *b = 0;
    }

    cout << "Array after handling: ";
    for (auto i : array)
    {
        cout << i << " ";
    }
    cout << endl;
        
    return 0;
}
