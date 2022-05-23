#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Sala{
    string name;
    int price, parking,seats;
    bool wifi;

public:
    Sala(string n, bool w, int price, int p, int s);
    friend ostream & operator <<(ostream &, const Sala&);
};

Sala::Sala(string n, bool w, int price, int p, int s) {
    this -> name = n;
    this -> wifi = w;
    this -> price = price;
    this -> parking = p;
    this -> seats = s;
}

ostream& operator <<(ostream &a, const Sala& b){
    a << b.name << " " << b.wifi << " " << b.price <<" "<< b.seats << " " << b.parking << endl;
    return a;
}



void selecteaza_data_zi(int zile){
    cout<<"0. Meniu principal\n\n";

    cout<<"Alege o  zi:\n";

    for(int i=1; i<=zile; i++ )
        cout<<i<<" ";

    int ver_zi;
    cin>>ver_zi;
    switch(ver_zi) {
        case 0:
            break;
        default:
            cout<<"Rezervarea a fost facuta cu succes.\n\n\n";
            break;
    }
}

void selecteaza_data_luna() {
    cout<<"0. Meniu principal\n";
    cout<<"1. Ianuarie\n";
    cout<<"2. Februarie\n";
    cout<<"3. Martie\n";
    cout<<"4. Aprilie\n";
    cout<<"5. Mai\n";
    cout<<"6. Iunie\n";
    cout<<"7. Iulie\n";
    cout<<"8. August\n";
    cout<<"9. Septenbrie\n";
    cout<<"10. Octombrie\n";
    cout<<"11. Noiembrie\n";
    cout<<"12. Decembrie\n";
    int ver;
    cin>>ver;
    switch(ver) {
        case 0:
            break;
        case 1:
            selecteaza_data_zi(31);
            break;
        case 2:
            selecteaza_data_zi(28);
            break;
        case 3:
            selecteaza_data_zi(31);
            break;
        case 4:
            selecteaza_data_zi(30);
            break;
        case 5:
            selecteaza_data_zi(31);
            break;
        case 6:
            selecteaza_data_zi(30);
            break;
        case 7:
            selecteaza_data_zi(31);
            break;
        case 8:
            selecteaza_data_zi(31);
            break;
        case 9:
            selecteaza_data_zi(30);
            break;
        case 10:
            selecteaza_data_zi(31);
            break;
        case 11:
            selecteaza_data_zi(30);
            break;
        case 12:
            selecteaza_data_zi(31);
            break;
        default:
            cout<<"Introduceti una din variantele existente\n\n\n";
            break;
    }
}


void selecteaza_sala() {
    int ver;
    cout<<"0. Meniu principal\n";
    cout<<"1. Sala 1\n";
    cout<<"2. Sala 2\n";
    cout<<"3. Sala 3\n";
    cout<<"4. Sala 4\n";
    cin>>ver;
    switch(ver) {
        case 0:
            break;
        default:
            selecteaza_data_luna();
            break;
    }
}


void creaza_rezervare() {
    cout<<"Introduceti numele\n";
    char name[100];
    cin>>name;
    int ver;
    cout<<"0. Meniu principal\n";
    cout<<"1. Selecteaza o sala\n";
    cin>>ver;
    switch(ver) {
        case 0:
            break;
        case 1:
            selecteaza_sala();
            break;
        default:
            cout<<"Introduceti una din variantele existente\n\n\n";
            break;
    }
}



void afisare_sali() {
    int ver;
    cout<<"0. Meniu principal\n";
    cout<<"1. Sala 1\n";
    cout<<"2. Sala 2\n";
    cout<<"3. Sala 3\n";
    cout<<"4. Sala 4\n";
    cout<<"\n\n";
    cin>>ver;
    switch(ver) {
        case 0:
            break;
        default:
            break;
    }
}

int main(){
    vector<Sala> sali;
    bool run = true;
    int choice;

    while(run){
            cout <<"1. Creaza rezervare\n2. Cauta rezervare\n3. Sterge rezervare\n4. Print sali\n5. "
            "Print rezervari\n6. "
            "Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Se va crea o rezervare" << endl;
                creaza_rezervare();
                break;
            case 2:
                cout << "Introduceti numele dvs: " << endl;
            case 3:
                cout << "Se va sterge o rezervare" << endl;
                break;
            case 4:
                cout << "Printam sali" << endl;
                afisare_sali();
                break;
            case 5:
                cout << "Printam rezervari" << endl;
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