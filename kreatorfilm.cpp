#include "kreatorfilm.h"
#include "film.h"

Material *kreatorFilm::stworzMaterial(int poziomDostepu, std::initializer_list<Wideo *> &wideoList)
{
    return new Film(poziomDostepu, wideoList);
}
