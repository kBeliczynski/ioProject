using namespace std;
#ifndef KONTO_H
#define KONTO_H

#include<iostream>
#include<list>
#include "wideo.h"
#include "bibliotekamaterialow.h"
#include <unistd.h>
enum dostep{
    PODSTAWOWE, PREMIUM, PRACOWNIK, ADMINISTRATOR
};

class Konto{
    list<Wideo> listaWykupionychFilmow;
    dostep poziomDostepu;
    bool reklamy;

public:
    Konto(dostep);
    Konto(dostep, bool);
    void wykupAbonament();
    dostep getDostep();
    void wyswietlKatalog(BibliotekaMaterialow *);
    void ogladaj(BibliotekaMaterialow *);
    void pobierz(BibliotekaMaterialow *);
    void wyswietlMenu();
    void wybierzOpcje(int, BibliotekaMaterialow *);
};

#endif // KONTO_H
