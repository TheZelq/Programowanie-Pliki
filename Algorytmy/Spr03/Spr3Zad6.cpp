#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string pesel;
    char tab[11]; // deklaracja tablicy 11elementowej
    int suma=0;
    cout << "Podaj pesel" << endl;
    cin >> pesel;
    strcpy(tab, pesel.c_str()); // funkcja strcpy pozwala zamienic stringa na tablice
    suma += int(tab[0])*1; // odpowiednio nadaje wartosci w zaleznosci od pozycji w peselu
    suma += int(tab[1])*3; // poniewaz tablica jest charem, uzywajac int(tab[x]) jestem w stanie zamienic wartosc char na wartosc int
    suma += int(tab[2])*7;
    suma += int(tab[3])*9;
    suma += int(tab[4])*1;
    suma += int(tab[5])*3;
    suma += int(tab[6])*7;
    suma += int(tab[7])*9;
    suma += int(tab[8])*1;
    suma += int(tab[9])*3;
    suma += int(tab[10])*1;
    if (suma%10==0) { // sprawdza czy suma jest podzielna przez 10
        cout << "PESEL jest poprawny" << endl;
    } else cout << "PESEL nie jest poprawny" << endl;
    return 0;
}
