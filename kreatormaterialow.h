#ifndef KREATORMATERIALOW_H
#define KREATORMATERIALOW_H

#include "material.h"
#include <vector>

class kreatorMaterialow
{
public:
    virtual Material *stworzMaterial(int poziomDostepu, std::vector<Wideo*> wideoList) = 0;
};

#endif // KREATORMATERIALOW_H
