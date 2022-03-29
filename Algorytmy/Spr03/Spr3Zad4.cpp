#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double srednia = 0; // zmienna na srednia (double dla ulamkow)
    int i = 0;
    cout << i << endl;
    double elementy[2][4]; // tablica wielowymiarowa 2x4(dla 4 liczb w sredniej)
    do {
        cout << "Podaj " << i+1 << " liczbe do sredniej" << endl;
        cin >> elementy[0][i]; // daje wartosci do pierwszego wiersza tablicy
        cout << "Podaj wage " << i+1 << " liczby do sredniej" << endl;
        cin >> elementy[1][i]; // daje wartosci do drugiego wiersza tablicy
        i++; // iteracja
    } while(i<4);
    for (int j=0; j<4; j++) {
        srednia += elementy[0][j]*elementy[1][j]; // mnozymy liczbe przez jej wage
    }
    srednia /= 4; // dzielimy przez ilosc elementow
    cout << "Srednia wazona: " << srednia << endl;
    return 0;
}
