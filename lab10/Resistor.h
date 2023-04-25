// Resistor.h header defintions for class Resistor
//George Paul Robert, 117928226
#ifndef RESISTOR_H_
#define RESISTOR_H_

class Resistor{
private:
    double resistance;
    double current;

public:
    Resistor(double);
    double GetCurrent(double);
};

#endif //RESISTOR_H_