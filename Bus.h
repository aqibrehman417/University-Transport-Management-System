#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

class Bus : public Vehicle {
private:
    bool AC;

public:
    Bus();
    Bus(int id, string plate, int cap, bool ac);

    void displayVehicle() override;
    void save(ofstream& out) override;
    void load(ifstream& in) override;
};

#endif
