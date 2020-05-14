#ifndef bazaKont_h
#define bazaKont_h
#include <iostream>

class BazaKont{
    public:
        bool dodajKonto(std::string&, std::string&, std::string& );
        bool usunKonto(std::string);
        std::string findAccount(std::string&, std::string&);
        void pokazListeKont();
        bool usunKonto(std::string&, std::string&);
        //void getKonto(std::string&);
        //void modifyKonto();
};
#endif // bazaKont_h
