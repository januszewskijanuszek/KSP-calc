#pragma once
#include "../celestial.hpp"

class Eeloo : public Celestial{
public:
    Eeloo(){
        GRAVITATIONAL_PARAMETER = 7.4410815 * pow(10, 10);
        RADIUS = 210000;
        MASS = 1.1149224 * pow(10, 21);
        SOI = 119082940;
    }
    std::string getName() const override {return "Eeloo";}
};