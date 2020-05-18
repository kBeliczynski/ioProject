#include "loginManager.h"
#include <iostream>
using namespace std;

dostep convert(string chmod){
    dostep d;
    if( chmod == "User" )
        d = PODSTAWOWE;
    else if( chmod == "Pracownik")
        d = PRACOWNIK;
    else if( chmod == "Administrator")
        d = ADMINISTRATOR;
    else if( chmod == "Premium")
        d = PREMIUM;
    return d;
}


Konto * LoginManager::zarejestruj(){
    cout << "-------------------" << endl;
    cout << "Zarejestruj sie: " << endl;

    string login;
    string haslo;
    string uprawnienie = "Podstawowe";

    cout << "Podaj login: " << endl;
    cin >> login;
    cout << "Podaj haslo: " << endl;
    cin >> haslo;

    if( !baza.dodajKonto(login, haslo, uprawnienie) ){
        cout << "Sprobuj jeszcze raz!" << endl;
        return zarejestruj();
    }
    else
        return zaloguj();
}

Konto * LoginManager::zaloguj(){
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
    else{
        dostep d = convert(chmod);
        return new Konto(d);
    }

    // tutaj poprowadzenie do innego interfejsu
}
