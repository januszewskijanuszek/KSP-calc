#include "../celestal.hpp"

class Minimus : public Celestal {
public:
    const double GRAVITATIONAL_PARAMETER = 1.7658000 * pow(10, 9);
    const double RADIUS = 60000;
    const double MASS = 2.6457580 * pow(10, 19);
    const double SOI = 2247735.4;

    double getGravitationalParameter() const override {return GRAVITATIONAL_PARAMETER;}
    double getSoi() const override {return SOI;}
    double getMass() const override {return MASS;}
    double getRadius() const override {return RADIUS;}
    std::string getName() const override {return "Minimus";}
};