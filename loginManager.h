#ifndef loginManager_h
#define loginManager_h
#include "bazaKont.h"

class LoginManager{
    BazaKont baza;
    public:
        void zaloguj();
        void zarejestruj();
        //void zalogujAdmin(string login, string haslo);
};

#endif // loginManager_h
