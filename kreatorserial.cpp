#include "kreatorserial.h"

Material *kreatorSerial::stworzMaterial(int poziomDostepu, std::vector<Wideo *> wideoList)
{
    return new Serial(poziomDostepu, wideoList);
}
