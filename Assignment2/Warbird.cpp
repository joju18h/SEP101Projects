#include "Warbird.h"
/*
class Warbird
{
    Propulsion propulsion1;
    Propulsion propulsion2;
    Payload payload;
    WeaponSystem weaponsystem1;
    WeaponSystem weaponsystem2;
    double speed;
    double distance;

public:
    Warbird(int, double, int, int, int, int, int);
    bool ChangeSpeed(double velocity );
    void Travel(double, double);
    bool FireTorpedoes(int);
    bool FireLaser(int);
    void GenerateReport()const;


};
*/

Warbird::Warbird(int _fuelLevel, double _lightLevel, int _passengerMass, int _cargoMass, int _workstationMass, int _numTorpedoes, int _numLaser)

{
    Propulsion();
    Payload();
    WeaponSystem();

    propulsion1 = Propulsion(_fuelLevel, _lightLevel);
    propulsion2 = Propulsion(_fuelLevel, _lightLevel);
    Payload(_passengerMass, _cargoMass, _workstationMass);
    weaponsystem1 = WeaponSystem(_numTorpedoes, _numLaser);
    weaponsystem2 = WeaponSystem(_numTorpedoes, _numLaser);

    speed = 0.00;
    distance = 0.00;
}

bool Warbird::ChangeSpeed(double velocity)
{
    bool retval = false;
    double totalMass = payload.getMass();
    double energyRequired = 0.5 * totalMass * velocity * velocity;
    retval = propulsion1.consumeFuel(energyRequired);
    retval = propulsion2.consumeFuel(energyRequired);
    if (retval == true)
    {
        speed += velocity;
    }

    return retval;
}

void Warbird::Travel(double time, double _lightLevel)
{
    distance = speed * time;
    propulsion1.setLightLevel(_lightLevel);
    propulsion1.generateFuel(time);
    propulsion1.addFuel();
    propulsion2.setLightLevel(_lightLevel);
    propulsion2.generateFuel(time);
    propulsion2.addFuel();
}

bool Warbird::FireTorpedo(int _numTorpedoes)
{
    return weaponsystem1.FireTorpedo(_numTorpedoes);
    return weaponsystem2.FireTorpedo(_numTorpedoes);
}

bool Warbird::FireLaser(int time)
{
    bool retval = false;
    double energyRequired = weaponsystem1.FireLaser(time);
    energyRequired = weaponsystem2.FireLaser(time);
    retval = propulsion1.consumeFuel(energyRequired);
    retval = propulsion2.consumeFuel(energyRequired);

    return retval;
}

void Warbird::GenerateReport() const
{
    std::cout.precision(2);
    std::cout << std::fixed << "The warbird is travelling at " << speed << "m/s and has travelled" << distance << "km." << std::endl;
    propulsion1.GenerateReport();
    propulsion2.GenerateReport();
    payload.GenerateReport();
    weaponsystem1.PrintReport();
    weaponsystem2.PrintReport();
}
