#include "../celestal.hpp"

class Kerbin : public Celestal{
public:
    const double GRAVITATIONAL_PARAMETER = 3.5303940 * pow(10, 12);
    const double RADIUS = 600000;
    const double MASS = 5.2897088 * pow(10, 22);
    const double SOI = 84147790;

    double getGravitationalParameter() const override {return GRAVITATIONAL_PARAMETER;}
    double getSoi() const override {return SOI;}
    double getMass() const override {return MASS;}
    double getRadius() const override {return RADIUS;}
    std::string getName() const override {return "Kerbin";}
};