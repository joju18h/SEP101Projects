// Capacitor.h header file for class Capacitor
//George Paul Robert, 117928226
#ifndef CAPACITOR_H_
#define CAPACITOR_H_

class Capacitor{
    private:
        double capacitance;
        double current;
        double voltage;

    public:
    Capacitor(double);
    double GetCurrent(double, double);
};

#endif //CAPACITOR_H