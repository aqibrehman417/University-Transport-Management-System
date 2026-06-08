#include "Bus.h"

Bus::Bus() : Vehicle() {
    AC = false;
}

Bus::Bus(int id, string plate, int cap, bool ac)
    : Vehicle(id, plate, cap) {
    AC = ac;
}

void Bus::displayVehicle() {
    cout << "BUS ID: " << vehicleID << endl;
    cout << "Plate Number: " << numberPlate << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Occupied: " << occupiedSeats << endl;
    cout << "AC: " << (AC ? "Yes" : "No") << endl;
}

void Bus::save(ofstream& out) {
    out << vehicleID << " " << numberPlate << " "
        << capacity << " " << occupiedSeats << " " << AC << endl;
}

void Bus::load(ifstream& in) {
    in >> vehicleID >> numberPlate >> capacity >> occupiedSeats >> AC;
}