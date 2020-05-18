#include "serial.h"

Serial::Serial(int poziomDostepu, std::vector<Wideo*> wideoList)
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
    if( odcinek >= 0 && odcinek<listaOdcinkow.size() ){
        std::cout << "Ogladasz teraz : ";
        std :: cout << listaOdcinkow[odcinek]->getZawartosc() << std::endl;
    }
    else
        std::cout << "Nie ma takiego numeru!" << std::endl;
}

void Serial::pobierz() const
{
    std::cout << "Nie można pobrać" << std::endl;
}
