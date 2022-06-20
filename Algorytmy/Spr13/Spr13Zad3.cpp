#include <iostream>
#include <string>
using namespace std;

string plotki(string haslo, int wysokosc){
    string wynik;
    for (int i=0; i<wysokosc; i++){ // ustawiamy wynik modulo, ktory zadziala jak tablica z plotkami
        for (int j=0; j<haslo.length(); j++){ // idziemy po kolei dodajac litery spelniajace warunek
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
    cout << "Oto haslo: "+plotki(haslo, 3);
    return 0;
}