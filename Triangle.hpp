#pragma once
#include "Point.hpp"
#include "Line.hpp"

// template <class T> // double
class Triangle {
private:
    Point p1;
    Point p2;
    Point p3;

public:
    Triangle(const Point&, const Point&, const Point&);

    double area();
};