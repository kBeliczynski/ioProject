#include "kreatortransmisjilive.h"
#include "transmisjalive.h"

Material *kreatorTransmisjiLive::stworzMaterial(int poziomDostepu, std::initializer_list<Wideo *> &wideoList)
{
    return new TransmisjaLive(poziomDostepu, wideoList);
}
