#ifndef KREATORSERIAL_H
#define KREATORSERIAL_H

#include "kreatormaterialow.h"

class kreatorSerial : public kreatorMaterialow
{
public:
    Material *stworzMaterial(int poziomDostepu, std::initializer_list<Wideo*> &wideoList);
};

#endif // KREATORSERIAL_H
