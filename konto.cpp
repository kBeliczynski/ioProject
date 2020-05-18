#include "konto.h"
#include "windows.h"

Konto::Konto(dostep poziom){
    this->poziomDostepu = poziom;
    this->reklamy = true;
}

Konto::Konto(dostep poziomDostepu, bool reklamy){
    this->poziomDostepu = poziomDostepu;
    this->reklamy = reklamy;
}

dostep Konto::getDostep(){
    return this->poziomDostepu;
}

void Konto::wykupAbonament(){
    if(this->poziomDostepu == PODSTAWOWE){
        cout << "Wykupiono abonament. Od teraz posiadasz konto premium" << endl;
        cout << "Okres premium wygasa z wylaczeniem systemu!" << endl;
        this->poziomDostepu = PREMIUM;
        this->reklamy = false;
    }else
        cout << "Posiadasz najwyzszy rodzaj abonamentu" << endl;
}

void Konto::wyswietlKatalog(BibliotekaMaterialow * biblioteka){
    cout << "Twoje materialy : " << endl;
    if(this->listaWykupionychFilmow.empty())
        cout << "Brak posiadanych materialow w twojej bibliotece." << endl;
    else
        for(auto lista : this->listaWykupionychFilmow){
            cout << lista.getTytul() << endl;
        }
    cout << "Ogolna biblioteka : " << endl;
    biblioteka->wyswietlKatalog();
}

void Konto::ogladaj(BibliotekaMaterialow * biblioteka){
    int numer;
    biblioteka->wyswietlKatalog();
    cout << "podaj numer materialu : ";
    cin >> numer;

    //można dodać walidacje czy numer jest poprawny

    if(this->poziomDostepu == PODSTAWOWE){
        cout << "REKLAMA";
        for(int i=0; i<5; i++){
            Sleep(1); // sleep(1);
            cout << ". ";
            cout.flush();
        }
        cout << endl;
    }
    biblioteka->ogladaj(numer);
}

void Konto::pobierz(BibliotekaMaterialow * biblioteka){
    if(this->poziomDostepu == PODSTAWOWE){
        cout << "Uzytkownicy z kontem podstwowym nie maja opcji pobierania materialow" << endl;
    }else{
        int numer;
        cout << "Podaj numer materialu do pobrania: ";
        cin >> numer;
        biblioteka->pobierz(numer);
    }
}

void Konto::wyswietlMenu(){
    cout << "-------------MENU--------------" << endl;
    cout << "0. Zamknij program" << endl;
    cout << "1. Wykup abonament" << endl;
    cout << "2. Wyswietl katalog" << endl;
    cout << "3. ogladaj material" << endl;
    cout << "4. pobierz material" << endl;
}

void Konto::wybierzOpcje(int wybor, BibliotekaMaterialow * biblioteka){
        switch(wybor){
            case 0:
                 cout << "Zamykam program" << endl;
                 break;
            case 1:
                 wykupAbonament();
                 break;
             case 2:
                wyswietlKatalog(biblioteka);
                break;
            case 3:
                ogladaj(biblioteka);
                break;
            case 4:
                pobierz(biblioteka);
                break;
            default:
                cout << "Taka opcja nie istnieje";
    }
}
