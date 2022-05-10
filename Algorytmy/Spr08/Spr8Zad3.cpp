#include <iostream>
#include <fstream>
#include <sstream>
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

int mediana(int tab[], int a, int b) {
    int licznik = 1, mediana = a, pomoc;
    while (licznik != 0) { // wykorzystuję sortowanie bąbelkowe
        licznik = 0; // licznik/reset licznika do weryfikacji zakonczenia funkcji
        for (int i = mediana; i<b; i++) {
            if (tab[i] > tab[i+1]) { // zamiana wartosci przy danym warunku
                pomoc = tab[i+1];
                tab[i+1] = tab[i];
                tab[i] = pomoc;
                licznik++; // zwiekszenie licznika w
            }
        }
    }
    int liczba = b - a;
    liczba = liczba/2 + 1;
    mediana = tab[a + liczba];
    return mediana;
}

void medianOfMedians(int tab[], int a, int b, int ktora) {
    int pomoc = b + 1; // pomoc to ilość elementów w głównej tablicy
    int x = pomoc / 5; // x to liczba elementów (median), które zostaną dodane do podtablicy
    int y = pomoc % 5; // y to rozmiar najmniejszej "piątki"
    int i = 0;
    if (y != 0) x++; // jeśli jest jakaś reszta to doda kolejny slot dla y elementów 
    int* tabM = new int[x]; // tworzy nową dynamiczną tablicę
    if (y != 0) {
        x--; // wracamy do wartości równej ilości pełnych "piątek"
        tabM[i] = mediana(tab, x, x + y);
        i++;
    }
    int zmienna = x-1, licznik = 0;
    for (zmienna; zmienna >= 0; zmienna--) {
        pomoc = 5 * zmienna;
        tabM[licznik] = mediana(tab, pomoc, pomoc + 4); // do mniejszej tablicy podajemy wartości danych median
        licznik++; // licznik
    }
    int r = mediana(tabM, 0, i - 1); // ustawienie naszego piwotu
    x = 0;
    for (i = 0; i <= b; i++) { // sprawdzenie indeksu piwotu
        if (tab[i] <= r) x++;
    }   
    i = 0; 
    int j = b;
    while (i < j) {
        // szukamy elementu najbardziej na lewo, który jest mniejszy od wybranego elementu
        if (tab[i] <= r) i++;
        // szukamy elementu najbardziej na prawo, który jest równy lub większy od wybranego elementu
        if (tab[j] > r) j--;
        swap(tab[i], tab[j]);
    }
    if (ktora < x) sortQuick(tab, a, x - 1); // w zależności od miejsca piwota, wykonuje odpowiednie funkcje
    else if (ktora == x) tab[b] = r;
    else sortQuick(tab, x + 1, b);
}

void sortowanie(string rodzaj, string opt, int ktora){
    int dlugosc = 10000; // to edytuje recznie (wielkosc zbioru)
    int tab[dlugosc];
    int i = 0;
    //czesc losowa
    if (rodzaj == "los"){
        for (int j=0; j<dlugosc; j++){
            tab[j] = rand() % dlugosc;
        }
    }
    //czesc pesymistyczna
    else if (rodzaj == "pes"){
        for (int j = 0; j<dlugosc; j++){
            tab[j] = dlugosc - j - 1;
        }
    }
    //babelkowe
    if (opt == "hoa") sortQuick(tab, 0, dlugosc-1);
    //przez wstawianie
    else if (opt == "mom") medianOfMedians(tab, 0, dlugosc-1, ktora);
}

int main(){
    string opt;
    clock_t start, koniec;
    double wyniki[5], liczba;
    double srednia;
    cout << "Podaj metode sortowania do mierzenia:\n";
    cin >> opt;
    cout << "Podaj ktora liczba:\n";
    cin >> liczba;
    for (int i=0; i<5; i++){
        start = clock();
        sortowanie("pes", opt, liczba);
        koniec = clock();
        wyniki[i] = koniec-start;
    }
    for (int i=0; i<5; i++){
        cout << wyniki[i] << " ";
        srednia += wyniki[i];
    }
    cout << "srednia: " << srednia/5;
    cout << "\n";
    srednia = 0;
    for (int i=0; i<5; i++){
        start = clock();
        sortowanie("los", opt, liczba);
        koniec = clock();
        wyniki[i] = koniec-start;
    }
    for (int i=0; i<5; i++){
        cout << wyniki[i] << " ";
        srednia += wyniki[i];
    }
    cout << "srednia: " << srednia/5;
    return 0;
}