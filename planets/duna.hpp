#pragma once
#include "../celestial.hpp"
#include "ike.hpp"

class Duna : public Celestial{
public:
    Duna(){
        GRAVITATIONAL_PARAMETER = 3.0136321 * pow(10, 11);
        RADIUS = 320000;
        MASS = 4.5154270 * pow(10, 21);
        SOI = 47921949;
        moons = {new Ike()};
    }
    std::string getName() const override {return "Duna";}
};