#include "Student.h"
#include <fstream>

Student::Student() {
    department = "";
    registered = false;
}

Student::Student(int i, string n, string p, string d): User(i, n, p) {
    department = d;
    registered = false;
}

Student::Student(const Student& s) {
    id = s.id;
    name = s.name;
    password = s.password;
    department = s.department;
    registered = s.registered;
}

Student& Student::operator=(const Student& s) {
    if (this != &s) {
        id = s.id;
        name = s.name;
        password = s.password;
        department = s.department;
        registered = s.registered;
    }
    return *this;
}

void Student::menu() {
    cout << "========== STUDENT MENU ==========" << endl;
    cout << "1. View Routes" << endl;
    cout << "2. Apply for Transport" << endl;
    cout << "3. View Registration" << endl;
    cout << "4. Cancel Registration" << endl;
    cout << "5. View Profile" << endl;
    cout << "6. Logout" << endl;
}

void Student::display() {
    User::display();
    cout << "Department: " << department << endl;
    cout << "Status: " << (registered ? "Registered" : "Not Registered") << endl;
}

void Student::save(ofstream& out) {
    out << id << " " << name << " " << password << " "
        << department << " " << registered << endl;
}

void Student::setRegistered(bool r) {
    registered = r;
}

bool Student::getRegistered() {
    return registered;
}