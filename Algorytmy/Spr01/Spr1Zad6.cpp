#include <iostream>
#include <cmath>
using namespace std;
int tablica [5] = {2, 6, 9, 3, 10}; // deklaracja tablicy

int najw(int tab[]) {
    int zmienna = tab[0];
    for (int i=0; i<5; i++){
        if(tablica[i]>zmienna) zmienna = tablica[i]; // podmienia wartosc najwieksza jesli nowa wartosc z tablicy jest wieksza
    }
    return zmienna;
}

int najm(int tab[]) {
    int zmienna = tab[0];
    for (int i=0; i<5; i++){
        if(tablica[i]<zmienna) zmienna = tablica[i]; // podmienia wartosc najmniejsza jesli nowa wartosc z tablicy jest mniejsza
    }
    return zmienna;
}

bool czyTrzy(int tab[]){
    int zmienna;
    for (int i=0; i<5; i++){
        if(tablica[i]%3==0) zmienna++; // sprawdza po modulo podzielnosc przez 3
    }
    if (zmienna==0) return 0;
    else return 1;
}

int iloscTrzy(int tab[]){
    int zmienna=0;
    for (int i=0; i<5; i++){
        if(tablica[i]%3==0) zmienna=zmienna+1; // liczy ilosc liczb podzielnych przez 3
    }
    return zmienna;
}

int suma(int tab[]){
    int zmienna;
    for (int i=0; i<5; i++){
        zmienna += tablica[i]; // sumuje elementy tablicy
    }
    return zmienna;
}

int main() {
    int n;
    do {
        cout << "Podaj indeks od 0 do 4" << endl;
        cin >> n;
    } while (4<n<0);
    cout << najw(tablica) << endl; // kazda z funkcji jest wykonywana w osobnych funkcjach poza mainem
    cout << najm(tablica) << endl;
    cout << abs(najw(tablica)-najm(tablica)) << endl;  // rozrzut to bezwzgledna roznica miedzy wartosciami skrajnymi
    cout << suma(tablica)/5 << endl; // srednia arytmetyczna to suma wartosci podzielone przez ich ilosc;
    cout << suma(tablica) << endl;
    cout << sqrt(suma(tablica)/5) << endl; // wzor na odchylenie to pierwiastek sredniej
    cout << czyTrzy(tablica) << endl;
    if (czyTrzy(tablica)) cout << iloscTrzy(tablica) << endl; //wykonuje tylko jesli znajduja sie liczby podzielne przez 3;
    cout << tablica[n] << endl;
    return 0;
}