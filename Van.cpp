#include "Van.h"

Van::Van() : Vehicle() {
    slidingDoor = false;
}

Van::Van(int id, string plate, int cap, bool sd)
    : Vehicle(id, plate, cap) {
    slidingDoor = sd;
}

void Van::displayVehicle() {
    cout << "VAN ID: " << vehicleID << endl;
    cout << "Plate: " << numberPlate << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Occupied: " << occupiedSeats << endl;
    cout << "Sliding Door: " << (slidingDoor ? "Yes" : "No") << endl;
}

void Van::save(ofstream& out) {
    out << vehicleID << " " << numberPlate << " "
        << capacity << " " << occupiedSeats << " " << slidingDoor << endl;
}

void Van::load(ifstream& in) {
    in >> vehicleID >> numberPlate >> capacity >> occupiedSeats >> slidingDoor;
}