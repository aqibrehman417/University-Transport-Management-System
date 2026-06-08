#include <iostream>
#include <fstream>
using namespace std;

const string ADMIN_FILE = "admin.txt";

void saveAdmin(string user, string pass) {
    ofstream out(ADMIN_FILE);
    out << user << " " << pass << endl;
    out.close();
}

void loadAdmin(string& user, string& pass, bool& created) {
    ifstream in(ADMIN_FILE);

    if (!in) {
        created = false;
        return;
    }

    in >> user >> pass;
    created = true;

    in.close();
}