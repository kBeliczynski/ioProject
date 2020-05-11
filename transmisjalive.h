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
    TransmisjaLive(int poziomDostepu, std::vector<Wideo*> wideoList);
    int getPoziomDostepu() const override;
    void setPoziomDostepu(int poziomDostepu) override;
    std::string getTytul() const override;
    std::pair<int, int> getCena() const override;
    void setCena(const std::pair<int, int> &nowaCena) override;
    void ogladaj() const override;
    void pobierz() const override;
};

#endif // TRANSMISJALIVE_H
