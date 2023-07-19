#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <array>
#include "Point.hpp"

class AUV {
public:
    std::string name;
    Point position;
    double depth;
    double heading;
    std::array<double, 3> speed;
    double angular_speed;

    AUV(
        std::string name, 
        Point position, 
        double depth,
        double heading,
        std::array<double, 3> speed,
        double angular_speed
    );

    void step(double dt);

    void apply_acceleration(const std::array<double, 3> acceleration, double dt);
    
    void apply_angular_acceleration(double angular_acceleration, double dt);
};