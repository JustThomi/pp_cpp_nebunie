#include "rezervare.h"

#include <iostream>
using namespace std;

Rezervare::Rezervare(string n, int s, int m, int d) {
    this->name = n;
    this->sala = s;
    this->month = m;
    this->day = d;
}

ostream& operator<<(ostream& os, const Rezervare& r) {
    os << "Nume: " << r.name << endl
       << "Sala numarul: " << r.sala << endl
       << "In data de: " << r.day << "." << r.month << endl;
    return os;
}

string Rezervare::getName() { return name; }