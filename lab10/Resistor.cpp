// Resistor.cpp Function defintions for class Resistor
//George Paul Robert, 117928226
#include "Resistor.h"

/*
class Resistor{
private:
    double resistance;
    double current;

public:
    Resistor(double);
    double GetCurrent(double);
};
*/

//constructor
Resistor::Resistor(double _resistance){
    resistance = _resistance;
    current = 0.0;
}

//getter function for current
double Resistor::GetCurrent(double voltage){
    current = voltage / resistance;
    return current;
}