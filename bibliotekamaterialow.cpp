#include "bibliotekamaterialow.h"


void BibliotekaMaterialow::dodajMaterial(const std::string &typKreatora, int poziomDostepu, std::initializer_list<Wideo *> wideoList)
{
    if (kreatoryMaterialow.find(typKreatora) == kreatoryMaterialow.end())
    {
        std::cout << "Błędna nazwa kreatora" << std::endl;
    }
    else
    {
        kreatorMaterialow* k = kreatoryMaterialow[typKreatora];
        std::vector<Wideo*> vec;
        vec.insert(vec.end(), wideoList.begin(), wideoList.end());
        bibliotekaMaterialow.push_back(k->stworzMaterial(poziomDostepu, vec));
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

int BibliotekaMaterialow::getPoziomDostepu(int numerMaterialu) const
{
    return bibliotekaMaterialow[numerMaterialu - 1]->getPoziomDostepu();
}

void BibliotekaMaterialow::setPoziomDostepu(int numerMaterialu, int poziomDostepu)
{
    bibliotekaMaterialow[numerMaterialu - 1]->setPoziomDostepu(poziomDostepu);
}

std::pair<int, int> BibliotekaMaterialow::getCena(int numerMaterialu) const
{
    return bibliotekaMaterialow[numerMaterialu - 1]->getCena();
}

void BibliotekaMaterialow::setCena(int numerMaterialu, std::pair<int, int> nowaCena)
{
    bibliotekaMaterialow[numerMaterialu - 1]->setCena(nowaCena);
}

void BibliotekaMaterialow::ogladaj(int numerMaterialu) const
{
    bibliotekaMaterialow[numerMaterialu - 1]->ogladaj();
}

void BibliotekaMaterialow::pobierz(int numerMaterialu)
{
    bibliotekaMaterialow[numerMaterialu - 1]->pobierz();
}
