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
    Film(int poziomDostepu, std::initializer_list<Wideo*> &wideoList);
    int getPoziomDostepu() const;
    void setPoziomDostepu(int poziomDostepu);
    std::string getTytul() const;
    std::pair<int, int> getCena() const;
    void setCena(const std::pair<int, int> &nowaCena);
    void ogladaj() const;
};

#endif // FILM_H
