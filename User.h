#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    int id;
    string name;
    string password;

public:
    User();
    User(int i, string n, string p);

    virtual void menu() = 0;
    virtual void display();

    int getID();
    string getPassword();
    string getName();

    virtual ~User();
};

#endif
