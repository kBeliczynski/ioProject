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
    Serial(int poziomDostepu, std::initializer_list<Wideo*> &wideoList);
    int getPoziomDostepu() const;
    void setPoziomDostepu(int poziomDostepu);
    std::string getTytul() const;
    std::pair<int, int> getCena() const;
    void setCena(const std::pair<int, int> &nowaCena);
    void ogladaj() const;
};

#endif // SERIAL_H
