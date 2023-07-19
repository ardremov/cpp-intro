#include <cmath>
#include <vector>
#include <string>
#include <array>

template<class T>
T sqr(T x) {
  return x * x;
}

template<class T>
struct Point
{
    T x,y;
};

template<class T>
struct Line
{
    Point<T> p1, p2;

    Point<T> diff() const {
      return Point{p1.x - p2.x, p1.y - p2.y};
    }

    T length() const {
      auto d = diff();
      return std::sqrt(sqr(d.x) + sqr(d.y));
    }

    T slope() const {
      auto d = diff();
      // TODO: this will throw division by zero for vertical line
      // assert(d.x != 0);
      return d.y / d.x;
    }
};

namespace distance {
  template<class T>
  T pointToPoint(const Point<T>& p1, const Point<T>& p2) {
    return Line{p1, p2}.length();
  }

  template <class T>
    T pointToOrigin(const Point<T>& pt) {
      return pointToPoint(pt, Point<T>{});
    }

    template<class T>
    T pointToLine(const Point<T>& pt, const Line<T>& line) {
      auto d = line.diff();
      if (!d.x && !d.y)
        return 0;
      auto c = d.y * pt.x + d.x * pt.y;
      return std::abs(d.y * pt.x + d.x * pt.y - c) / sqrt(sqr(d.x) + sqr(d.x));
    }
} // namespace distance

template<class T>
class Circle
{
  T radius;

public:
  Circle(T r) : radius(r) {}
  
  T area() const {
    return M_PI * sqr(radius);
  }

  T perimeter() const {
    return 2 * M_PI * radius;
  }
};

template<class T>
class Triangle
{
    Point<T> pt[3];

public:
    T area() const {
      Line l{pt[0], pt[1]};
      return distance::pointToLine(pt[2], l) * l.length() / 2;
    }

    T perimeter() const {
      return
         Line{pt[0], pt[1]}.length() +
         Line{pt[1], pt[2]}.length() +
         Line{pt[2], pt[0]}.length();
    }
};

template<class T>
class Polygon
{
  public:
    std::vector<Point<T>> points;

    T area() const {
      // TODO: polygon MUST BE convex for this function to work.
      T a{};
      for (int i = 1; i < points.size() - 1; i++) {
          Triangle t{points[0], points[i], points[i+1]}; // crash here!
          a += t.area();
      }
      return a;
    }

    T perimeter() const {
      auto p = Line{points[0], points[points.size()-1]}.length();
      for (size_t i = 1; i < points.size(); i++) {
          p += Line{points[i-1], points[i]}.length();
      }
      return p;      
    }
};
// Autonomous Underwater Vehicle
class AUV
{
public:
  using POS = double;

  // 0 = forward speed, 1 = lateral speed, 2 = vertical speed
  enum Speed{
    SpeedForward,
    SpeedLateral,
    SpeedVertical,
    SpeedTotal
  };
  using NPOS = std::array<POS, SpeedTotal>;

    void step(POS);
    void accelerate(const double acceleration, const NPOS&); // braindead code…
    void accelerateByAngle(const double angular_acceleration, POS);

  private:
    std::string name;
    Point<POS> position;
    POS depth;
    POS heading;
    NPOS speed;
    POS angular_speed;
};