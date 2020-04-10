#include "point.h"

#include <cstdlib>
#include <iostream>
using namespace std;

float randFloat()
{
    return 1.0 * rand() / RAND_MAX;
}

int main(int argc, char *argv[])
{
    const int pointCount = atoi(argv[1]);
    if (!pointCount)
    {
        cout << "error: invalid value" << endl;
        return 0;
    }

    const float ethalonDistance = atof(argv[2]);
    if (ethalonDistance == 0.0)
    {
        cout << "error: invalid value" << endl;
        return 0;
    }

    Point *points = new Point[pointCount];
    for (int i = 0; i < pointCount; ++i)
    {
        points[i].x = randFloat();
        points[i].y = randFloat();
    }

    int count = 0;
    for (int i = 0; i < pointCount; ++i)
    {
        for (int j = i + 1; j < pointCount; ++j)
        {
            if (distance(points[i], points[j]) < ethalonDistance)
            {
                ++count;
            }
        }
    }

    cout << count << " pairs within " << ethalonDistance << endl;

    return 0;
}