// Program calculate orbital lenght for KSP
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include "celestial.hpp"

#include "planets/kerbin.hpp"
#include "planets/duna.hpp"
#include "planets/moho.hpp"
#include "planets/eve.hpp"
#include "planets/eeloo.hpp"
#include "planets/dres.hpp"

#define MAIN 1

using namespace std;

void printMenu(const uint16_t &id, const string &content){
    cout << id << " - " << content << "\n";
}

template<typename T>
T getValueFromConsole(string comment){
    T return_value;
    cout << comment;
    cin >> return_value;
    return return_value;
}


int main(){
    #ifdef MAIN
    vector<Celestial*> planets = {
        new Moho(),
        new Eve(),
        new Gilly(),
        new Kerbin(), 
        new Moon(), 
        new Minimus(),
        new Duna(),
        new Ike(),
        new Dres(),
        new Eeloo()
    };

    system("cls");
    cout << "Chose planet:\n";
    uint16_t picked_number;
    for(int i = 1 ; i <= planets.size() ;){
        Celestial* element = planets[i - 1];
        printMenu(i++, element -> getName());
        if(element->getMoons().size() != 0){
            for(Celestial* moon : element->getMoons()){
                cout << "  " << i++ << " " << moon -> getName() << endl;
            }
        }
    }

    cin >> picked_number;
    Celestial* chosen_planet = planets.at(picked_number - 1);
    system("cls");
    uint16_t mode_chose;
    try {
        cout << "Chosen planet: " + chosen_planet -> getName() + "\n";
    } catch(const out_of_range &e){
        cout << "Invalid number\n";
        exit(1);
    }
    
    printMenu(1, "Get apoapsis by providing a time (perfect circular orbit)");
    printMenu(2, "Get time by providing a apoapsis (perfect circular orbit)");
    printMenu(3, "Get periapsis by providing fixed time and apoapsis");
    printMenu(4, "Get periapsis for comm network, prividing amount of satellites and apoapsis");
    cin >> mode_chose;

    switch(mode_chose){
        case 1: {
            uint16_t time = getValueFromConsole<uint16_t>("Provide time(s): ");
            cout << fixed << chosen_planet->getAltitudeByTime(time) << "m" << setprecision(6) << endl;
            break;
        }
        case 2:{
            double apoapsis = getValueFromConsole<double>("Provide apoapsis(m): ");
            cout << fixed << chosen_planet->getTimeByAltitude(apoapsis) << "s" << setprecision(6) << endl;
            break;
        }
        case 3:{
            double apoapsis = getValueFromConsole<double>("Provide apoapsis(m): ");
            uint16_t time = getValueFromConsole<uint16_t>("Provide time(s): ");
            cout << fixed << chosen_planet->getPeriapsis(time, apoapsis) << "m" << setprecision(6) << endl;
            break;
        }
        case 4:{
            double apoapsis = getValueFromConsole<double>("Provide apoapsis(m): ");
            int amount_of_satellites = getValueFromConsole<int>("Provide number of satellites (min 3): ");
            cout << fixed << chosen_planet->getPeriapsisForSynchronousSattelites(apoapsis, amount_of_satellites) << "m" << setprecision(6) << endl;
            break;
        }
        default: exit(1);
    }
    #endif // MAIN
    return 0;
}