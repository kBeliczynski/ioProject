#ifndef KREATORTRANSMISJILIVE_H
#define KREATORTRANSMISJILIVE_H

#include "kreatormaterialow.h"
#include "transmisjalive.h"

class kreatorTransmisjiLive : public kreatorMaterialow
{
public:
    Material *stworzMaterial(int poziomDostepu, std::vector<Wideo*> wideoList);
};

#endif // KREATORTRANSMISJILIVE_H
