#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a;
    cout << "Jesli chcesz zamienic dzies na bin, wpisz 1" << endl << "Jesli chcesz zamienic bin na dzies, wpisz 2" << endl;
    cin >> a; // pyta uzytkownika w ktora strone chce zamienic
    switch (a) {
        case 1: { // dzies na bin 
            int numer, i=0, tablica[31]; 
            cout << "Podaj liczbe do zamiany" << endl;
            cin >> numer;
            while(numer!=0){ // sprwawdza modulo przez 2 i dodaje wynik do tablicy; dzieli tak dlugo az liczba osiagnie wartosc 0
                tablica[i++]=numer%2;
                numer/=2; // dzieli liczbe na 2
            }
            for (int j=i-1; j>=0; j--) cout<<tablica[j]; // odczytuje tablice od tylu i wypisuje poszczegolne elementy
            break; }
        case 2: { // bin na dzies
            int suma = 0, i=0, numer;
            cout << "Podaj liczbe do zamiany" << endl;
            cin >> numer;
            while (numer > 0){
                if(numer %2 ==1){ // sprawdzamy, czy bit jest 0 czy 1
                    suma += (1 * pow(2, i)); // dodaje 2 do potegi pozycji bitu jesli bit jest rowny 1, inaczej ignoruj
                }
                numer /= 10; // dzielenie przez 10 pozwala na przejscie do kolejnego bitu
                i++;
            }
            cout << suma << endl; // wypisz sume
            break; }
        default: {// jesli uzytkownik wpisze niepoprawna liczbe
            cout << "Podales zla liczbe" << endl; 
            break; }
    }
    return 0;
}
