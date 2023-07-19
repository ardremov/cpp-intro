#pragma once
#include "Point.hpp"

// template <class T> // double
class Line {
private:
    Point p1;
    Point p2;

public:
    Line(const Point&, const Point&);

    double length();
    double distance_to_point(Point);
};