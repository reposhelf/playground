/*
 * 4.2
 * Add a member function to the point class in Program 4.3 that returns the distance to the origin.
 */
#include "point.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    constexpr size_t point_count = 10;
    Point *points = new Point[point_count];
    for (size_t i = 0; i != point_count; ++i) {
        cout << points[i] << endl;
        cout << points[i].distance() << endl;
    }
    delete[] points;
    return 0;
}
