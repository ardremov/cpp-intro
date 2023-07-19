#pragma once
#include "Point.hpp"
#include "Line.hpp"
#include "Triangle.hpp"
#include <vector>

// template <class T> // double
class Polygon {
private:
    std::vector<Point> vertices;

public:
    Polygon(std::vector<Point>);

    double area();
    double perimeter();
};