#include <iostream>
#include <cmath>
#include <vector>
#include <array>

class Circle
{
public:
  int radius;

  double area();
};

class Point
{
  public:
    double x;
    double y;
    double distance_to_origin();
    double distance_to_point(Point);
    double distance_to_line(Line);
};

class Line
{
  public:
    Point p1;
    Point p2;
    double length();
    double slope();
    double distance_to_point(Point);
};

class Triangle
{
  public:
    Point p1;
    Point p2;
    Point p3;
    double area();
};

class Polygon
{
  public:
    std::vector<Point> points;
    double area();
    double perimeter();
};

class AUV
{
  public:
    std::string name;
    Point position;
    double depth;
    double heading;
    std::array<double, 3> speed; // speed[0] = forward speed, speed[1] = lateral speed, speed[2] = vertical speed.
    double angular_speed;
    void step(double dt);
    void apply_acceleration(std::array<double, 3>);
    void apply_angular_acceleration(double angular_acceleration);
};