#include "../celestal.hpp"

class Kerbin : public Celestal{
public:
    Kerbin(){
        GRAVITATIONAL_PARAMETER = 3.5303940 * pow(10, 12);
        RADIUS = 600000;
        MASS = 5.2897088 * pow(10, 22);
        SOI = 84147790;
    }
    std::string getName() const override {return "Kerbin";}
};