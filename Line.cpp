#include "Point.hpp"
#include "Line.hpp"
#include <cmath>

Line::Line(const Point& pa, const Point& pb) : p1(pa), p2(pb) {
  this->p1 = pa;
  this->p2 = pb;
}

double Line::length() {
    return this->p1.distance_to_point(this->p2);
}

double Line::distance_to_point(Point p){
  double dy = this->p2.y() - this->p1.y();
  double dx = this->p2.x() - this->p1.x();
  double c = dy * this->p1.x() + dx * this->p1.y();

  double distance = abs(dy * p.x() + dx * p.y() - c) / sqrt(dy * dy + dx * dx);
  return distance;
}