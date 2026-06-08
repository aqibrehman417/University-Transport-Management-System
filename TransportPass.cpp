#include "TransportPass.h"

TransportPass::TransportPass() {
    passID = 0;
    student = NULL;
    route = NULL;
    approved = false;
}

TransportPass::TransportPass(int id, Student* s, Route* r, Bill b): bill(b) {
    passID = id;
    student = s;
    route = r;
    approved = false;
}

void TransportPass::approve() {
    approved = true;

    if (route && route->getVehicle()) {
        route->getVehicle()->occupySeat();
    }
}

void TransportPass::cancel() {
    approved = false;

    if (route && route->getVehicle()) {
        route->getVehicle()->removeSeat();
    }
}

void TransportPass::displayPass() {
    cout << "PASS ID: " << passID << endl;
    cout << "Student: " << student->getName() << endl;
    cout << "Status: " << (approved ? "Approved" : "Pending") << endl;
    bill.displayBill();
}