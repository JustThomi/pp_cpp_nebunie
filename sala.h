#include <iostream>
using namespace std;

class Sala {
    string name;
    int price, parking, seats;
    bool wifi;

   public:
    Sala(string n, bool w, int price, int p, int s);
    friend ostream& operator<<(ostream&, const Sala&);

    string getName();
    int getPrice();
    int getParking();
    int getSeats();
    bool getWifi();
};