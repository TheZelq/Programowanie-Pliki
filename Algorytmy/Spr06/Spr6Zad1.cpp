#include <iostream>
using namespace std;

void merge(int tab[], int a, int pomoc, int b){ //funkcja do laczenia tablic wraz z sortowaniem
    int len1 = pomoc - a + 1; // liczenie dlugosci obu mniejszych tablic
    int len2 = b - pomoc;
    int tab1[len1], tab2[len2]; // tworzenie nowych tablic
    for (int i=0; i<len1; i++) tab1[i] = tab[a+i]; // wpisywanie wartosci do tabel
    for (int i=0; i<len2; i++) tab2[i] = tab[pomoc+i+1];
    int p = 0, q = 0, r = a; // tworzenie iteracji
    while (p < len1 && q < len2){
        if (tab1[p] > tab2[q]){ // jesli wartosc po lewej jest wieksza niz wartosc po prawej
            tab[r] = tab2[q];
            q++;
        } else { // w przeciwnym wypadku
            tab[r] = tab1[p];
            p++;
        }
        r++;
    }
    while (p < len1){ // w razie czego sprawdzenie czy nie zostaly jakies wartosci w jakiejs z tabel, gdy ta druga zostala zakonczona
        tab[r] = tab1[p];
        p++, r++;
    }
    while (q < len2){
        tab[r] = tab2[q];
        q++, r++;
    }

}

void sortMerge(int tab[], int a, int b){ 
    // funkcja Merge Sort jest funkcją rekurencyjną i ma na celu wyznaczanie coraz mniejszych części danej tablicy 
    // do tego wykorzystujemy tzw. wartowników; po tym jak już odpowiednio podzielimy tablicę to dokonujemy fuzji (merge)
    // jesli element z pierwszej tabeli jest wiekszy od drugiej to do glownej tablicy nadpisujemy nowa wartosc
    // na danej pozycji rownej wartosci na danej pozycji mnejszej tablicy
    if (a<b) {
        int pomoc = a + (b-a)/2;  // szukamy srodka
        sortMerge(tab, a, pomoc); // wykonujemy rekurencje dla jednej polowy
        sortMerge(tab, pomoc+1, b); // i dla drugiej
        merge(tab, a, pomoc, b); // dokonujemy fuzji
    }
}

int main(){
    int x; // dlugosc tablicy
    cout << "Podaj ilość elementów tablicy" << endl;
    cin >> x;
    int tab[x]; // deklaracja tablicy
    for (int i=0; i<x; i++) cin >> tab[i]; // wpisywanie poszczególnych elementów do tablicy
    cout << "Przed sortowaniem" << endl;
    for (int i=0; i<x; i++) cout << tab[i] << " "; // wypisywanie elementow przed sortowaniem
    cout << endl << "Po sortowaniu MergeSort" << endl;
    sortMerge(tab, 0, x-1); // wykonywanie funkcji sortujacej, ktora nic nie zwraca (dlatego jest typu void)
    for (int i=0; i<x; i++) cout << tab[i] << " "; // wypisywanie elementow po sortowaniu
    return 0;
}
