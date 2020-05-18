#ifndef loginManager_h
#define loginManager_h
#include "bazaKont.h"
#include "konto.h"

class LoginManager{
    BazaKont baza;
    public:
        Konto * zaloguj();
        Konto * zarejestruj();
        //void zalogujAdmin(string login, string haslo);
};

#endif // loginManager_h
