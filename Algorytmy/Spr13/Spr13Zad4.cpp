#include <iostream>
#include <string>
using namespace std;

string sciezka(string haslo, int wysokosc){
    string wynik;
    if (haslo.length()%wysokosc != 0) { // dodajemy x tak dlugo az nasz string byl dlugosci, ktory jest podzielny przez ilosc kolumn (3)
        while (haslo.length()%wysokosc != 0) haslo += "x";
    }
    for (int i=wysokosc-1; i>=0; i--){ // ustawiamy wynik modulo, ktory zadziala jak tablica z plotkami
        if (i%2==0){ // (UWAGA! kolumny zaczynaja sie od "0")
            for (int j=0; j<haslo.length(); j++){ // dla kolumny parzystej idzie z gory do dolu
                if (j%wysokosc==i) wynik += haslo[j];
            }
        }
        else for (int j=haslo.length()-1; j>=0; j--){ // dla kolumny nieparzystej idzie z dolu do gory
                if (j%wysokosc==i) wynik += haslo[j];
            }
    }
    return wynik;
}

int main(){
    string haslo;
    int wysokosc;
    cout << "Podaj haslo do zaszyfrowania: ";
    cin >> haslo;
    //cout << "Podaj wysokosc plotu: "; jesli chcemy miec inna wysokosc plotu
    //cin >> wysokosc; musimy tylko podstawic wysokosc zamiast 3 w kolejnej funkcji
    cout << "Oto haslo: "+sciezka(haslo, 3);    
    return 0;
}