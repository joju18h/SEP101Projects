#include <iostream>
#include "Cargo.h"

/*
class Cargo{
    private:
        Propulsion propulsion;
        Payload payload1;
        Payload payload2;
        double speed;
        double distance;

    public:
        Cargo(int, double, int, int, int);
        bool ChangeSpeed(double);
        void Travel(double, double);
        void GenerateReport() const;
};
*/

Cargo::Cargo(int _fuelLevel, double _lightLevel, int _passengerMass, int _cargoMass, int _workstationMass){
    speed = 0.00;
    distance = 0.00;
    Propulsion();
    Payload();
    Propulsion(_fuelLevel, _lightLevel);
    payload1 = Payload(_passengerMass, _cargoMass, _workstationMass);
    payload2 = Payload(_passengerMass, _cargoMass, _workstationMass);
}

bool Cargo::ChangeSpeed(double velocity){
    bool retval = false;
    double totalMass = payload1.getMass() + payload2.getMass();
    double energyRequired = 0.5 * totalMass * velocity * velocity;
    retval = propulsion.consumeFuel(energyRequired);
    if(retval == true){
        speed += velocity;
    }

    return retval;
}

void Cargo::Travel(double time, double _lightLevel){
    distance = speed * time;
    propulsion.setLightLevel(_lightLevel);
    propulsion.generateFuel(time);
    propulsion.addFuel();
}

void Cargo::GenerateReport() const{
    std::cout.precision(2);
    std::cout << std::fixed << "The cargo ship is travelling at " << speed << "m/s and has travelled" << distance << "km." << std::endl;
    propulsion.GenerateReport();
    payload1.GenerateReport();
    payload2.GenerateReport();
}
