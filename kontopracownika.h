#ifndef KONTOPRACOWNIKA_H
#define KONTOPRACOWNIKA_H
#include "konto.h"

class KontoPracownika : public Konto{
public:
    KontoPracownika();
    void rozpocznijTransmisje(BibliotekaMaterialow *);
    void dodajMaterial(BibliotekaMaterialow *);
    void wykupAbonament();
};

#endif // KONTOPRACOWNIKA_H
