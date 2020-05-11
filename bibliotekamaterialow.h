#ifndef BIBLIOTEKAMATERIALOW_H
#define BIBLIOTEKAMATERIALOW_H

#include "material.h"
#include "kreatormaterialow.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>

class BibliotekaMaterialow
{
private:
    std::vector<Material*> bibliotekaMaterialow;
    std::map <std::string, kreatorMaterialow*> kreatoryMaterialow;
public:
    void dodajMaterial(const std::string &typKreatora, int poziomDostepu,
                       std::initializer_list<Wideo*> wideoList);
    void usunMaterial();
    void wyswietlKatalog() const;
    void dodajKreator(const std::string &typKreatora, kreatorMaterialow *kreator);
    int getPoziomDostepu(int numerMaterialu) const;
    void setPoziomDostepu(int numerMaterialu, int poziomDostepu);
    std::pair<int, int> getCena(int numerMaterialu) const;
    void setCena(int numerMaterialu, std::pair<int, int> nowaCena);
    void ogladaj(int numerMaterialu) const;
    void pobierz(int numerMaterialu);
};

#endif // BIBLIOTEKAMATERIALOW_H
