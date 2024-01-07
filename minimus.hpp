#include "celestal.hpp"

class Minimus : public Celestal {
public:
    double GRAVITATIONAL_PARAMETER = 1.7658000 * pow(10, 9);
    double RADIUS = 60000;
    double MASS = 2.6457580 * pow(10, 19);
    double SOI = 2247735.4;

    double getGravitationalParameter() const override {return GRAVITATIONAL_PARAMETER;}
    double getSoi() const override {return SOI;}
    double getMass() const override {return MASS;}
    double getRadius() const override {return RADIUS;}
    std::string getName() const override {return "Minimus";}
};