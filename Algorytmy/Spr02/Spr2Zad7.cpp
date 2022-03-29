#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a;
    cout << "Sprawdz pierwszosc liczby:" << endl;
    cin >> a;
    for (int i=2; i<a; i++){ // petla ktora bedzie sprawdzala czy dana liczba jest podzielna przez kolejne liczby naturalne zaczynajac od 2
        if (a%i==0) {
            cout << "Liczba nie jest pierwsza" << endl; // zwraca ze nie jest pierwsza i konczy program 
            return 0;
        }
    }
    cout << "Liczba jest pierwsza" << endl; //zwraca ze jest pierwsza i konczy program
    return 0;
}