#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <fstream>
#include "Vehicle.h"
using namespace std;

class Route {
private:
    int routeID;
    string startPoint;
    string endPoint;
    double distance;
    Vehicle* assignedVehicle;

public:
    Route();
    Route(int id, string s, string e, double d);

    int getRouteID();
    Vehicle* getVehicle();

    void assignVehicle(Vehicle* v);

    void save(ofstream& out);
    void displayRoute();
};

#endif
