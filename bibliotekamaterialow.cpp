#include "bibliotekamaterialow.h"


void BibliotekaMaterialow::dodajMaterial(const std::string &typKreatora, int poziomDostepu, std::initializer_list<Wideo *> &wideoList)
{
    if (kreatoryMaterialow.find(typKreatora) == kreatoryMaterialow.end())
    {
        std::cout << "Błędna nazwa kreatora" << std::endl;
    }
    else
    {
        kreatorMaterialow* k = kreatoryMaterialow[typKreatora];
        k->stworzMaterial(poziomDostepu, wideoList);
    }
}

void BibliotekaMaterialow::usunMaterial()
{
    std::cout << "Podaj numer materiału do usunięcia z katalogu materiałów lub -1 by anulować:" << std::endl;
    long toRemove;
    std::cin >> toRemove;
    if (toRemove == -1)
    {
        return;
    }
    else if (toRemove >= 0 && toRemove < bibliotekaMaterialow.size())
    {
        bibliotekaMaterialow.erase(bibliotekaMaterialow.begin() + toRemove);
    }
}

void BibliotekaMaterialow::wyswietlKatalog() const
{
    for (std::vector<Material*>::size_type i = 0; i < bibliotekaMaterialow.size(); ++i)
    {
        std::cout << i + 1 << ". " << bibliotekaMaterialow[i]->getTytul() << std::endl;
    }
}

void BibliotekaMaterialow::dodajKreator(const std::string &typKreatora, kreatorMaterialow *kreator)
{
    kreatoryMaterialow[typKreatora] = kreator;
}
