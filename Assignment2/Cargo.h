#ifndef _CARGO_H_
#define _CARGO_H_

#include <iostream>
#include "Propulsion.h"
#include "Payload.h"

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

#endif //_CARGO_H_