#pragma once
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string numberPlate;
    int capacity;
    int occupiedSeats;

public:
    Vehicle();
    Vehicle(int id, string plate, int cap);

    virtual void displayVehicle() = 0;
    virtual void save(ofstream& out) = 0;
    virtual void load(ifstream& in) = 0;

    int getVehicleID();
    int getCapacity();
    int getOccupiedSeats();

    void occupySeat();
    void removeSeat();

    virtual ~Vehicle();
};

#endif