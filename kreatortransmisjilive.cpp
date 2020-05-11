#include "kreatortransmisjilive.h"

Material *kreatorTransmisjiLive::stworzMaterial(int poziomDostepu, std::vector<Wideo *> wideoList)
{
    return new TransmisjaLive(poziomDostepu, wideoList);
}
