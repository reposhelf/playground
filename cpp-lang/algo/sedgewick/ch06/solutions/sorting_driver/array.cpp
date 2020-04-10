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
    /*
     * typo in the book (page 281, rus. edition)
     *
     * void scan(Item a[], int &N)
     * { for (int i = 0; i < N; i++)
     *     if (!scan(a[i])) break;
     *   N = i; <--- 'i' was not declared in this scope
     * }
     */

    // TODO: use unsigned type for count
    int i = 0;
    for (; i != count; ++i) {
        if (!(std::cin >> a[i])) {
            break;
        }
    }
    count = i;
}

void show(Item a[], int left, int right)
{
    // TODO: use unsigned type for left and right
    for (int i = left; i <= right; ++i) {
        std::cout << a[i] << std::endl;
    }
    std::cout << std::endl;
}

void sort(Item a[], int left, int right)
{

}
