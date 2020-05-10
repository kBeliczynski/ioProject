#ifndef TRANSMISJALIVE_H
#define TRANSMISJALIVE_H

#include "material.h"
#include <utility>

class TransmisjaLive : public Material
{
    int poziomDostepu;
    Wideo *transmisja;
    std::pair<int, int> cena;
public:
    TransmisjaLive(int poziomDostepu, std::initializer_list<Wideo*> &wideoList);
    int getPoziomDostepu() const;
    void setPoziomDostepu(int poziomDostepu);
    std::string getTytul() const;
    std::pair<int, int> getCena() const;
    void setCena(const std::pair<int, int> &nowaCena);
    void ogladaj() const;
};

#endif // TRANSMISJALIVE_H
