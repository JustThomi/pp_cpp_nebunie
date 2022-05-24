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

    cout << "0. Meniu principal\n\n";
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

    cout << "0. Meniu principal\n";
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
    cout << "0. Meniu principal\n";
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
// nu merge atm, dar nu m-am mai uitat dc
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
        cout << *it;
        it++;
    }
}

// FILE IO
void load_sali() {
    fstream file;

    if (!file) {
        cout << "FILE NOT FOUND";
    } else {
        // to be continued lol
    }
}

int main() {
    vector<Sala> sali;
    vector<Rezervare> rezervari;

    bool run = true;
    int choice;
    string name, delete_name;

    // hardcoded sali for testing
    sali.push_back(Sala("Sweden", true, 100, 50, 50));
    sali.push_back(Sala("India", true, 200, 100, 100));
    sali.push_back(Sala("Japan", true, 350, 200, 300));
    sali.push_back(Sala("Poland", false, 400, 500, 500));

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
                break;
            case 2:
                // No error handling prezent atm
                cout << "Introduceti numele dvs: " << endl;
                cin >> name;
                cout << rezervari[search_rezervare(rezervari, name)];
                break;
            case 3:
                cout << "Se va sterge o rezervare" << endl;
                cout << "Introduceti numele dvs: " << endl;
                cin >> delete_name;
                delete_rezervare(rezervari, name);
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
                break;
            default:
                cout << "\nOptiunea nu exisat\n";
                break;
        }
    }
    return 0;
}