#include "point.h"

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter two values for reference point: " << endl;

    double x;
    double y;
    cin >> x >> y;
    
    Point referencePoint(x, y);

    double distance = 0.0;
    Point nearestPoint;

    cout << "Enter another points to find nearest to the first point:" << endl;

    while (cin >> x >> y) {
        Point tempPoint(x, y);

        if (distance == 0.0) {
            distance = referencePoint.distanceTo(tempPoint);
            nearestPoint = tempPoint;
        } else {
            double tempDistance = referencePoint.distanceTo(tempPoint);
            if (tempDistance < distance) {
                distance = tempDistance;
                nearestPoint = tempPoint;
            }
        }
    }
    cout << "Nearest point: x = " << nearestPoint.x() 
         << ", y = " << nearestPoint.y() << endl;

    return 0;
}