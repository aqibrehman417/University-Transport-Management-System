#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "TransportManager.h"
#include "Report.h"
#include "TransportPass.h"

using namespace std;

void saveAdmin(string user, string pass);
void loadAdmin(string& user, string& pass, bool& created);

int main() {

    TransportManager manager;

    // Load saved data
    manager.loadVehicles();
    manager.loadRoutes();

    DynamicArray<Student*> students(100);
    int studentCount = 0;

    manager.loadStudents(students.getArray(), studentCount);

    // Admin data
    string adminUser = "";
    string adminPass = "";
    bool adminCreated = false;

    loadAdmin(adminUser, adminPass, adminCreated);

    cout << "===== SYSTEM STARTED =====" << endl;

    int Choice;

    do {
        cout << "========== UNIVERSITY TRANSPORT SYSTEM ==========" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Create Admin Account" << endl;
        cout << "3. Student Sign Up" << endl;
        cout << "4. Student Login" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> Choice;

        // ================= ADMIN LOGIN =================
        if (Choice == 1) {
            
            if (!adminCreated) {
                cout << "No admin account found!"<<endl;
                continue;
            }

            string u, p;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;

            if (u == adminUser && p == adminPass) {

                int choice;

                do {
                    cout << "========== ADMIN MENU ==========" << endl;
                    cout << "1. Add Vehicle" << endl;
                    cout << "2. View Vehicles" << endl;
                    cout << "3. Remove Vehicle" << endl;
                    cout << "4. Add Route" << endl;
                    cout << "5. Assign Vehicle to Route" << endl;
                    cout << "6. View Routes" << endl;
                    cout << "7. Reports" << endl;
                    cout << "8. Save Data" << endl;
                    cout << "9. Logout" << endl;
                    cout << "Enter: ";
                    cin >> choice;

                    // ADD VEHICLE
                    if (choice == 1) {

                        int type;
                        cout << "1. Bus" << endl;
                        cout << "2. Van" << endl;
                        cout << "Choice: " << endl;
                        cin >> type;

                        int id, cap;
                        string plate;

                        cout << "ID: "; cin >> id;
                        cout << "Plate Number: "; cin >> plate;
                        cout << "Capacity: "; cin >> cap;

                        if (type == 1) {
                            bool ac;
                            cout << "AC (1/0): ";
                            cin >> ac;
                            manager.addVehicle(new Bus(id, plate, cap, ac));
                        }
                        else {
                            bool sd;
                            cout << "Sliding Door (1/0): ";
                            cin >> sd;
                            manager.addVehicle(new Van(id, plate, cap, sd));
                        }
                    }

                    // VIEW VEHICLES
                    else if (choice == 2) {
                        manager.viewVehicles();
                    }

                    // REMOVE VEHICLE
                    else if (choice == 3) {
                        int id;
                        cout << "Enter Vehicle ID: ";
                        cin >> id;
                        manager.removeVehicle(id);
                    }

                    // ADD ROUTE
                    else if (choice == 4) {
                        int id;
                        string s, e;
                        double d;

                        cout << "Route ID: "; cin >> id;
                        cout << "Start: "; cin >> s;
                        cout << "End: "; cin >> e;
                        cout << "Distance: "; cin >> d;

                        manager.addRoute(new Route(id, s, e, d));
                    }

                    // ASSIGN VEHICLE
                    else if (choice == 5) {
                        manager.viewRoutes();
                        manager.viewVehicles();

                        int rid, vid;
                        cout << "Route ID: "; cin >> rid;
                        cout << "Vehicle ID: "; cin >> vid;

                        Route* r = manager.searchRoute(rid);
                        Vehicle* v = manager.searchVehicle(vid);

                        if (r && v) {
                            r->assignVehicle(v);
                            cout << "Assigned Successfully" << endl;
                        }
                        else {
                            cout << "Invalid IDs" << endl;
                        }
                    }

                    // VIEW ROUTES
                    else if (choice == 6) {
                        manager.viewRoutes();
                    }

                    // REPORTS
                    else if (choice == 7) {
                        Report r;
                        r.generateRevenueReport();
                        r.generateRouteReport();
                    }

                    // SAVE DATA
                    else if (choice == 8) {
                        manager.saveVehicles();
                        manager.saveRoutes();
                        manager.saveStudents(students.getArray(), studentCount);
                        saveAdmin(adminUser, adminPass);
                        cout << "Data Saved" << endl;
                    }

                } while (choice != 9);

            }
            else {
                cout << "Invalid Admin Login" << endl;
            }
        }

        // ================= CREATE ADMIN =================
        else if (Choice == 2) {

            if (adminCreated) {
                cout << "Admin already exists!" << endl;
            }
            else {
                cout << "Create Username: ";
                cin >> adminUser;
                cout << "Create Password: ";
                cin >> adminPass;

                adminCreated = true;
                saveAdmin(adminUser, adminPass);

                cout << "Admin Created Successfully" << endl;
            }
        }

        // ================= STUDENT SIGNUP =================
        else if (Choice == 3) {

            int id;
            string name, pass, dept;

            cout << "ID: "; cin >> id;
            cout << "Name: "; cin >> name;
            cout << "Password: "; cin >> pass;
            cout << "Department: "; cin >> dept;

            students[studentCount++] = new Student(id, name, pass, dept);

            cout << "Account Created" << endl;
        }

        // ================= STUDENT LOGIN =================
        else if (Choice == 4) {

            int id;
            string pass;

            cout << "ID: "; cin >> id;
            cout << "Password: "; cin >> pass;

            bool found = false;

            for (int i = 0; i < studentCount; i++) {

                if (students[i]->getID() == id &&
                    students[i]->getPassword() == pass) {

                    found = true;

                    int choice;

                    do {
                        cout << "========== STUDENT MENU ==========" << endl;
                        cout << "1. View Routes" << endl;
                        cout << "2. Apply Transport" << endl;
                        cout << "3. View Status" << endl;
                        cout << "4. Cancel Registration" << endl;
                        cout << "5. View Profile" << endl;
                        cout << "6. Logout" << endl;
                        cout << "Enter: ";
                        cin >> choice;

                        // VIEW ROUTES
                        if (choice == 1) {
                            manager.viewRoutes();
                        }

                        // APPLY TRANSPORT
                        else if (choice == 2) {

                            int rid;
                            manager.viewRoutes();

                            cout << "Route ID: ";
                            cin >> rid;

                            Route* r = manager.searchRoute(rid);

                            if (r && r->getVehicle() &&
                                r->getVehicle()->getOccupiedSeats() <
                                r->getVehicle()->getCapacity()) {

                                double fine = 0;
                                int late;

                                cout << "Late days: ";
                                cin >> late;

                                if (late > 5) fine = 500;

                                Bill b(5000, fine);

                                TransportPass p(1, students[i], r, b);
                                p.approve();
                                p.displayPass();

                                students[i]->setRegistered(true);

                                cout << "Transport Approved" << endl;
                            }
                            else {
                                cout << "No vehicle or seats full" << endl;
                            }
                        }

                        // STATUS
                        else if (choice == 3) {
                            cout << (students[i]->getRegistered()
                                ? "Registered\n"
                                : "Not Registered\n");
                        }

                        // CANCEL
                        else if (choice == 4) {
                            students[i]->setRegistered(false);
                            cout << "Cancelled\n";
                        }

                        // PROFILE
                        else if (choice == 5) {
                            students[i]->display();
                        }

                    } while (choice != 6);
                }
            }

            if (!found)
                cout << "Invalid Student Login" << endl;
        }

    } while (Choice != 5);

    // ================= SAVE BEFORE EXIT =================
    manager.saveVehicles();
    manager.saveRoutes();
    manager.saveStudents(students.getArray(), studentCount);
    saveAdmin(adminUser, adminPass);

    // cleanup
    for (int i = 0; i < studentCount; i++)
        delete students[i];

    cout << "System Closed" << endl;

    return 0;
}