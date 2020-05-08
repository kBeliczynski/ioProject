#include "bazaKont.h"
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

string message;

bool checkLine(string & linia, string & login){
   unsigned int i=0;
   string toCompare = "";

   while( linia[i]!=' ' && i<linia.size() ){
        toCompare+=linia[i];
        i++;
   }

   if( toCompare == login )
        return false;
   return true;
}

bool validate(string & login, string & haslo){
    fstream file;
    file.open("bazaKont.txt", ios::in);
    if( file.good() ){
       string linia;
       while( getline(file, linia) ){
            if( !checkLine(linia, login) ){
                file.close();
                message = "Login jest juz zajêty";
                return false;
            }
       }

       file.close();
       return true;
    }
    else{
        message = "Blad otwarcia pliku";
        return false;
    }
}

bool BazaKont::dodajKonto(string & login, string & haslo, string & uprawnienia){
        if( validate(login, haslo) ){
            fstream file;
            file.open("bazaKont.txt", ios_base::app);
            file << login+" "+haslo+" "+uprawnienia+'\n';

            cout << "Pomyslnie zarejestrowano uzytkownika! Login to: " << login << endl;
            file.close();
            return true;
        }
        else{
            cout << message << endl;
            return false;
        }
}

bool BazaKont::usunKonto(string l){
    string login;
    string haslo;
    string chmod;

    fstream file;
    fstream newFile;

    file.open("bazaKont.txt", ios::in);
    newFile.open("temp.txt", ios::out);

    if( file.good() ){
        while( file >> login >> haslo >> chmod ){
            if( login != l )
                newFile << login+" "+haslo+" "+chmod+'\n';
        }
        newFile.close();
        file.close();

        remove("bazaKont.txt");
        rename("temp.txt", "bazaKont.txt");
        return true;
    }
    else{
        cout << "Blad otwarcia pliku" << endl;
        return false;
    }
}

string BazaKont::findAccount(string & login, string & haslo){
    fstream file;
    string l;
    string h;
    string chmod;
    bool isLogin = false;
    bool isHaslo = false;

    file.open("bazaKont.txt", ios::in);
    if( file.good() ){
        while( file >> l >> h >> chmod )
            if( l==login ){
                isLogin = true;
                if( h==haslo ){
                    isHaslo = true;
                    return chmod;
                }
            }
         file.close();

         if( isLogin && !isHaslo )
            cout << "Podales zle haslo" << endl;
         else if( !isLogin )
            cout << "Nie ma takiego loginu w bazie" << endl;

         return "";
    }
    else{
        cout << "Blad otwarcia pliku" << endl;
        return "";
    }
}
