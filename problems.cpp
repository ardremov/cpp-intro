#include "problems.hpp"

double Circle::area() {
    return M_PI * radius * radius;
}

double Point::distance_to_origin() {
    return sqrt(x * x + y * y);
}

double Point::distance_to_point(Point p) {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

double Point::distance_to_line(Line l) {
    Point p;
    p.x = x;
    p.y = y;
    return l.distance_to_point(p);
}

double Line::length() {
    Point p;
    p.x = p1.x;
    p.y = p1.y;
    return p.distance_to_point(p2);
}

double Line::slope() {
    return (p1.y - p2.y) / (p1.x - p2.x);
}

double Line::distance_to_point(Point p) {
    double dy = p2.y - p1.y;
    double dx = p2.x - p1.x;
    double c = dy * p1.x + dx * p1.y;

    double distance = abs(dy * p.x + dx * p.y - c) / sqrt(dy * dy + dx * dx);
    return distance;
}

double Triangle::area() {
    Line l;
    l.p1 = p1;
    l.p2 = p2;
    return l.distance_to_point(p3) * l.length() / 2;
}

double Polygon::area() {
    // polygon MUST BE convex for this function to work.
    double a = 0;
    for (int i = 1; i < points.size() - 1; i++) {
        Triangle t;
        t.p1 = points[0];
        t.p2 = points[i];
        t.p3 = points[i + 1];
        a += t.area();
    }
    return a;
}

double Polygon::perimeter() {
    double p = 0;
    for (int i = 1; i < points.size(); i++) {
        Line l; 
        l.p1 = points[i];
        l.p2 = points[i - 1];
        p += l.length();
    }
    return p;
}

void AUV::step(double dt) {

}

void AUV::apply_acceleration(std::array<double, 3>) {

}

void AUV::apply_angular_acceleration(double angular_acceleration) {

}