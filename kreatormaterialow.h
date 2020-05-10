#ifndef KREATORMATERIALOW_H
#define KREATORMATERIALOW_H

#include "material.h"
#include <initializer_list>
#include "wideo.h"

class kreatorMaterialow
{
public:
    virtual Material *stworzMaterial(int poziomDostepu, std::initializer_list<Wideo*> &wideoList) = 0;
};

#endif // KREATORMATERIALOW_H
