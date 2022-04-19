#include <iostream>
using namespace std;

int dzielenie(int tab[], int a, int b){ //funkcja do wyznaczenia granicy
    int piwot = tab[b]; // piwotem będzie wartość ostatniego elementu danego przedziału
    int gran = a; // początkową granicą jest numer pozycji pierwszego elementu przedziału
    for (int i=a; i<b; i++){
        if (tab[i] < piwot){ // jeśli piwot jest większy od wartości elementu tablicy to zamienia liczby między elementem końcowym a tym mniejszym
            int pomoc = tab[i];
            tab[i] = tab[gran];
            tab[gran] = pomoc;
            gran++; // zwiększa numer pozycji granicy o 1
        }
    }
    int pomoc = tab[b];
    tab[b] = tab[gran];
    tab[gran] = pomoc; // zamiana wartości między piwotem, a wartością z pozycji granicy 
    return gran;   
}

void sortQuick(int tab[], int a, int b){ 
    // funkcja Quick Sort jest funkcją rekurencyjną i ma na celu wyznaczanie coraz mniejszych części danej tablicy do posorotwania jak najbliższych sobie elementów
    // wyznaczamy granicę, a potem dana granica dzieli przedział na 2 części, na których znowu wykonujemy sortowanie
    // jesli nie da sie wykonac sortowania, to idzie dalej, konczy sie gdy wszystkie elementy sa posortowane
    int pomoc;
    if (a<b) {
        pomoc = dzielenie(tab, a, b);
        sortQuick(tab, a, pomoc - 1);
        sortQuick(tab, pomoc+1, b); 
    }
}

int main(){
    int tab[10] {67, 32, 23, 75, 9, 15, 40, 20, 5, 58}; // deklaracja tablicy
    cout << "Przed sortowaniem" << endl;
    for (int i=0; i<=9; i++) cout << tab[i] << " "; // wypisywanie elementow przed sortowaniem
    cout << endl << "Po sortowaniu QuickSort" << endl;
    sortQuick(tab, 0, 9); // wykonywanie funkcji sortujacej, ktora nic nie zwraca (dlatego jest typu void)
    for (int i=0; i<=9; i++) cout << tab[i] << " "; // wypisywanie elementow po sortowaniu
    return 0;
}
