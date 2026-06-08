#ifndef VAN_H
#define VAN_H

#include "Vehicle.h"

class Van : public Vehicle {
private:
    bool slidingDoor;

public:
    Van();
    Van(int id, string plate, int cap, bool sd);

    void displayVehicle() override;
    void save(ofstream& out) override;
    void load(ifstream& in) override;
};

#endif
