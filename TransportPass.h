#ifndef TRANSPORTPASS_H
#define TRANSPORTPASS_H

#include "Student.h"
#include "Route.h"
#include "Bill.h"

class TransportPass {
private:
    int passID;
    Student* student;
    Route* route;
    Bill bill;
    bool approved;

public:
    TransportPass();
    TransportPass(int id, Student* s, Route* r, Bill b);

    void approve();
    void cancel();
    void displayPass();
};

#endif
