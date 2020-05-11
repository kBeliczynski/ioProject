#include "film.h"

Film::Film(int poziomDostepu, std::vector<Wideo*> wideoList)
{
    this->poziomDostepu = poziomDostepu;
    film = wideoList[0];
}

int Film::getPoziomDostepu() const
{
    return poziomDostepu;
}

void Film::setPoziomDostepu(int poziomDostepu)
{
    this->poziomDostepu = poziomDostepu;
}

std::string Film::getTytul() const
{
    return film->getTytul();
}

std::pair<int, int> Film::getCena() const
{
    return cena;
}

void Film::setCena(const std::pair<int, int> &nowaCena)
{
    cena = nowaCena;
}

void Film::ogladaj() const
{
    std::cout << film->getZawartosc() << std::endl;
}

void Film::pobierz() const
{
    std::cout << "Nie można pobrać" << std::endl;
}
