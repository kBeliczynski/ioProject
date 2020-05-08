#include "wideo.h"

Wideo::Wideo()
{
    tytul = "";
    zawartosc = "";
}

Wideo::Wideo(const std::string &tytul, const std::string &zawartosc)
{
    this->tytul = tytul;
    this->zawartosc = zawartosc;
}

std::string Wideo::getZawartosc() const
{
    return zawartosc;
}

void Wideo::setZawartosc(const std::string &value)
{
    zawartosc = value;
}

std::string Wideo::getTytul() const
{
    return tytul;
}

void Wideo::setTytul(const std::string &value)
{
    tytul = value;
}
