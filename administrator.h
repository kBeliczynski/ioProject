#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "kontopracownika.h"
#include "bazaKont.h"

class Administrator : public KontoPracownika{
    BazaKont bazaKont;
public:
    Administrator(BazaKont);
    void usunMaterial(BibliotekaMaterialow *);
    void modyfikujKonto();
    void dodajKonto();
    void usunKonto();
    void wyswietlMenu();
    void wybierzOpcje(int, BibliotekaMaterialow *);
    void wyswietlListeKont();
};

#endif // ADMINISTRATOR_H
