#include "celestial.hpp"
#include <cmath>
#include <iostream>

bool Celestial::validateAltitude(const double &height) const {
    if(height > getSoi()) return false;
    if(height <= getRadius()) return false;
    return true;
}

double Celestial::getAltitudeByTime(const uint16_t &time) const {
    const double upper = time * sqrt(getGravitationalParameter());
    const double down = 2 * M_PI;
    const double raw_data = pow(upper / down, 2.0 / 3.0);
    const double npm = raw_data - getRadius();
    return validateAltitude(npm) ? npm : 0.0;
}

double Celestial::getPeriapsis(const uint16_t &time, double apoapsis) const {
    // r1 + r2 / 2 = a
    const double a = getAltitudeByTime(time) + getRadius();
    const double r2 = a * 2 - (apoapsis + getRadius());
    return validateAltitude(r2) ? r2 - getRadius(): 0.0;
}

double Celestial::getTimeByAltitude(const double &altitude) const{
    const double left = M_PI * 2;
    const double right = sqrt(pow(altitude + getRadius(), 3) / getGravitationalParameter());
    return left * right;
}

double Celestial::getPeriapsisForSynchronousSattelites(double apoapsis, int comm_count) const{
    double time_of_circular_orbit = getTimeByAltitude(apoapsis);
    double trajectory_min = time_of_circular_orbit / comm_count;
    double trajectory_optimal = trajectory_min * (comm_count - 1);
    return getPeriapsis(trajectory_optimal, apoapsis);
}