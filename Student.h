
#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

class Student : public User {
private:
    string department;
    bool registered;

public:
    Student();
    Student(int i, string n, string p, string d);

    Student(const Student& s);
    Student& operator=(const Student& s);

    void menu() override;
    void display() override;

    void save(ofstream& out);

    void setRegistered(bool r);
    bool getRegistered();
};

#endif