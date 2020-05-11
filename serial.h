#ifndef SERIAL_H
#define SERIAL_H

#include <vector>
#include "material.h"

class Serial : public Material
{
    int poziomDostepu;
    std::vector<Wideo*> listaOdcinkow;
    std::pair<int, int> cena;
public:
    Serial(int poziomDostepu, std::vector<Wideo*> wideoList);
    int getPoziomDostepu() const override;
    void setPoziomDostepu(int poziomDostepu) override;
    std::string getTytul() const override;
    std::pair<int, int> getCena() const override;
    void setCena(const std::pair<int, int> &nowaCena) override;
    void ogladaj() const override;
    void pobierz() const override;
};

#endif // SERIAL_H
