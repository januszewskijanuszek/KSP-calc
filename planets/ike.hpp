#pragma once
#include "../celestial.hpp"

class Ike : public Celestial{
public:
    Ike(){
        GRAVITATIONAL_PARAMETER = 1.8568369 * pow(10, 10);
        RADIUS = 130000;
        MASS = 2.7821615 * pow(10, 20);
        SOI = 1049598.9 ;
    }
    std::string getName() const override {return "Ike";}
};