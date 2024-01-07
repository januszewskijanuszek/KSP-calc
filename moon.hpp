#include "celestal.hpp"

class Moon : public Celestal{
public:
    double GRAVITATIONAL_PARAMETER = 6.5138398 * pow(10, 10);
    double RADIUS = 200000;
    double MASS = 9.7599066 * pow(10, 20);
    double SOI = 2429891.1;

    double getGravitationalParameter() const override {return GRAVITATIONAL_PARAMETER;}
    double getSoi() const override {return SOI;}
    double getMass() const override {return MASS;}
    double getRadius() const override {return RADIUS;}
    std::string getName() const override {return "Moon";}
};