#include "point.h"

#include <iostream>
using namespace std;

int main()
{
    double x;
    double y;

    cin >> x >> y;
    Point p1(x, y);

    cin >> x >> y;
    Point p2(x, y);

    cin >> x >> y;
    Point p3(x, y);

    cout << p1.isSameLine(p2, p3) << endl;

    return 0;
}