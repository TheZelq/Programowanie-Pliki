#include <iostream>
#include <cstring>
using namespace std;

void sortBab(int tab[]){ 
    // funkcja babelkowa polega na sortowaniu od pierwszego elementu sprawdzajac poszczegolne elementy na prawo od niego 
    // jesli element na prawo jest od niego wiekszy, to zamienia sie miejscami
    // jesli nie da sie wykonac wiecej sortowan, to funkcja sie konczy
    int licznik, pomoc;
    for (int i=0; i<9; i++) { // petla zewnetrzna
        licznik = 0; // licznik/reset licznika do weryfikacji zakonczenia funkcji
        for (int j=0; j<9-i; j++) { // petla wewnetrzna
            if (tab[j] > tab[j+1]) { // zamiana wartosci przy danym warunku
                pomoc = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = pomoc;
                licznik++; // zwiekszenie licznika w
            }
        }
        if (licznik == 0) return; // koniec funkcji przy braku zmian w tablicy
    }
}

int main(){
    int tab[10] {67, 32, 23, 75, 9, 15, 40, 20, 5, 58}; // deklaracja tablicy
    cout << "Przed sortowaniem" << endl;
    for (int i=0; i<=9; i++) cout << tab[i] << " "; // wypisywanie elementow przed sortowaniem
    cout << endl << "Po sortowaniu babelkowym" << endl;
    sortBab(tab); // wykonywanie funkcji sortujacej, ktora nic nie zwraca (dlatego jest typu void)
    for (int i=0; i<=9; i++) cout << tab[i] << " "; // wypisywanie elementow po sortowaniu
    return 0;
}
