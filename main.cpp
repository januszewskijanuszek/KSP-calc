// Program calculate orbital lenght for KSP
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include "celestal.hpp"

#include "planets/moon.hpp"
#include "planets/minimus.hpp"
#include "planets/kerbin.hpp"
#include "planets/duna.hpp"

using namespace std;

void printMenu(const uint16_t &id, const string &content){
    cout << id << " - " << content << "\n";
}

int main(){
    vector<Celestal*> planets = {
        new Kerbin(), 
        new Moon(), 
        new Minimus(),
        new Duna()
    };
    system("cls");
    cout << "Chose planet:\n";
    uint16_t i = 1;
    uint16_t planet_chose;
    for(Celestal * element : planets){
        printMenu(i++, element -> getName());
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
    
    printMenu(1, "Get apoapsis by providing a time");
    printMenu(2, "Get time by providing a apoapsis");
    printMenu(3, "Get periapsis by providing fixed time and apoapsis");
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
        default: exit(1);
    }
    return 0;
}