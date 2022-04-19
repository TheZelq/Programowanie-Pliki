#include <iostream>
using namespace std;

void zamiana(int &a, int &b){ // podmianka uzywajac adresow zmiennych
    int pomoc;
    pomoc = a;
    a = b;
    b = pomoc;
}

void sortSel(int *tab){ 
    // funkcja Selection Sort ma na celu wybranie najmniejszego elementu z nieposortowanego ciagu i zamienia go z pierwszy elementem tego ciagu
    // co petle ciag posortowany zwieksza sie o 1, a nieposortowany zmiejsza sie
    // jesli nie da sie wykonac sortowania, to idzie dalej, konczy sie gdy wszystkie elementy sa posortowane
    int licznik, pozycja;
    for (int i=0; i<9; i++) { // petla zewnetrzna
        int pozycja = i;
        for (int j=i+1; j<10; j++) { // petla wewnetrzna
            if (tab[j]<tab[pozycja]){ // jesli wartosc danej pozycji jest mniejsza niz aktualnie najmniejsza wartosc
                pozycja = j;
            }
        }   
        zamiana(tab[i], tab[pozycja]); // kolejna funkcja ktora zamienia dane wartosci opisane wyzej
    }
}

int main(){
    int tab[10] {67, 32, 23, 75, 9, 15, 40, 20, 5, 58}; // deklaracja tablicy
    cout << "Przed sortowaniem" << endl;
    for (int i=0; i<=9; i++) cout << tab[i] << " "; // wypisywanie elementow przed sortowaniem
    cout << endl << "Po sortowaniu selekcyjnym" << endl;
    sortSel(tab); // wykonywanie funkcji sortujacej, ktora nic nie zwraca (dlatego jest typu void)
    for (int i=0; i<=9; i++) cout << tab[i] << " "; // wypisywanie elementow po sortowaniu
    return 0;
}
