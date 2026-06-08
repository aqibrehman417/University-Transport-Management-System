#include "Vehicle.h"

Vehicle::Vehicle() {
    vehicleID = 0;
    numberPlate = "";
    capacity = 0;
    occupiedSeats = 0;
}

Vehicle::Vehicle(int id, string plate, int cap) {
    vehicleID = id;
    numberPlate = plate;
    capacity = cap;
    occupiedSeats = 0;
}

int Vehicle::getVehicleID() { return vehicleID; }
int Vehicle::getCapacity() { return capacity; }
int Vehicle::getOccupiedSeats() { return occupiedSeats; }

void Vehicle::occupySeat() {
    if (occupiedSeats < capacity)
        occupiedSeats++;
}

void Vehicle::removeSeat() {
    if (occupiedSeats > 0)
        occupiedSeats--;
}

Vehicle::~Vehicle() {}