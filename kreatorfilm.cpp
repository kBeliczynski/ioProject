#include "kreatorfilm.h"

Material *kreatorFilm::stworzMaterial(int poziomDostepu, std::vector<Wideo *> wideoList)
{
    return new Film(poziomDostepu, wideoList);
}
