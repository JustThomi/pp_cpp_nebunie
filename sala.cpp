#include "sala.h"

#include <iostream>
using namespace std;

Sala::Sala(string n, bool w, int price, int p, int s) {
    this->name = n;
    this->wifi = w;
    this->price = price;
    this->parking = p;
    this->seats = s;
}

ostream& operator<<(ostream& os, const Sala& b) {
    os << b.name << " " << b.wifi << " " << b.price << " " << b.seats << " "
       << b.parking << endl;
    return os;
}