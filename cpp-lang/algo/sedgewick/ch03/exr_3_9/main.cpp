#include "triangle.h"
#include "shapegenerator.h"

#include <iostream>
using namespace std;

int main()
{
    int triangleCount = 0;
    double areas = 0.0;
    char choice;

    do
    {
        cout << "\nThe new triangle is:" << endl;
        // output the triangle's coordinates
        Triangle triangle = ShapeGenerator::generateTriangle();
        cout << triangle << endl;
        // output the triangle's area
        double area = triangle.area();
        cout << "Area = " << area << endl;
        // output the triangles average area
        areas += area;
        cout << "Average area = " << (areas / static_cast<double>(++triangleCount)) << endl << endl;;

        // ask to continue
        do
        {
            cout << "Do you want to continue? (y/n) ";
            cin >> choice;
        } while ((choice != 'y') && (choice != 'n'));
    } while (choice != 'n');

    return 0;
}