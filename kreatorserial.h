#ifndef KREATORSERIAL_H
#define KREATORSERIAL_H

#include "kreatormaterialow.h"
#include "serial.h"

class kreatorSerial : public kreatorMaterialow
{
public:
    Material *stworzMaterial(int poziomDostepu, std::vector<Wideo*> wideoList);
};

#endif // KREATORSERIAL_H
