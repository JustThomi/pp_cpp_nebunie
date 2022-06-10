#include <iostream>
using namespace std;

class Rezervare {
    string name, sala;
    int month, day;

   public:
    Rezervare(string n, string s, int m, int d);
    friend ostream& operator<<(ostream&, const Rezervare&);
    string getName();
    string getSala();
    int getMonth();
    int getDay();
};