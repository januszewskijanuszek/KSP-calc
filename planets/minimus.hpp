#pragma once
#include "../celestial.hpp"

class Minimus : public Celestial {
public:
    Minimus(){
        GRAVITATIONAL_PARAMETER = 1.7658000 * pow(10, 9);
        RADIUS = 60000;
        MASS = 2.6457580 * pow(10, 19);
        SOI = 2247735.4;
    }
    std::string getName() const override {return "Minimus";}
};