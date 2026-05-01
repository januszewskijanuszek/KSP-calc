#include <cstdint>
#include <string>
#include <cmath>
#include <vector>
#define M_PI 3.14159265358979323846

#ifndef CELESTAL_HPP
#define CELESTAL_HPP

class Celestial{
protected:
    double GRAVITATIONAL_PARAMETER = 0;
    double RADIUS = 0;
    double MASS = 0;
    double SOI = 0;
    std::vector<Celestial*> moons = {};

    // Check if data are correct
    bool validateAltitude(const double &height) const;

public:
    // Getters for constants for each planet
    inline double getGravitationalParameter() const {return GRAVITATIONAL_PARAMETER;}
    inline double getSoi() const {return SOI;}
    inline double getMass() const {return MASS;}
    inline double getRadius() const {return RADIUS;}

    std::vector<Celestial*> getMoons() {return moons;}

    virtual std::string getName() const {return "Default";}

    // Getting altitude to Time
    double getAltitudeByTime(const uint16_t &time) const;

    // Getting Periapsis by fixed time and Apoapsis
    double getPeriapsis(const uint16_t &time, double apoapsis) const;

    double getTimeByAltitude(const double &altitude) const;

    double getPeriapsisForSynchronousSattelites(double apoapsis, int comm_count) const;
};

#endif // CELESTAL_HPP