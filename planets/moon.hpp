#pragma once
#include "../celestial.hpp"

class Moon : public Celestial{
public:
    Moon(){
        GRAVITATIONAL_PARAMETER = 6.5138398 * pow(10, 10);
        RADIUS = 200000;
        MASS = 9.7599066 * pow(10, 20);
        SOI = 2429891.1;
    }
    std::string getName() const override {return "Moon";}
};