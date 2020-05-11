#include "bibliotekamaterialow.h"
#include "kreatorfilm.h"
#include "kreatorserial.h"
#include "kreatortransmisjilive.h"
#include "loginManager.h"
#include "konto.h"
#include "kontopracownika.h"

using namespace std;

int main()
{
    // Inizjalizacja biblioteki i dostępnych kreatorów materiałów.
    kreatorFilm *kFilm = new kreatorFilm;
    kreatorSerial *kSerial = new kreatorSerial;
    kreatorTransmisjiLive *kTransmisja = new kreatorTransmisjiLive;
    BibliotekaMaterialow *biblioMat = new BibliotekaMaterialow;
    biblioMat->dodajKreator("FILM", kFilm);
    biblioMat->dodajKreator("SERIAL", kSerial);
    biblioMat->dodajKreator("TRANSMISJA", kTransmisja);

    // Dodanie przykładowych elementów biblioteki.
    // To administrator lub pracownik tworzy elementy klasy wideo i podaje je do
    // funkcji dodającej materiały do biblioteki w postaci listy inizjalizacyjnej.
    Wideo *wid = new Wideo("The Lighthouse", "The Lighthouse content");
    biblioMat->dodajMaterial("FILM", 2, {wid});
    biblioMat->setCena(1, std::make_pair(19, 99));
    wid = new Wideo("Debata prezydencka", "Czy poratowałby Pan Stanisława Żółtka szlugiem albo chociaż złotóweczką?");
    biblioMat->dodajMaterial("TRANSMISJA", 0, {wid});
    biblioMat->dodajMaterial("SERIAL", 0, {new Wideo("Mr Robot S01E01", "Mr Robot S01E01 content"),
                             new Wideo("Mr Robot S01E02", "Mr Robot S01E02 content"),
                             new Wideo("Mr Robot S01E03", "Mr Robot S01E03 content")});

    /* Poniżej demonstracja użycia biblioteki materiałów. Pozostałe funkcje są oczywiste.
    biblioMat->wyswietlKatalog();
    biblioMat->pobierz(2);
    biblioMat->ogladaj(3);
    cout << biblioMat->getCena(1).first << " zł " << biblioMat->getCena(1).second << " gr" << endl;
    cout << biblioMat->getPoziomDostepu(1) << endl;
    /**/

    /*
    Konto konto;
    konto.wyswietlKatalog(biblioMat);
    konto.ogladaj(biblioMat);
    konto.pobierz(biblioMat);
    konto.wykupAbonament();
    konto.wykupAbonament();
    konto.ogladaj(biblioMat);
    konto.pobierz(biblioMat);
    /**/

    KontoPracownika kontoPracownika;
//    kontoPracownika.wykupAbonament();
//    kontoPracownika.wyswietlKatalog(biblioMat);
//    kontoPracownika.rozpocznijTransmisje(biblioMat);
    kontoPracownika.dodajMaterial(biblioMat);

//    LoginManager loginMenago;
//    loginMenago.zarejestruj();



    return 0;
}
