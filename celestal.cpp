#include "celestal.hpp"
#include <cmath>
#include <iostream>

bool Celestal::validateData(const double &height) const {
    if(height > getSoi()) return false;
    if(height <= 0.0) return false;
    return true;
}

double Celestal::getAltitudeByTime(const uint16_t &time) const {
    const double upper = time * sqrt(getGravitationalParameter());
    const double down = 2 * M_PI;
    const double raw_data = pow(upper / down, 2.0 / 3.0);
    const double npm = raw_data - getRadius();
    return validateData(npm) ? npm : 0.0;
}

double Celestal::getPeriapsis(const uint16_t &time, double apoapsis) const {
    // r1 + r2 / 2 = a
    const double a = getAltitudeByTime(time) + getRadius();
    const double r2 = a * 2 - (apoapsis + getRadius());
    return validateData(r2) ? r2 : 0.0;
}

double Celestal::getTimeByAltitude(const double &altitude) const{
    const double left = M_PI * 2;
    const double right = sqrt(pow(altitude + getRadius(), 3) / getGravitationalParameter());
    return left * right;
}