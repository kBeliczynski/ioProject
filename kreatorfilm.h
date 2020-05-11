#ifndef KREATORFILM_H
#define KREATORFILM_H

#include "kreatormaterialow.h"
#include "film.h"

class kreatorFilm : public kreatorMaterialow
{
public:
    Material *stworzMaterial(int poziomDostepu, std::vector<Wideo*> wideoList);
};

#endif // KREATORFILM_H
