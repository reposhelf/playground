/*
 * Exercise 5.16:
 * Write a recursive program that finds the maximum element, based on comparing
 * the first element in the array against the maximum element in the rest of
 * the array (computed recursively).
 */

#include "chapter05.h"
using namespace std;

int max(int array[], int first, int last) // [first, last)
{
    if (last == 0)
        return 0;

    if (first == last - 1)
        return array[first];

    int maxFromArray = max(array, first + 1, last);
    return (array[first] > maxFromArray ? array[first] : maxFromArray);
}

void sol_5_16()
{
    int values[] = {
        100, 781, 654, 123, 589,
        547, 689, 257, 498, 588,
        698, 753, 398, 879, 985,
        265, 981, 467, 352, 598,
        599, 300, 401, 456, 687};

    cout << max(values, 0, sizeof(values) / sizeof(int)) << endl;
}