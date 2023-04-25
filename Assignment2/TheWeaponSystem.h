// TheWeaponSystem.h - class decleration for Weapon system
// Written by Amir Abdalla

#ifndef _THEWEAPONSYSTEM_H_
#define _THEWEAPONSYSTEM_H_

#include <iostream>

int const TORPEDOE_CAPACITY = 110;
int const MAX_LASERCANNONS = 10;
double const ENERGY_PER_SECOND = 1000000000000.0;
class WeaponSystem

{
    int num_Torpedoes;
    int num_LaserCannons;

public:
    WeaponSystem();
    WeaponSystem(int, int);
    bool FireTorpedo(int);
    double FireLaser(int time_duration);
    void AddTorpedoes(int);
    void AddLaserCannons(int);
    void PrintReport()const;
};

#endif // _THEWEAPONSYSTEM_H_
