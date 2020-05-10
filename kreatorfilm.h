#ifndef KREATORFILM_H
#define KREATORFILM_H

#include "kreatormaterialow.h"

class kreatorFilm : public kreatorMaterialow
{
public:
    Material *stworzMaterial(int poziomDostepu, std::initializer_list<Wideo*> &wideoList);
};

#endif // KREATORFILM_H
