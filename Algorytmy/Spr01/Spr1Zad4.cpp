#include <iostream>
using namespace std;

int potega(int a, int b) {
    int liczba = a;
    if (b==0) liczba = 1; //jesli potega to 0, to program wypisze 1
    else {  //program liczy w petli tak dlugo az dojdzie do wartosci potegi
        for (int i=1; i<b; i++) {
        liczba = liczba*a;
        }
    }
    return liczba;
}

int main() {
    int x, y;
    cout << "Podaj liczbe" << endl;
    cin >> x;
    cout << "Podaj potege" << endl;
    cin >> y;
    cout << potega(x, y) << endl;
    return 0;
}