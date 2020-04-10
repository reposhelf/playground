#include "point.h"

#include <iostream>
using namespace std;

int main()
{
    Point a, b;

    a.x = 1.0;
    a.y = 1.0;

    b.x = 5.0;
    b.y = 4.0;

    cout << distance(a, b) << endl;

    float r = 0.0;
    float theta = 0.0;

    polar(1.0, 1.0, r, theta);

    cout << r << " " << theta << endl;

    return 0;
}