#include "kreatorserial.h"
#include "serial.h"

Material *kreatorSerial::stworzMaterial(int poziomDostepu, std::initializer_list<Wideo *> &wideoList)
{
    return new Serial(poziomDostepu, wideoList);
}
