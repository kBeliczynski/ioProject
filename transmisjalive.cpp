#include "transmisjalive.h"


TransmisjaLive::TransmisjaLive(int poziomDostepu, std::vector<Wideo *> wideoList)
{
    this->poziomDostepu = poziomDostepu;
    transmisja = *wideoList.begin();
}

int TransmisjaLive::getPoziomDostepu() const
{
     return poziomDostepu;
}

void TransmisjaLive::setPoziomDostepu(int poziomDostepu)
{
    this->poziomDostepu = poziomDostepu;
}

std::string TransmisjaLive::getTytul() const
{
    return transmisja->getTytul();
}

std::pair<int, int> TransmisjaLive::getCena() const
{
    return std::make_pair(0, 0);
}

void TransmisjaLive::setCena(const std::pair<int, int> &nowaCena)
{
    cena = nowaCena;
}

void TransmisjaLive::ogladaj() const
{
    std::cout << transmisja->getZawartosc() << std::endl;
}

void TransmisjaLive::pobierz() const
{
    std::cout << "Pobieranie transmisji pod tytułem: " << getTytul() << std::endl;
}
