#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b;
    cout << "Podaj a:" << endl;
    cin >> a;
    cout << "Podaj b:" << endl;
    cin >> b;
    // Obliczenia w wypisywaniu znakow
    cout << "Suma: " << a+b << endl;
    cout << "Roznica: " << a-b << endl;
    cout << "Iloczyn: " << a*b << endl;
    if (b == 0) cout << "Nie dziel przez 0" << endl; // Sprawdza, czy mianownik jest zerem i wypisuje blad jesli tak
    else cout << "Iloraz: " << a/b << endl;
    return 0;
}