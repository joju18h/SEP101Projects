#include "Starship.h"

/*
class Starship{
    private:
        Propulsion propulsion;
        Payload payload;
        WeaponSystem weaponsystem;
        double speed;
        double distance;

    public:
        Starship(int, double, int, int, int);
        bool ChangeSpeed(double);
        void Travel(double, double);
        bool FireTorpedos(int);
        bool FireLaser(int);
        void GenerateReport() const;
};
*/

Starship::Starship(int _fuelLevel, double _lightLevel, int _passengerMass, int _cargoMass, int _workstationMass, int _numTorpedos, int _numLaser){
    speed = 0.00;
    distance = 0.00;
    Propulsion();
    Payload();
    WeaponSystem();
    Propulsion(_fuelLevel, _lightLevel);
    Payload(_passengerMass, _cargoMass, _workstationMass);
    WeaponSystem(_numTorpedos, _numLaser);
}

bool Starship::ChangeSpeed(double velocity){
    bool retval = false;
    double totalMass = payload.getMass();
    double energyRequired = 0.5 * totalMass * velocity * velocity;
    retval = propulsion.consumeFuel(energyRequired);
    if(retval == true){
        speed += velocity;
    }

    return retval;
}

void Starship::Travel(double time, double _lightLevel){
    distance = speed * time;
    propulsion.setLightLevel(_lightLevel);
    propulsion.generateFuel(time);
    propulsion.addFuel();
}

bool Starship::FireTorpedo(int _numTorpedos){
    return weaponsystem.FireTorpedo(_numTorpedos);
}

bool Starship::FireLaser(int time){
    bool retval = false;
    double energyRequired = weaponsystem.FireLaser(time);
    retval = propulsion.consumeFuel(energyRequired);

    return retval;
}

void Starship::GenerateReport() const{
    std::cout.precision(2);
    std::cout << std::fixed << "The star ship is travelling at " << speed << "m/s and has travelled" << distance << "km." << std::endl;
    propulsion.GenerateReport();
    payload.GenerateReport();
    weaponsystem.PrintReport();
}
