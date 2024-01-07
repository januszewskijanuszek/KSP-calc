#include "celestal.hpp"

class Kerbin : public Celestal{
public:
    double GRAVITATIONAL_PARAMETER = 3.5303940 * pow(10, 12);
    double RADIUS = 600000;
    double MASS = 5.2897088 * pow(10, 22);
    double SOI = 84147790;

    double getGravitationalParameter() const override {return GRAVITATIONAL_PARAMETER;}
    double getSoi() const override {return SOI;}
    double getMass() const override {return MASS;}
    double getRadius() const override {return RADIUS;}
    std::string getName() const override {return "Kerbin";}
};