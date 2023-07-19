#include "Point.hpp"
#include "Line.hpp"
#include "Triangle.hpp"
#include <cmath>

Triangle::Triangle(const Point& pa, const Point& pb, const Point& pc) : p1(pa), p2(pb), p3(pc) {
  this->p1 = pa;
  this->p2 = pb;
  this->p3 = pc;
}

double Triangle::area() {
    return Line(p2, p3).distance_to_point(p1) * Line(p2, p3).length() / 2;
}