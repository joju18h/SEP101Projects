#ifndef STARSHIP_H_
#define STARSHIP_H_

#include "Propulsion.h"
#include "Payload.h"
#include "TheWeaponSystem.h"

class Starship{
    private:
        Propulsion propulsion;
        Payload payload;
        WeaponSystem weaponsystem;
        double speed;
        double distance;

    public:
        Starship(int, double, int, int, int, int, int);
        bool ChangeSpeed(double);
        void Travel(double, double);
        bool FireTorpedo(int);
        bool FireLaser(int);
        void GenerateReport() const;
};

#endif //STARSHIP_H_