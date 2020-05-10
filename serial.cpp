#include "serial.h"

Serial::Serial(int poziomDostepu, std::initializer_list<Wideo*> &wideoList)
{
    this->poziomDostepu = poziomDostepu;
    listaOdcinkow = wideoList;
}

int Serial::getPoziomDostepu() const
{
    return poziomDostepu;
}

void Serial::setPoziomDostepu(int poziomDostepu)
{
    this->poziomDostepu = poziomDostepu;
}

std::string Serial::getTytul() const
{
    return listaOdcinkow[0]->getTytul();
}

std::pair<int, int> Serial::getCena() const
{
    return cena;
}

void Serial::setCena(const std::pair<int, int> &nowaCena)
{
    cena = nowaCena;
}

void Serial::ogladaj() const
{
    std::cout << "Wybierz numer odninka od 0 do " << listaOdcinkow.size() - 1
              << std::endl;
    int odcinek;
    std::cin >> odcinek;
    std :: cout << listaOdcinkow[odcinek]->getZawartosc() << std::endl;
}
