#ifndef BILL_H
#define BILL_H

#include <iostream>
using namespace std;

class Bill {
private:
    double fee;
    double fine;

public:
    Bill();
    Bill(double f, double fi);

    Bill operator+(Bill b);
    double total();

    void displayBill();
};

#endif
