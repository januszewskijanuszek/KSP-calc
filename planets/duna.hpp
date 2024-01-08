#include "../celestal.hpp"

class Duna : public Celestal{
public:
    const double GRAVITATIONAL_PARAMETER = 3.0136321 * pow(10, 11);
    const double RADIUS = 320000;
    const double MASS = 4.5154270 * pow(10, 21);
    const double SOI = 47921949;

    double getGravitationalParameter() const override {return GRAVITATIONAL_PARAMETER;}
    double getSoi() const override {return SOI;}
    double getMass() const override {return MASS;}
    double getRadius() const override {return RADIUS;}
    std::string getName() const override {return "Duna";}
};