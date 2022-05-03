#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void sortBab(int tab[], int dlugosc){ 
    // funkcja babelkowa polega na sortowaniu od pierwszego elementu sprawdzajac poszczegolne elementy na prawo od niego 
    // jesli element na prawo jest od niego wiekszy, to zamienia sie miejscami
    // jesli nie da sie wykonac wiecej sortowan, to funkcja sie konczy
    int licznik, pomoc;
    for (int i=0; i<dlugosc-1; i++) { // petla zewnetrzna
        licznik = 0; // licznik/reset licznika do weryfikacji zakonczenia funkcji
        for (int j=0; j<dlugosc-i; j++) { // petla wewnetrzna
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

void sortWst(int tab[], int dlugosc){
    // funkcja sortowania przez wstawianie polega na sortowaniu od drugiego elementu sprawdzajac czy elementy przed nim nie sa wieksze
    // jesli element po prawo jest mniejszy, to przesuwa sie w lewo, a petla wewnetrzna sie konczy gdy element po prawej stronie bedzie wiekszy
    // po przejsciu przez wszystkie elementy funkcja sie konczy
    int pomoc, j;
    for(int i=1; i<dlugosc; i++) { // petla zewnetrzna
        pomoc = tab[i]; // nadanie wartosci pomocniczej wartosci tab[i]
        j = i-1; // j to iteracja pozycji liczby na lewo od i
        while(j>=0 && tab[j]>pomoc){ // przesuwa pod okreslonym warunkiem
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = pomoc;
    }     
}

void zamiana(int &a, int &b){ // podmianka uzywajac adresow zmiennych
    int pomoc;
    pomoc = a;
    a = b;
    b = pomoc;
}

void sortSel(int *tab, int dlugosc){ 
    // funkcja Selection Sort ma na celu wybranie najmniejszego elementu z nieposortowanego ciagu i zamienia go z pierwszy elementem tego ciagu
    // co petle ciag posortowany zwieksza sie o 1, a nieposortowany zmiejsza sie
    // jesli nie da sie wykonac sortowania, to idzie dalej, konczy sie gdy wszystkie elementy sa posortowane
    int licznik, pozycja;
    for (int i=0; i<dlugosc-1; i++) { // petla zewnetrzna
        int pozycja = i;
        for (int j=i+1; j<dlugosc; j++) { // petla wewnetrzna
            if (tab[j]<tab[pozycja]){ // jesli wartosc danej pozycji jest mniejsza niz aktualnie najmniejsza wartosc
                pozycja = j;
            }
        }   
        zamiana(tab[i], tab[pozycja]); // kolejna funkcja ktora zamienia dane wartosci opisane wyzej
    }
}

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

void sortowanie(string rodzaj, string opt){
    int dlugosc = 50000; // to edytuje recznie (wielkosc zbioru)
    int tab[dlugosc];
    int i = 0;
    if (rodzaj == "opt") {
        for (int j=0; j<dlugosc; j++){
            if (j <= dlugosc/2) tab[j] = j;
            else tab[j] = rand() % dlugosc;
        }
    }
    //czesc losowa
    else if (rodzaj == "los"){
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
    if (opt == "bab") sortBab(tab, dlugosc);
    //przez wstawianie
    else if (opt == "ins") sortWst(tab, dlugosc);
    //przez selekcje
    else if (opt == "sel") sortSel(tab, dlugosc);
    //szybkie
    else if (opt == "qui") sortQuick(tab, 0, dlugosc-1);
    //przez merge
    else if (opt == "mer") sortMerge(tab, 0, dlugosc-1);
}

int main(){
    string opt;
    clock_t start, koniec;
    int wyniki[5];
    double srednia;
    cout << "Podaj metode sortowania do mierzenia:\n";
    cin >> opt;
    for (int i=0; i<5; i++){
        start = clock();
        sortowanie("pes", opt);
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
        sortowanie("opt", opt);
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
        sortowanie("los", opt);
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