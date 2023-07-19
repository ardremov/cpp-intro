#include "problems.hpp"
#include "AUV.hpp"

AUV::AUV(
    std::string name,
    Point position,
    double depth,
    double heading,
    std::array<double, 3> speed,
    double angular_speed
) {
    this->name = name;
    this->position = position;
    this->depth = depth;
    this->heading = heading;
    this->speed = speed;
    this->angular_speed = angular_speed;
}

void AUV::step(double dt) {
    position.set_x(dt * speed[0]);
    position.set_y(dt * speed[1]);
    depth += dt * speed[2];
    heading += dt * angular_speed;
}

void AUV::apply_acceleration(const std::array<double, 3> acceleration, double dt) {
    speed[0] += dt * acceleration[0];
    speed[1] += dt * acceleration[1];
    speed[2] += dt * acceleration[2];
}

void AUV::apply_angular_acceleration(double angular_acceleration, double dt) {
    angular_speed += angular_acceleration * dt;
}