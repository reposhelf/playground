/*
 * 4.3
 * Modify the point ADT implementation in Program 4.3 to represent points with polar coordinates.
 */
#include "polar.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    constexpr size_t polars_count = 10;
    Polar *polars = new Polar[polars_count];
    for (size_t i = 0; i != polars_count; ++i) {
        for (size_t j = i + 1; j != polars_count; ++j) {
            cout << polars[i].distance(polars[j]) << endl;
        }
    }
    delete[] polars;
    return 0;
}
