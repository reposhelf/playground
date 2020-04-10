#ifndef SHAPEGENERATOR_H
#define SHAPEGENERATOR_H

#include "triangle.h"
#include "point.h"

class ShapeGenerator
{
public:
    static Triangle generateTriangle(double minCoord = 0.0, double maxCoord = 1.0);
    static Point generatePoint(double minCoord = 0.0, double maxCoord = 1.0);
    static double generateCoordinate(double min = 0.0, double max = 1.0);

private:
    ShapeGenerator();
    ShapeGenerator(const ShapeGenerator &other);
    ShapeGenerator &operator=(const ShapeGenerator &other);
    ShapeGenerator *instance();
};

#endif