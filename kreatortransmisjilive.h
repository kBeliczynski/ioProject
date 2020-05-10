#ifndef KREATORTRANSMISJILIVE_H
#define KREATORTRANSMISJILIVE_H

#include "kreatormaterialow.h"

class kreatorTransmisjiLive : public kreatorMaterialow
{
public:
    Material *stworzMaterial(int poziomDostepu, std::initializer_list<Wideo*> &wideoList);
};

#endif // KREATORTRANSMISJILIVE_H
