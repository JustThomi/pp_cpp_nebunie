#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "rezervare.cpp"
#include "sala.cpp"
using namespace std;

// CREATE REZERVARE
int selecteaza_data_zi(int n, string s, vector<Rezervare> rezervari) {
    int ver;

    if (n == 1 || n == 3 || n == 5  || n == 7 || n == 8 || n == 10 || n==12){
        for( int i = 1 ; i <= 31; i++){
            int g = 0;
            for( int j = 0; j < rezervari.size() && g == 0; j++) {
                if (rezervari[j].getDay() == i && rezervari[i].getSala() != s)
                    g = 1;
            }
            if(g == 0)
                cout<< i << " ";
        }
    }
    else{
        for( int i = 1 ; i <= 30; i++){
            int g = 0;
            for( int j = 0; j < rezervari.size() && g == 0; j++) {
                if (rezervari[j].getDay() == i && rezervari[i].getSala() != s)
                    g = 1;
            }
            if(g == 0)
                cout<< i << " ";
        }
    }

    cout << endl;
    cout << "0. Meniu principal\n\n";
    cout << "Alege o  zi:\n";

    cin >> ver;

    if (ver >= 1 && ver <= 31)
        return ver;
    else {
        cout << "NU EXISTA LUNA: " << ver << endl;
        return selecteaza_data_zi(ver, s, rezervari);
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

string selecteaza_sala(vector<Sala> s) {
    string ver;

    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }

    cin >> ver;
    return ver;
}

Rezervare creaza_rezervare(vector<Rezervare> rezervari, vector<Sala> sali) {
    int month, day;
    string name, sala;

    cout << "Introduceti numele\n";
    cin >> name;
    sala = selecteaza_sala(sali);
    month = selecteaza_data_luna();
    day = selecteaza_data_zi(month, sala, rezervari);

    return Rezervare(name, sala, month, day);
}


// DELETE
void delete_rezervare(vector<Rezervare> &r, string n) {
    auto it = r.begin();
    while (it <= r.end()) {
        if (it->getName() == n) {
            it = r.erase(it);
        }
        it++;
    }
}

// PRINT
void search_rezervare(vector<Rezervare> r, string name) {
    int g = 0;
    for (int i = 0; i < r.size(); i++) {
        if (r[i].getName() == name) {
            cout << "Sala: " << r[i].getSala() << endl << "Data: " << r[i].getDay() << "." << r[i].getMonth() << endl;
            g = 1;
        }
    }
    if(g == 0)
        cout << "Nu avem o rezervare facuta pe acest nume..." << endl;
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
            file << r[i].getDay()<< endl;
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
        int month, day;
        string name, sala;
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

void filtreaza_capacitatea(vector<Sala>& f){
    int c;
    cin >> c;
    for (auto i = f.begin(); i!=f.end(); ++i){
        if(i->getSeats() < c){
            f.erase(i);
            i--;
        }
    }
}

void filtreaza_pret(vector<Sala>& f){
    int p;
    cin >> p;
    for (auto i = f.begin(); i!=f.end(); ++i){
        if(i->getPrice() > p){
            f.erase(i);
            i--;
        }
    }
};

void filtreaza_parcare(vector<Sala>& f){
    int p;
    cin >> p;
    for (auto i = f.begin(); i!=f.end(); ++i){
        if(i->getParking() < p){
            f.erase(i);
            i--;
        }
    }
}

void filtreaza_wifi(vector<Sala>& f){
    bool w;
    cin >> w;
    for (auto i = f.begin(); i!=f.end(); ++i){
        if(i->getWifi() != w){
            f.erase(i);
            i--;
        }
    }
}


void filtreaza_sali(vector<Rezervare> r, vector<Sala> s){
    bool run = true;
    vector<Sala> f;
    for (int i=0; i<s.size(); i++)
        f.push_back(s[i]);
    while(run){
        cout << "1. Filtrare dupa capacitate\n2. Filtrare dupa pret\n3. Filtrare dupa locuri de parcare\n4. Filtrare dupa wifi\n5. Creaza rezervare\n6. Exit\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Numar de persoane:\n";
                filtreaza_capacitatea(f);
                afisare_sali(f);
                break;
            case 2:
                cout << "Pret:\n";
                filtreaza_pret(f);
                afisare_sali(f);
                break;
            case 3:
                cout << "Numar de locuri de parcare:\n";
                filtreaza_parcare(f);
                afisare_sali(f);
                break;
            case 4:
                cout << "Wifi:\n";
                filtreaza_wifi(f);
                afisare_sali(f);
                break;
            case 5:
                cout << "Se va crea o rezervare" << endl;
                r.push_back(creaza_rezervare(r,f));
                save_rezervari(r);
                break;
            case 6:
                run = false;
                break;
        }
    }

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
                "Print rezervari\n6. Filtreaza sali\n7. "
                "Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Se va crea o rezervare" << endl;
                rezervari.push_back(creaza_rezervare(rezervari,sali));
                save_rezervari(rezervari);
                break;
            case 2:
                cout << "Introduceti numele dvs: " << endl;
                cin >> name;
                search_rezervare(rezervari, name);
                break;
            case 3:
                cout << "Se va sterge o rezervare" << endl;
                cout << "Introduceti numele dvs: " << endl;
                cin >> delete_name;
                delete_rezervare(rezervari, delete_name);
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
                cout << "Selecteaza filtrul: ";
                filtreaza_sali(rezervari,sali);
            case 7:
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