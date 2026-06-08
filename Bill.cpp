#include "Bill.h"

Bill::Bill() {
    fee = 0;
    fine = 0;
}

Bill::Bill(double f, double fi) {
    fee = f;
    fine = fi;
}

Bill Bill::operator+(Bill b) {
    return Bill(fee + b.fee, fine + b.fine);
}

double Bill::total() {
    return fee + fine;
}

void Bill::displayBill() {
    cout << "FEE: " << fee << endl;
    cout << "FINE: " << fine << endl;
    cout << "TOTAL: " << total() << endl;
}