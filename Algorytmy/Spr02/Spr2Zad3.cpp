#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a;
    cout << "Dlugosc fibonacciego" << endl;
    cin >> a;
    int x = 0, y = 1; // pierwsze 2 elementy fib
    for (int i=0; i<a; i++) {
        cout << y << " ";
        y += x; // podstawia wartosc zmiennej y jako y+x
        x = y-x; // zamienia wartosc x na nowa wartosc rowna stara y;
    }
    return 0;
}