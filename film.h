#ifndef FILM_H
#define FILM_H

#include <utility>
#include "material.h"

class Film : public Material
{
    int poziomDostepu;
    Wideo *film;
    std::pair<int, int> cena;   // first == złote; second == grosze
public:
    Film(int poziomDostepu, std::vector<Wideo*> wideoList);
    int getPoziomDostepu() const override;
    void setPoziomDostepu(int poziomDostepu) override;
    std::string getTytul() const override;
    std::pair<int, int> getCena() const override;
    void setCena(const std::pair<int, int> &nowaCena) override;
    void ogladaj() const override;
    void pobierz() const override;
};

#endif // FILM_H
