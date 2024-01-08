#include <cstdint>
#include <string>
#include <cmath>
#define M_PI 3.14159265358979323846

#ifndef CELESTAL_HPP
#define CELESTAL_HPP

class Celestal{
public:
    virtual double getGravitationalParameter() const {return 0.0;}
    virtual double getMass() const {return 0.0;}
    virtual double getRadius() const {return 0.0;}
    virtual double getSoi() const {return 0.0;}
    virtual std::string getName() const {return "Default";}

    // Check if data are correct
    bool validateData(const double &height) const;

    // Getting altitude to Time
    double getAltitudeByTime(const uint16_t &time) const;

    // Getting Periapsis by fixed time and Apoapsis
    double getPeriapsis(const uint16_t &time, double apoapsis) const;

    double getTimeByAltitude(const double &altitude) const;
};

#endif // CELESTAL_HPP