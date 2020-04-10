/*
 * 4.1
 * Suppose that we wish to count the number of pairs of points that fall within a square of
 * size d. Give two different versions of client and implementation to solve this problem: first,
 * modify distance appropriately; second, replace distance with X and Y member functions.
 */
#include "point.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    if (argc < 4) {
        cout << "Four parameters are required." << endl << endl;;
        cout << "    Parameters order:" << endl;
        cout << "[1] - count of points." << endl;
        cout << "[2] - x of the square." << endl;
        cout << "[3] - y of the square." << endl;
        cout << "[4] - size of the square's side." << endl;
        return 1;
    }

    const size_t point_count = atoi(argv[1]);
    const float square_x = atof(argv[2]);
    const float square_y = atof(argv[3]);
    const float square_side = atof(argv[4]);

    Point *points = new Point[point_count];

    const Point topLeft(square_x, square_y);
    const Point bottomRight(square_x + square_side, square_y + square_side);

    // 1st way
    int inclusion_count = 0;
    for (size_t i = 0; i != point_count; ++i) {
        const Point &p = points[i];
        if (p.distance(topLeft.x(), p.y()) <= square_side
                && p.distance(bottomRight.x(), p.y()) <= square_side
                && p.distance(p.x(), topLeft.y()) <= square_side
                && p.distance(p.x(), bottomRight.y()) <= square_side) {
            ++inclusion_count;
            cout << p << endl;
        }
    }
    cout << inclusion_count << " within square: " << square_x << ", "
         << square_y << ", " << square_side << endl << endl;

    // 2nd way
    inclusion_count = 0;
    for (size_t i = 0; i != point_count; ++i) {
        const Point &p = points[i];
        if (points[i].x() >= topLeft.x()
                && p.y() >= topLeft.y()
                && p.x() <= bottomRight.x()
                && p.y() <= bottomRight.y()) {
            ++inclusion_count;
            cout << points[i] << endl;
        }
    }
    cout << inclusion_count << " within square: " << square_x << ", "
         << square_y << ", " << square_side << endl;

    delete[] points;

    return 0;
}
