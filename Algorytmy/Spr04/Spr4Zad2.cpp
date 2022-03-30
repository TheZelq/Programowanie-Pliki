#include <iostream>
#include <cstring>
using namespace std;

void sortWst(int tab[]){
    // funkcja sortowania przez wstawianie polega na sortowaniu od drugiego elementu sprawdzajac czy elementy przed nim nie sa wieksze
    // jesli element po prawo jest mniejszy, to przesuwa sie w lewo, a petla wewnetrzna sie konczy gdy element po prawej stronie bedzie wiekszy
    // po przejsciu przez wszystkie elementy funkcja sie konczy
    int pomoc, j;
    for(int i=1; i<10; i++) { // petla zewnetrzna
        pomoc = tab[i]; // nadanie wartosci pomocniczej wartosci tab[i]
        j = i-1; // j to iteracja pozycji liczby na lewo od i
        while(j>=0 && tab[j]>pomoc){ // przesuwa pod okreslonym warunkiem
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = pomoc;
    }     
}

int main(){
    int tab[10] {67, 32, 23, 75, 9, 15, 40, 20, 5, 58}; // deklaracja tablicy
    cout << "Przed sortowaniem" << endl;
    for (int i=0; i<=9; i++) cout << tab[i] << " "; // wypisywanie elementow przed sortowaniem
    cout << endl << "Po sortowaniu przez wstawianie" << endl;
    sortWst(tab); // wykonywanie funkcji sortujacej, ktora nic nie zwraca (dlatego jest typu void)
    for (int i=0; i<=9; i++) cout << tab[i] << " "; // wypisywanie elementow po sortowaniu
    return 0;
}
