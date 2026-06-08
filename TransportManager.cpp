#include "TransportManager.h"
#include <fstream>

TransportManager::TransportManager() {
    vehicles = new Vehicle * [100];
    routes = new Route * [100];

    vehicleCount = 0;
    routeCount = 0;
}

// ===== VEHICLES =====

void TransportManager::addVehicle(Vehicle* v) {
    vehicles[vehicleCount++] = v;
    cout << "Vehicle Added Successfully" << endl;
}

void TransportManager::viewVehicles() {
    for (int i = 0; i < vehicleCount; i++) {
        vehicles[i]->displayVehicle();
    }
}

void TransportManager::removeVehicle(int id) {
    for (int i = 0; i < vehicleCount; i++) {
        if (vehicles[i]->getVehicleID() == id) {
            delete vehicles[i];

            for (int j = i; j < vehicleCount - 1; j++) {
                vehicles[j] = vehicles[j + 1];
            }

            vehicleCount--;
            cout << "Vehicle Removed" << endl;
            return;
        }
    }
    cout << "Vehicle Not Found" << endl;
}

// ===== ROUTES =====

void TransportManager::addRoute(Route* r) {
    routes[routeCount++] = r;
    cout << "Route Added" << endl;
}

void TransportManager::viewRoutes() {
    for (int i = 0; i < routeCount; i++) {
        routes[i]->displayRoute();
    }
}

// ===== SEARCH =====

Vehicle* TransportManager::searchVehicle(int id) {
    for (int i = 0; i < vehicleCount; i++) {
        if (vehicles[i]->getVehicleID() == id)
            return vehicles[i];
    }
    return NULL;
}

Route* TransportManager::searchRoute(int id) {
    for (int i = 0; i < routeCount; i++) {
        if (routes[i]->getRouteID() == id)
            return routes[i];
    }
    return NULL;
}

// ===== SAVE LOAD VEHICLES =====

void TransportManager::saveVehicles() {
    ofstream out("vehicles.txt");

    out << vehicleCount << endl;

    for (int i = 0; i < vehicleCount; i++) {
        Bus* b = dynamic_cast<Bus*>(vehicles[i]);

        if (b) {
            out << "BUS ";
            b->save(out);
        }
        else {
            Van* v = dynamic_cast<Van*>(vehicles[i]);
            out << "VAN ";
            v->save(out);
        }
    }

    out.close();
}

void TransportManager::loadVehicles() {
    ifstream in("vehicles.txt");
    if (!in) return;

    in >> vehicleCount;

    for (int i = 0; i < vehicleCount; i++) {
        string type;
        in >> type;

        int id, cap, occupied;
        string plate;

        in >> id >> plate >> cap >> occupied;

        if (type == "BUS") {
            bool ac;
            in >> ac;

            Bus* b = new Bus(id, plate, cap, ac);
            for (int j = 0; j < occupied; j++)
                b->occupySeat();

            vehicles[i] = b;
        }
        else {
            bool sd;
            in >> sd;

            Van* v = new Van(id, plate, cap, sd);
            for (int j = 0; j < occupied; j++)
                v->occupySeat();

            vehicles[i] = v;
        }
    }
}

// ===== SAVE / LOAD ROUTES =====

void TransportManager::saveRoutes() {
    ofstream out("routes.txt");

    out << routeCount << endl;

    for (int i = 0; i < routeCount; i++) {
        routes[i]->save(out);
    }
}

void TransportManager::loadRoutes() {
    ifstream in("routes.txt");
    if (!in) return;

    in >> routeCount;

    for (int i = 0; i < routeCount; i++) {
        int id, vid;
        string s, e;
        double d;

        in >> id >> s >> e >> d >> vid;

        Route* r = new Route(id, s, e, d);
        routes[i] = r;

        if (vid != -1) {
            Vehicle* v = searchVehicle(vid);
            if (v)
                r->assignVehicle(v);
        }
    }
}

// ===== STUDENTS =====

void TransportManager::saveStudents(Student* students[], int count) {
    ofstream out("students.txt");

    out << count << endl;

    for (int i = 0; i < count; i++) {
        students[i]->save(out);
    }
}

void TransportManager::loadStudents(Student* students[], int& count) {
    ifstream in("students.txt");
    if (!in) return;

    in >> count;

    for (int i = 0; i < count; i++) {
        int id;
        string name, pass, dept;
        bool reg;

        in >> id >> name >> pass >> dept >> reg;

        students[i] = new Student(id, name, pass, dept);
        students[i]->setRegistered(reg);
    }
}

// ===== DESTRUCTOR =====

TransportManager::~TransportManager() {
    for (int i = 0; i < vehicleCount; i++)
        delete vehicles[i];

    for (int i = 0; i < routeCount; i++)
        delete routes[i];

    delete[] vehicles;
    delete[] routes;
}