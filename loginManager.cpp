#include "loginManager.h"
#include <iostream>
using namespace std;


void LoginManager::zarejestruj(){
    cout << "-------------------" << endl;
    cout << "Zarejestruj sie: " << endl;

    string login;
    string haslo;
    string uprawnienie = "PODSTAWOWE";

    cout << "Podaj login: " << endl;
    cin >> login;
    cout << "Podaj haslo: " << endl;
    cin >> haslo;

    if( !baza.dodajKonto(login, haslo, uprawnienie) ){
        cout << "Sprobuj jeszcze raz!" << endl;
        zarejestruj();
    }
    else
        zaloguj();
}

void LoginManager::zaloguj(){
    cout << "-------------------" << endl;
    cout << "Zaloguj sie: " << endl;

    string login;
    string haslo;
    string chmod;

    cout << "Podaj login: " << endl;
    cin >> login;
    cout << "Podaj haslo: " << endl;
    cin >> haslo;

    chmod = baza.findAccount(login, haslo);
    if( chmod == ""){
        cout << "Sprobuj ponownie" << endl;
        zaloguj();
    }
    else
        cout << "Zalogowano pomyslnie" << endl;

    // tutaj poprowadzenie do innego interfejsu
}
