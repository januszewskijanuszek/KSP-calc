#pragma once
#include "../celestial.hpp"
#include "gilly.hpp"

class Eve : public Celestial{
public:
    Eve(){
        GRAVITATIONAL_PARAMETER = 8.1717302 * pow(10, 12);
        RADIUS = 700000;
        MASS = 1.2243980 * pow(10, 23);
        SOI = 85109365;
        moons = {new Gilly()};
    }
    std::string getName() const override {return "Eve";}
};