/*
 * 4.4
 * Write a client program that takes an integer N from the command line, and fills an array with
 * N points, no two of which are equal. Use the overloaded== operator described in the text to
 * test equality.
 */
#include "point.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << "At least one parameter is required" << endl;
        return 1;
    }

    const size_t point_count = atoi(argv[1]);
    Point *points = new Point[point_count];
    Point **unique_points = new Point*[point_count];

    for (size_t i = 0; i != point_count; ++i) {
        for (size_t j = 0; j != point_count; ++j) {
            if (unique_points[j] == 0) {
                unique_points[j] = &points[i];
                break;
            }
            if (*unique_points[j] == points[i])
                break;
        }
    }

    for (size_t i = 0; unique_points[i] != 0 || i != point_count; ++i)
        cout << *unique_points[i] << endl;

    delete[] points;
    delete[] unique_points;
    return 0;
}
