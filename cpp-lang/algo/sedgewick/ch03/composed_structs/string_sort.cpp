#include "string_sort.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int compare(const void *c1, const void *c2)
{
    return strcmp(*(static_cast<char**>(const_cast<void*>(c1))),
                  *(static_cast<char**>(const_cast<void*>(c2))));
}

void string_sort_test_drive()
{
    static const size_t PTR_MAX = 1000;
    static const size_t CHAR_MAX = 10000;

    char *pointers[PTR_MAX];
    char buffer[CHAR_MAX];

    size_t m = 0;
    size_t n;
    for (n = 0; n < PTR_MAX; ++n) {
        pointers[n] = &buffer[m];
        if (!(cin >> pointers[n]))
            break;
        m += strlen(pointers[n]) + 1;
    }

    qsort(pointers, n, sizeof(char*), compare);

    for (size_t i = 0; i < n; ++i)
        cout << pointers[i] << endl;
}