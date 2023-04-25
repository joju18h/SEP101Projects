#ifndef PAYLOAD_H_
#define PAYLOAD_H_

class Payload{
    private:
        double passengerMass;
        double cargoMass;
        double workstationMass;

    public:
        Payload();
        Payload(double, double, double);
        double getMass() const;
        void addPassengerMass(double);
        void addCargoMass(double);
        void addWorkstationMass(double);
        void GenerateReport() const;
};

#endif //PAYLOAD_H_