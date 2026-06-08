#include "User.h"

User::User() {
    id = 0;
    name = "";
    password = "";
}

User::User(int i, string n, string p) {
    id = i;
    name = n;
    password = p;
}

void User::display() {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
}

int User::getID() { return id; }
string User::getPassword() { return password; }
string User::getName() { return name; }

User::~User() {}