#include <iostream>
#include "Payload.h"

/*
class Payload{
    private:
        double passengerMass;
        double cargoMass;
        double workstationMass;

    public:
        Payload();
        Payload(double, double, double);
        double getMass() const;
        void addPassengerMass(double);
        void addCargoMass(double);
        void addWorkstationMass(double);
        void report() const;
};
*/

// default constructor
Payload::Payload(){
    passengerMass = 0.00;
    cargoMass = 0.00;
    workstationMass = 0.00;
}

// sets all the masses
Payload::Payload(double _passengerMass, double _cargoMass, double _workstationMass)
{
    passengerMass = _passengerMass;
    cargoMass = _cargoMass;
    workstationMass = _workstationMass;
}

//getter function
double Payload::getMass() const{
    double totalMass = passengerMass + cargoMass + workstationMass;
    return totalMass;
}

//adding new mass/passenger/workstation masses
void Payload::addCargoMass(double newMass){
    cargoMass += newMass;
}

void Payload::addPassengerMass(double newMass){
    passengerMass += newMass;
}

void Payload::addWorkstationMass(double newMass){
    workstationMass += newMass;
}


//prints the report for payload
void Payload::GenerateReport() const{
    std::cout.precision(2);
    std::cout << std::fixed << "Payload: mass of passengers:" << passengerMass << "kg, mass of cargo:" << cargoMass << "kg, mass of workstations:" << workstationMass << "kg." << std::endl;
}

