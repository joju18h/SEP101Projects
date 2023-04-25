//Inductor.h - class declaration for the inductor

#ifndef INDUCTOR_H_
#define INDUCTOR_H_

class Inductor {
	double inductance;
	double current;
public:
	Inductor(double _inductance);
	double GetCurrent(double voltage, double timeStep);
};


#endif// _INDUCTOR_H_