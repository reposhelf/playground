#include "array.h"

#include <iostream>

void rand(Item a[], int count)
{
    // TODO: use unsigned type for count
    for (int i = 0; i != count; ++i) {
        rand(a[i]);
    }
}

void scan(Item a[], int &count)
{
    // TODO: use unsigned type for count
    for (int i = 0; i != count; ++i) {
        if (!scan(a[i])) {
            break;
        }
        count = i;
    }
}

void show(Item a[], int left, int right)
{
    // TODO: use unsigned type for left and right
    for (int i = left; i <= right; ++i) {
        show(a[i]);
    }
    std::cout << std::endl;
}

void sort(Item a[], int left, int right)
{

}
