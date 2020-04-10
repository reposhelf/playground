/*
 * Exercise 12.26:
 * Rewrite the exercise 12.23 using an allocator.
 */

#include "chapter12.h"

#include <cstring>

using namespace std;

void sol_12_26()
{
    const char *s1 = "Gens una ";
    const char *s2 = "sumus!";

    const size_t n = 50;
    allocator<char> alloc;
    auto p = alloc.allocate(n);

    auto q = uninitialized_copy_n(s1, strlen(s1), p);
    q = uninitialized_copy_n(s2, strlen(s2), q);

    for (auto i = p; i != q; ++i)
        cout << *i;
    cout << endl;

    // free memory
    for (auto i = p; i != q; ++i)
        alloc.destroy(i);

    alloc.deallocate(p, n);
}
