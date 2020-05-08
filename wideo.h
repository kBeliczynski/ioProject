#ifndef WIDEO_H
#define WIDEO_H

#include <string>

class Wideo
{
    std::string tytul;
    std::string zawartosc;
public:
    Wideo();
    Wideo(const std::string &tytul, const std::string &zawartosc);
    std::string getTytul() const;
    void setTytul(const std::string &value);
    std::string getZawartosc() const;
    void setZawartosc(const std::string &value);
};

#endif // WIDEO_H
