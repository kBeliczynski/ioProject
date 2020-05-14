#include "bibliotekamaterialow.h"
#include "kreatorfilm.h"
#include "kreatorserial.h"
#include "kreatortransmisjilive.h"
#include "loginManager.h"
#include "konto.h"
#include "kontopracownika.h"
#include "administrator.h"
using namespace std;

int main(){
    // Inizjalizacja biblioteki i dostępnych kreatorów materiałów.
    kreatorFilm *kFilm = new kreatorFilm;
    kreatorSerial *kSerial = new kreatorSerial;
    kreatorTransmisjiLive *kTransmisja = new kreatorTransmisjiLive;
    BibliotekaMaterialow *biblioMat = new BibliotekaMaterialow;
    biblioMat->dodajKreator("FILM", kFilm);
    biblioMat->dodajKreator("SERIAL", kSerial);
    biblioMat->dodajKreator("TRANSMISJA", kTransmisja);

    // Dodanie przykładowych elementów bi\blioteki.
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
    BazaKont bazakont;
    int wybor=1;
    /* Poniżej demonstracja użycia biblioteki materiałów. Pozostałe funkcje są oczywiste.
    biblioMat->wyswietlKatalog();
    biblioMat->pobierz(2);
    biblioMat->ogladaj(3);
    cout << biblioMat->getCena(1).first << " zł " << biblioMat->getCena(1).second << " gr" << endl;
    cout << biblioMat->getPoziomDostepu(1) << endl;
    /**/

//    LoginManager loginMenago;
//    loginMenago.zarejestruj();

    Administrator administrator(bazakont);
    while(wybor != 0){
        administrator.wyswietlMenu();
        cout << "Ktora opcje wybrac : ";
        cin >> wybor;
        administrator.wybierzOpcje(wybor,biblioMat);
    }
/*
    KontoPracownika pracownik;
     while(wybor != 0){
        pracownik.wyswietlMenu();
        cout << "Ktora opcje wybrac : ";
        cin >> wybor;
        pracownik.wybierzOpcje(wybor,biblioMat);
    }

    Konto konto;
     while(wybor != 0){
        konto.wyswietlMenu();
        cout << "Ktora opcje wybrac : ";
        cin >> wybor;
        konto.wybierzOpcje(wybor,biblioMat);
    }
/**/

    return 0;
}
