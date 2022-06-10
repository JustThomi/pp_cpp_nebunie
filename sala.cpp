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
    os << "Nume:" << b.name << endl << "WiFi: " << b.wifi << endl << "Pret: " << b.price << endl << "Locuri: " << b.seats << endl <<
      "Locuri de parcari: " << b.parking << endl;
    return os;
}

string Sala::getName() { return name; }
bool Sala::getWifi() { return wifi; }
int Sala::getPrice() { return price; }
int Sala::getParking() { return parking; }
int Sala::getSeats() { return seats; }
