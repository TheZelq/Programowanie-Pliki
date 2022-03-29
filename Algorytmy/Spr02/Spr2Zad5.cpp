#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int licznik = 1, a = 0; // ustawiamy licznik na 1, a a na 0 tymczasowo, bo bedzie zamieniona na wartosc wpisywana przez uzytkownika
    srand(time(NULL));
    int n = rand() % 15 + 1; // ograniczenie przedzialu losowanej liczby
    do {
        cout << "Zgadnij liczbe od 1 do 15:" << endl;
        cin >> a;
        if (a>n){ // jesli uzytkownik wpisal za duza 
            cout << "Wygenerowana liczba jest mniejsza" << endl;
            licznik++; // sprawdza licznik
        }
        if (a<n){ // jesli uzytkownik wpisal za mala
        cout << "Wygenerowana liczba jest wieksza" << endl;
        licznik++; // sprawdza licznik
        }
    } while (a!=n); // wykonuje tak dlugo az liczba wpisana przez uzytkownika jest rowna tej wygenerowanej
    cout << "Odgadles liczbe! Liczba prob: " << licznik << endl;
    return 0;
}