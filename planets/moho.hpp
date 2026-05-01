#include "../celestal.hpp"

class Moho : public Celestal{
public:
    const double GRAVITATIONAL_PARAMETER = 1.6860938 * pow(10, 11);
    const double RADIUS = 250000;
    const double MASS = 2.5263314 * pow(10, 21);
    const double SOI = 9646663;

    double getGravitationalParameter() const override {return GRAVITATIONAL_PARAMETER;}
    double getSoi() const override {return SOI;}
    double getMass() const override {return MASS;}
    double getRadius() const override {return RADIUS;}
    std::string getName() const override {return "Moon";}
};