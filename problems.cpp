#include "problems.hpp"
void AUV::step(POS pos) {
    position.x += speed[0];
    position.y += speed[1];
    depth += speed[2];
}

void AUV::accelerate(const POS dt, const NPOS& npos) {
    speed[0] += dt * npos[0];
    speed[1] += dt * npos[1];
    speed[2] += dt * npos[2];
}

void AUV::accelerateByAngle(const double angular_acceleration, POS pos) {
    angular_speed += angular_acceleration * pos;
}