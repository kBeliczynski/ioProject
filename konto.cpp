#include "konto.h"

Konto::Konto(){
    this->poziomDostepu = PODSTAWOWE;
    this->reklamy = true;
}

Konto::Konto(dostep poziomDostepu, bool reklamy){
    this->poziomDostepu = poziomDostepu;
    this->reklamy = reklamy;
}

void Konto::wykupAbonament(){
    if(this->poziomDostepu == PODSTAWOWE){
        cout << "Wykupiono abonament. Od teraz posiadasz konto premium" << endl;
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
    cout << "podaj numer materialu : ";
    cin >> numer;

    //można dodać walidacje czy numer jest poprawny

    if(this->poziomDostepu == PODSTAWOWE){
        cout << "REKLAMA";
        for(int i=0; i<5; i++){
            sleep(1);
            cout << ". ";
            cout.flush();
        }
        cout << endl;
    }
    cout << "Ogladasz teraz : ";
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
