#include "Point.hpp"
#include "Line.hpp"
#include "Triangle.hpp"
#include "Polygon.hpp"
#include <cmath>

Polygon::Polygon(std::vector<Point> verts) : vertices(verts) {
  this->vertices = verts;
}

double Polygon::area() {
    // TODO: polygon MUST BE convex for this function to work.
    double a{};
    for (int i = 1; i < this->vertices.size() - 1; i++) {
        Triangle t{this->vertices[0], this->vertices[i], this->vertices[i+1]}; // crash here?
        a += t.area();
    }
    return a;
}

double Polygon::perimeter() {
    auto p = Line{this->vertices[0], this->vertices[this->vertices.size()-1]}.length();
    for (size_t i = 1; i < this->vertices.size(); i++) {
        p += Line{this->vertices[i-1], this->vertices[i]}.length();
    }
    return p;     
}