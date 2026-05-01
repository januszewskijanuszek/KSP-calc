#pragma once
#include "../celestial.hpp"

class Moho : public Celestial{
public:
    Moho(){
        GRAVITATIONAL_PARAMETER = 1.6860938 * pow(10, 11);
        RADIUS = 250000;
        MASS = 2.5263314 * pow(10, 21);
        SOI = 9646663;
    }
    std::string getName() const override {return "Moho";}
};