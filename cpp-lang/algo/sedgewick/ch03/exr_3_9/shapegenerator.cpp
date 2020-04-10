#include "shapegenerator.h"

#include <cstdlib>

Triangle ShapeGenerator::generateTriangle(double minCoord, double maxCoord)
{
    Point x = generatePoint(minCoord, maxCoord);
    Point y = generatePoint(minCoord, maxCoord);
    Point z = generatePoint(minCoord, maxCoord);
    return Triangle(x, y, z);
}

Point ShapeGenerator::generatePoint(double minCoord, double maxCoord)
{
    double x = generateCoordinate(minCoord, maxCoord);
    double y = generateCoordinate(minCoord, maxCoord);
    return Point(x, y);
}

double ShapeGenerator::generateCoordinate(double min, double max)
{
    double d = (static_cast<double>(rand()) / (RAND_MAX));
    return min + d * (max - min);
}

ShapeGenerator::ShapeGenerator()
{
}

ShapeGenerator::ShapeGenerator(const ShapeGenerator &other)
{
}

ShapeGenerator &ShapeGenerator::operator=(const ShapeGenerator &other)
{
    return *this;
}

ShapeGenerator *ShapeGenerator::instance()
{
    static ShapeGenerator g;
    return &g;
}