#ifndef _WARBIRD_H_
#define _WARBIRD_H_

#include "TheWeaponSystem.h"
#include "Propulsion.h"
#include "Payload.h"

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
    bool FireTorpedo(int); 
    bool FireLaser(int);
    void GenerateReport()const;


};

#endif //_WARBIRD_H_