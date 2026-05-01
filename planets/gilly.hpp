#pragma once
#include "../celestial.hpp"

class Gilly : public Celestial{
public:
    Gilly(){
        GRAVITATIONAL_PARAMETER = 8289449;
        RADIUS = 13000;
        MASS = 1.2420363 * pow(10, 17);
        SOI = 126123.27;
    }
    std::string getName() const override {return "Gilly";}
};