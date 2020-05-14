#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "kontopracownika.h"
#include "bazaKont.h"

class Administrator : public KontoPracownika{
    BazaKont bazaKont;
public:
    Administrator(BazaKont);
    void usunMaterial(BibliotekaMaterialow *); //jest
    void modyfikujKonto(); //aby dokonczyc wymaga metody modyfiKonto w klasie bazaKont
    void dodajKonto(); // jest
    void usunKonto(); // jest
    void wyswietlMenu();
    void wybierzOpcje(int, BibliotekaMaterialow *);
    void wyswietlListeKont();
};

#endif // ADMINISTRATOR_H
