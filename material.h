#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include "wideo.h"

class Material
{
public:
    virtual int getPoziomDostepu() const = 0;
    virtual void setPoziomDostepu(int poziomDostepu) = 0;
    virtual std::string getTytul() const = 0;
    virtual std::pair<int, int> getCena() const = 0;
    virtual void setCena(const std::pair<int, int> &nowaCena) = 0;
    virtual void ogladaj() const = 0;
    virtual void pobierz() const = 0;
};

#endif // MATERIAL_H
