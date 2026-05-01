#pragma once
#include "../celestial.hpp"

class Dres : public Celestial{
public:
    Dres(){
        GRAVITATIONAL_PARAMETER = 2.1484489 * pow(10, 10);
        RADIUS = 138000;
        MASS = 3.2190937 * pow(10, 20);
        SOI = 32832840;
    }
    std::string getName() const override {return "Dres";}
};