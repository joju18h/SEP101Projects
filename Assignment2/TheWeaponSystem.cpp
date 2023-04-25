// Function Defintions for the class Weapon System
// Written by Amir Abdalla

#include <iostream>
#include "TheWeaponSystem.h"

WeaponSystem::WeaponSystem()
{
    num_Torpedoes = 0;
    num_LaserCannons = 0;
}

WeaponSystem::WeaponSystem(int _num_Torpedoes, int _num_LaserCannons)
{
    num_Torpedoes = _num_Torpedoes;
    num_LaserCannons = _num_LaserCannons;
}

bool WeaponSystem::FireTorpedo(int _num_Torpedoes)
{
    if (num_Torpedoes >= _num_Torpedoes)
    {
        num_Torpedoes -= _num_Torpedoes;
        return true;
    }

    else
    {
        return false;
    }
    return false;
}

double WeaponSystem::FireLaser(int time_duration)
{

    return ENERGY_PER_SECOND * time_duration * num_LaserCannons;
}

void WeaponSystem::AddTorpedoes(int _num_Torpedoes)
{
    num_Torpedoes += _num_Torpedoes;
    if (num_Torpedoes > TORPEDOE_CAPACITY)
    {
        num_Torpedoes = TORPEDOE_CAPACITY;
    }
}

void WeaponSystem::AddLaserCannons(int _num_LaserCannons)
{
    num_LaserCannons += _num_LaserCannons;

    if (num_LaserCannons > MAX_LASERCANNONS)
    {
        num_LaserCannons = MAX_LASERCANNONS;
    }
}

void WeaponSystem::PrintReport() const
{
    std::cout << "Number of Torpedoes: " << num_Torpedoes;
    std::cout << "Number of Laser Cannons: " << num_LaserCannons << std::endl;
}
