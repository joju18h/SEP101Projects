// Capacitor.cpp Function defintions for class Capacitor
//George Paul Robert, 117928226
#include "Capacitor.h"

/*
class Capacitor{
    private:
        double capacitance;
        double current;
        double voltage;

    public:
    Capacitor(double);
    double getCurrent(double, double);
};
*/

//constructor
Capacitor::Capacitor(double _capacitance){
    capacitance = _capacitance;
    current = 0.00;
    voltage = 0.00;
}

//returns current, getter function
double Capacitor::GetCurrent(double newVoltage, double timestep){
    current = capacitance * (newVoltage - voltage) / timestep;
    voltage = newVoltage;
    return current;
}

