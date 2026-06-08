#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H

#include "Vehicle.h"
#include "Route.h"
#include "Bus.h"
#include "Van.h"
#include "Student.h"

class TransportManager {
private:
    Vehicle** vehicles;
    Route** routes;

    int vehicleCount;
    int routeCount;

public:
    TransportManager();

    void addVehicle(Vehicle* v);
    void viewVehicles();
    void removeVehicle(int id);

    void addRoute(Route* r);
    void viewRoutes();

    Vehicle* searchVehicle(int id);
    Route* searchRoute(int id);

    void saveVehicles();
    void loadVehicles();

    void saveRoutes();
    void loadRoutes();

    void saveStudents(Student* students[], int count);
    void loadStudents(Student* students[], int& count);

    ~TransportManager();
};

#endif
