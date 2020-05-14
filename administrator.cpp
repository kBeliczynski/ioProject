#include "administrator.h"

Administrator::Administrator(BazaKont bazaKont) : KontoPracownika(ADMINISTRATOR){
    this->bazaKont = bazaKont;
}

void Administrator::usunMaterial(BibliotekaMaterialow * biblioteka){
    cout << "Wyswietlam biblioteke wszystkich materialow: "<< endl;
    biblioteka->wyswietlKatalog();
    biblioteka->usunMaterial();
}

void Administrator::modyfikujKonto(){
    cout << "Wyswietlam liste wszystkich kont: " << endl;
    bazaKont.pokazListeKont();
//    bazaKont.modifyKonto();   // wymaga implementacji metody w klasie bazaKont
}

void Administrator::dodajKonto(){
    string login, haslo;
    string podstawowe = "PODSTAWOWE";
    string premium = "PREMIUM";
    string pracownik = "PRACOWNIK";
    int dostep;
    cout << "podaj login: ";
    cin >> login;
    cout << "podaj haslo: ";
    cin >> haslo;
    cout << "Wybierz rodzaj uprawnienia: ";
    cout << "1. Konto podstawowe" << endl;
    cout << "2. Konto premium" << endl;
    cout << "3. Konto pracownika" << endl;
    cin >> dostep;
    switch(dostep){
        case 1:
            bazaKont.dodajKonto(login,haslo,podstawowe);
            break;
        case 2:
            bazaKont.dodajKonto(login,haslo,premium);
            break;
        case 3:
            bazaKont.dodajKonto(login,haslo,pracownik);
            break;
    default:
            cout << "Podano zly numer uprawnien!" << endl;
    }
}

void Administrator::usunKonto(){
    string login;
    cout << "Wyswietlam liste wszystkich kont: " << endl;
    bazaKont.pokazListeKont();
    cout << "Podaj login konta do usuniecia: ";
    cin >> login;
    bazaKont.usunKonto(login);
}

void Administrator::wyswietlMenu(){
    KontoPracownika::wyswietlMenu();
    cout << "7. Usun material" << endl;
    cout << "8. Dodaj konto" << endl;
    cout << "9. Usun konto" << endl;
    cout << "10. Modyfikuj konto" << endl;
    cout << "11. Wyswietl liste kont" << endl;
}

void Administrator::wybierzOpcje(int wybor, BibliotekaMaterialow * biblioteka){
    if(wybor < 7)
        KontoPracownika::wybierzOpcje(wybor,biblioteka);
    else{
        switch(wybor){
            case 7:
                usunMaterial(biblioteka);
                break;
            case 8:
                dodajKonto();
                break;
            case 9:
                usunKonto();
                break;
            case 10:
                modyfikujKonto();
                break;
            case 11:
                wyswietlListeKont();
                break;
            default:
                cout << "Podana opcja nie istnieje" << endl;
        }
    }
}

void Administrator::wyswietlListeKont(){
    bazaKont.pokazListeKont();
}
