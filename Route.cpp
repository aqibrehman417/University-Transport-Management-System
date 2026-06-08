#include "Route.h"

Route::Route() {
    routeID = 0;
    distance = 0;
    assignedVehicle = NULL;
}

Route::Route(int id, string s, string e, double d) {
    routeID = id;
    startPoint = s;
    endPoint = e;
    distance = d;
    assignedVehicle = NULL;
}

int Route::getRouteID() {
    return routeID;
}

Vehicle* Route::getVehicle() {
    return assignedVehicle;
}

void Route::assignVehicle(Vehicle* v) {
    assignedVehicle = v;
}

void Route::save(ofstream& out) {
    out << routeID << " " << startPoint << " "
        << endPoint << " " << distance << " ";

    if (assignedVehicle)
        out << assignedVehicle->getVehicleID();
    else
        out << -1;

    out << endl;
}

void Route::displayRoute() {
    cout << "ROUTE ID: " << routeID << endl;
    cout << "Start: " << startPoint << endl;
    cout << "End: " << endPoint << endl;
    cout << "Distance: " << distance << endl;

    if (assignedVehicle) {
        cout << "Vehicle ID: " << assignedVehicle->getVehicleID() << endl;
    }
    else {
        cout << "No Vehicle Assigned" << endl;
    }
    cout << endl;
}