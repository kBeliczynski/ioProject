#include "bibliotekamaterialow.h"
#include "kreatorfilm.h"
#include "kreatorserial.h"
#include "kreatortransmisjilive.h"
#include "loginManager.h"
#include "konto.h"
#include "kontopracownika.h"
#include "administrator.h"
using namespace std;

void initializeLibrary(BibliotekaMaterialow * biblioMat ){

    kreatorFilm *kFilm = new kreatorFilm;  //inicjalizacja kreatorow
    kreatorSerial *kSerial = new kreatorSerial;
    kreatorTransmisjiLive *kTransmisja = new kreatorTransmisjiLive;

    biblioMat->dodajKreator("FILM", kFilm); //dodanie kreatorow do biblioteki
    biblioMat->dodajKreator("SERIAL", kSerial);
    biblioMat->dodajKreator("TRANSMISJA", kTransmisja);


    Wideo *wid = new Wideo("The Lighthouse", "The Lighthouse content"); //inicjalizacja wideo
    biblioMat->dodajMaterial("FILM", 2, {wid});
    biblioMat->setCena(1, std::make_pair(19, 99));
    wid = new Wideo("Debata prezydencka", "Czy poratowałby Pan Stanisława Żółtka szlugiem albo chociaż złotóweczką?");
    biblioMat->dodajMaterial("TRANSMISJA", 0, {wid});
    biblioMat->dodajMaterial("SERIAL", 0, {new Wideo("Mr Robot S01E01", "Mr Robot S01E01 content"),
                             new Wideo("Mr Robot S01E02", "Mr Robot S01E02 content"),
                             new Wideo("Mr Robot S01E03", "Mr Robot S01E03 content")});
}

int main(){
    LoginManager * systemLogowania;
    Konto * konto = NULL;
    Administrator * administrator = NULL;
    KontoPracownika * pracownik = NULL;

    string option;
    bool notLogged = true;

    cout << "Witaj uzytkowniku!" << endl;
    cout << "1.Zaloguj sie. " << endl;
    cout << "2.Zarejestruj sie " << endl;
    cout << "3.Zaloguj admin: " << endl;
    cout << "Wybierz co chcesz zrobic: " << endl;
    cin >> option;

    while( notLogged ){ //system logowania
        if( option == "1" ){
            konto = systemLogowania->zaloguj();
            if( konto->getDostep() == ADMINISTRATOR ){
                konto = NULL;
                cout << "Adminie zalogowales sie w zlym panelu! Zalogowalismy cie jako Admina!" << endl;
                administrator = new Administrator(BazaKont());
            }
            else if( konto->getDostep()==PRACOWNIK){
                pracownik = new KontoPracownika();
                konto = NULL;
                cout << "Witaj w koncie pracownika!" << endl;
            }
            else
                cout << "Zalogowano pomyslnie!" << endl;
                break;
        }
        else if( option == "2" ){
            konto = systemLogowania->zarejestruj();
            break;
        }
        else if( option == "3" ){
            konto = systemLogowania->zaloguj();
            if( konto->getDostep() == ADMINISTRATOR ){
                cout << "Pomyslnie zalogowano admina" << endl;
                administrator = new Administrator(BazaKont());
                konto = NULL;
                break;
            }
            else{
                konto = NULL;
                cout << "Blad logowania! Sprobuj jeszcze raz!" << endl;
                continue;
            }
        }
        else
            cout << "Podales niepoprawna opcje! Sprobuj jeszcze raz!" << endl;
    }

    int wybor=true;

    BibliotekaMaterialow *biblioMat = new BibliotekaMaterialow;
    initializeLibrary(biblioMat);

    if( administrator != NULL ){ //administrator
        while(wybor != 0){
            administrator->wyswietlMenu();
            cout << "Ktora opcje wybrac : ";
            cin >> wybor;
            cout << "-------------------------------" << endl;
            administrator->wybierzOpcje(wybor,biblioMat);
            cout << "-------------------------------" << endl;
        }
    }
    else if( pracownik != NULL ){ // pracownik
         while(wybor != 0){
            pracownik->wyswietlMenu();
            cout << "Ktora opcje wybrac : ";
            cin >> wybor;
            cout << "-------------------------------" << endl;
            pracownik->wybierzOpcje(wybor,biblioMat);
            cout << "-------------------------------" << endl;
        }
    }
    else{ //Uzytkownik premium lub zwykly
        while(wybor != 0){
            konto->wyswietlMenu();
            cout << "Ktora opcje wybrac : ";
            cin >> wybor;
            cout << "-------------------------------" << endl;
            konto->wybierzOpcje(wybor,biblioMat);
            cout << "-------------------------------" << endl;
        }
    }
    return 0;
}
