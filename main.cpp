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
    uint16_t planet_chose;
    for(int i = 1 ; i <= planets.size() ;){
        Celestial* element = planets[i - 1];
        printMenu(i++, element -> getName());
        if(element->getMoons().size() != 0){
            for(Celestial* moon : element->getMoons()){
                cout << "  " << i++ << " " << moon -> getName() << endl;
            }
        }
    }

    cin >> planet_chose;
    system("cls");
    uint16_t mode_chose;
    try {
        cout << "Chosen planet: " + planets.at(planet_chose - 1) -> getName() + "\n";
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
            uint16_t time;
            cout << "Provide time(s): ";
            cin >> time;
            cout << fixed << planets.at(planet_chose - 1)->getAltitudeByTime(time) << "m" << setprecision(6) << endl;
            break;
        }
        case 2:{
            double apoapsis;
            cout << "Provide apoapsis(m): ";
            cin >> apoapsis;
            cout << fixed << planets.at(planet_chose - 1)->getTimeByAltitude(apoapsis) << "s" << setprecision(6) << endl;
            break;
        }
        case 3:{
            double apoapsis;
            uint16_t time;
            cout << "Provide apoapsis(m): ";
            cin >> apoapsis;
            cout << "Provide time(s): ";
            cin >> time;
            cout << fixed << planets.at(planet_chose - 1)->getPeriapsis(time, apoapsis) << "m" << setprecision(6) << endl;
            break;
        }
        case 4:{
            double apoapsis;
            int amount_of_satellites;
            cout << "Provide apoapsis(m): ";
            cin >> apoapsis;
            cout << "Provide number of satellites (min 3): ";
            cin >> amount_of_satellites;
            cout << fixed << planets.at(planet_chose - 1)->getPeriapsisForSynchronousSattelites(apoapsis, amount_of_satellites) << "m" << setprecision(6) << endl;
            break;
        }
        default: exit(1);
    }
    #endif // MAIN
    return 0;
}