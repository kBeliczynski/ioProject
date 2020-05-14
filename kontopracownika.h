#ifndef KONTOPRACOWNIKA_H
#define KONTOPRACOWNIKA_H
#include "konto.h"

class KontoPracownika : public Konto{
public:
    KontoPracownika();
    KontoPracownika(dostep );
    void rozpocznijTransmisje(BibliotekaMaterialow *);
    void dodajMaterial(BibliotekaMaterialow *);
    void wykupAbonament();
    void wyswietlMenu();
    void wybierzOpcje(int, BibliotekaMaterialow *);
};

#endif // KONTOPRACOWNIKA_H
