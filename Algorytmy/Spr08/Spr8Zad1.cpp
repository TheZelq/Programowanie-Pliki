#include <iostream>
using namespace std;

int dzielenie(int tab[], int a, int b){
    int r = tab[a];
    int i = a-1, j = b+1; 
    while (true) {
        // szukamy elementu najbardziej na lewo, który jest mniejszy od wybranego elementu
        do {
            i++;
        } while (tab[i] < r);
        // szukamy elementu najbardziej na prawo, który jest równy lub większy od wybranego elementu
        do { 
            j--;
        } while (tab[j] > r);
        // jeśli oba z elementów są sobie równe
        if (i >= j) return j;
        swap(tab[i], tab[j]);
    }
}

void sortQuick(int tab[], int a, int b){ 
    // funkcja Quick Sort jest funkcją rekurencyjną i ma na celu wyznaczanie coraz mniejszych części danej tablicy do posorotwania jak najbliższych sobie elementów
    // wyznaczamy granicę, a potem dana granica dzieli przedział na 2 części, na których znowu wykonujemy sortowanie
    // jesli nie da sie wykonac sortowania, to idzie dalej, konczy sie gdy wszystkie elementy sa posortowane
    int r;
    if (a<b) {
        r = dzielenie(tab, a, b);
        sortQuick(tab, a, r);
        sortQuick(tab, r+1, b); 
    }
}

int main(){
    int k, n = 10; // pozycja
    int tab[n] {67, 32, 23, 75, 9, 15, 40, 20, 5, 58}; //deklaracja tablicy
    cout << "Którego elementu szukasz?" << endl; // wypisywanie elementow po sortowaniu
    cin >> k;
    if (k>10) cout << "Element wykracza poza zakres.";
    else if (n==1) cout << tab[0];
    else {
        sortQuick(tab, 0, n-1); // wykonywanie funkcji sortujacej, ktora nic nie zwraca (dlatego jest typu void)
        cout << tab[k-1];
    }
    return 0;
}
