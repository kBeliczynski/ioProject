#include "kontopracownika.h"


KontoPracownika::KontoPracownika() : Konto(PRACOWNIK,false){}

KontoPracownika::KontoPracownika(dostep d) : Konto(d,false){}


void KontoPracownika::rozpocznijTransmisje(BibliotekaMaterialow * biblioteka){
    string tytul, zawartosc;
    char c;
    cout << "Podaj tytul : ";
    cin >> tytul;
    cin.ignore();
    cout << "Podaj zawartosc: ";
    getline(cin,zawartosc);
    cout << "Rozpoczynam transmisje" << endl;
    sleep(1);
    cout << "Transmisja trwa ";
    for(int i=0; i<5; i++){
        sleep(1);
        cout << ". ";
        cout.flush();
    }
    cout << endl << "Transmisja zostala zakonczona" << endl;
    cout << "Jesli chcesz zapisac transmisje kliknij 't' jesli nie, kliknij dowolny klawisz : ";
    c = getchar();
    if(c == 't'){
        Wideo * transmisja = new Wideo;
        transmisja->setTytul(tytul);
        transmisja->setTytul(tytul);
        transmisja->setZawartosc(zawartosc);
        biblioteka->dodajMaterial("TRANSMISJA",0,{transmisja});
        cout << "Dodano transmisje" << endl;
    }
}

void KontoPracownika::wykupAbonament() {Konto::wykupAbonament();}

void KontoPracownika::dodajMaterial(BibliotekaMaterialow * biblioteka){
    int licznik = 0;
    string kreatory[biblioteka->getKreatoryMaterialow().size()];
    int wybor, poziomDostepu;
    string tytul, zawartosc;
    cout << "Jaki material chcesz dodac ? " << endl;
    for(auto it=biblioteka->getKreatoryMaterialow().begin(); it!=biblioteka->getKreatoryMaterialow().end(); it++,licznik++){
        cout<< licznik+1 << ". " <<it->first<<endl;
        kreatory[licznik]=it->first;
    }
    cin >> wybor;
    cout << "Podaj tytul: ";
    cin >> tytul;
    cin.ignore();
    cout << "Podaj zawartosc: ";
    getline(cin,zawartosc);
    cout << "Podaj poziom dostepu: ";
    cin >> poziomDostepu;
    Wideo * wideo = new Wideo;
    wideo->setTytul(tytul);
    wideo->setZawartosc(zawartosc);
    biblioteka->dodajMaterial(kreatory[wybor-1],poziomDostepu,{wideo});
    cout << "Dodano " << kreatory[wybor-1] << " pomyslnie"<< endl;
}

void KontoPracownika::wyswietlMenu(){
    Konto::wyswietlMenu();
    cout << "5. Rozpocznij transmisje" << endl;
    cout << "6. Dodaj material" << endl;
}

void KontoPracownika::wybierzOpcje(int wybor, BibliotekaMaterialow * biblioteka){
    if(wybor < 5)
        Konto::wybierzOpcje(wybor,biblioteka);
    else{
        switch(wybor){
            case 5:
                rozpocznijTransmisje(biblioteka);
                break;
            case 6:
                dodajMaterial(biblioteka);
                break;
            default:
                cout << "Podana opcja nie istnieje" << endl;
        }
    }
}
