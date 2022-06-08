#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "rezervare.cpp"
#include "sala.cpp"
using namespace std;

// CREATE REZERVARE
int selecteaza_data_zi() {
    int ver;

    cout << "Alege o  zi:\n";
    cin >> ver;

    if (ver >= 1 && ver <= 31)
        return ver;
    else {
        cout << "NU EXISTA LUNA: " << ver << endl;
        return selecteaza_data_zi();
    }
}

int selecteaza_data_luna() {
    int ver;

    cout << "1. Ianuarie\n";
    cout << "2. Februarie\n";
    cout << "3. Martie\n";
    cout << "4. Aprilie\n";
    cout << "5. Mai\n";
    cout << "6. Iunie\n";
    cout << "7. Iulie\n";
    cout << "8. August\n";
    cout << "9. Septenbrie\n";
    cout << "10. Octombrie\n";
    cout << "11. Noiembrie\n";
    cout << "12. Decembrie\n";

    cin >> ver;

    if (ver >= 1 && ver <= 12)
        return ver;
    else {
        cout << "NU EXISTA LUNA: " << ver << endl;
        return selecteaza_data_luna();
    }
}

int selecteaza_sala() {
    int ver;

    cout << "Selecteaza o sala\n";
    cout << "1. Sala 1\n";
    cout << "2. Sala 2\n";
    cout << "3. Sala 3\n";
    cout << "4. Sala 4\n";

    cin >> ver;
    return ver;
}

Rezervare creaza_rezervare() {
    int sala, month, day;
    string name;

    cout << "Introduceti numele\n";
    cin >> name;
    sala = selecteaza_sala();
    month = selecteaza_data_luna();
    day = selecteaza_data_zi();

    return Rezervare(name, sala, month, day);
}

// DELETE
void delete_rezervare(vector<Rezervare> r, string n) {
    vector<Rezervare>::iterator it;
    it = r.begin();
    while (it != r.end()) {
        if (it->getName() == n) {
            r.erase(it);
        }
        it++;
    }
}

// PRINT
int search_rezervare(vector<Rezervare> r, string name) {
    for (int i = 0; i < r.size(); i++) {
        if (r[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

void afisare_sali(vector<Sala> s) {
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
}

void afisare_rezervari(vector<Rezervare> r) {
    vector<Rezervare>::iterator it;
    it = r.begin();
    while (it != r.end()) {
        cout << *it << endl;
        it++;
    }
}

// FILE IO
void load_sali(vector<Sala>& s) {
    ifstream file("sali.txt");
    string line;

    if (!file) {
        cout << "FILE NOT FOUND";
    } else {
        int price, parking, seats;
        bool wifi;
        string name;

        while (!file.eof()) {
            file >> name;
            file >> wifi;
            file >> price;
            file >> parking;
            file >> seats;
            s.push_back(Sala(name, wifi, price, parking, seats));
        }
    }
    file.close();
}

// NOT TESTED
void save_rezervari(vector<Rezervare> r) {
    ofstream file("rezervari.txt");

    if (!file) {
        cout << "FILE NOT FOUND";
    } else {
        for (int i = 0; i < r.size(); i++) {
            file << r[i].getName() << endl;
            file << r[i].getSala() << endl;
            file << r[i].getMonth() << endl;
            file << r[i].getDay() << endl;
        }
    }
    file.close();
}

void load_rezervari(vector<Rezervare>& r) {
    ifstream file("rezervari.txt");
    string line;

    if (!file) {
        cout << "No rezervari prezent";
    } else {
        int sala, month, day;
        string name;
        while (!file.eof()) {
            file >> name;
            file >> sala;
            file >> month;
            file >> day;
            r.push_back(Rezervare(name, sala, month, day));
        }
    }
    file.close();
}

int main() {
    vector<Sala> sali;
    vector<Rezervare> rezervari;

    bool run = true;
    int choice;
    string name, delete_name;

    load_sali(sali);
    load_rezervari(rezervari);
    while (run) {
        cout << "1. Creaza rezervare\n2. Cauta rezervare\n3. Sterge "
                "rezervare\n4. Print sali\n5. "
                "Print rezervari\n6. "
                "Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Se va crea o rezervare" << endl;
                rezervari.push_back(creaza_rezervare());
                save_rezervari(rezervari);
                break;
            case 2:
                cout << "Introduceti numele dvs: " << endl;
                cin >> name;
                cout << rezervari[search_rezervare(rezervari, name)];
                break;
            case 3:
                cout << "Se va sterge o rezervare" << endl;
                cout << "Introduceti numele dvs: " << endl;
                cin >> delete_name;
                delete_rezervare(rezervari, name);
                save_rezervari(rezervari);
                break;
            case 4:
                cout << "Printam sali" << endl;
                afisare_sali(sali);
                break;
            case 5:
                cout << "Printam rezervari" << endl;
                afisare_rezervari(rezervari);
                break;
            case 6:
                run = false;
                save_rezervari(rezervari);
                break;
            default:
                cout << "\nOptiunea nu exisat\n";
                break;
        }
    }
    return 0;
}