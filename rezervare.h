#include <iostream>
using namespace std;

class Rezervare {
    string name;
    int sala, month, day;

   public:
    Rezervare(string n, int s, int m, int d);
    friend ostream& operator<<(ostream&, const Rezervare&);
    string getName();
};