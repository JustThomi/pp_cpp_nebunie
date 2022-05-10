#include <iostream>
using namespace std;

int main(){
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
                break;
            case 2:
                cout << "Introduceti numele dvs: " << endl;
            case 3:
                cout << "Se va sterge o rezervare" << endl;
                break;
            case 4:
                cout << "Printam sali" << endl;
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