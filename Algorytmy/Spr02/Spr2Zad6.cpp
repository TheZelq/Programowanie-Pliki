#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a1, a2, b1, b2, c1, c2, wg, wx, wy;
    cout << "Podaj wsp a1:" << endl;
    cin >> a1;
    cout << "Podaj wsp a2:" << endl;
    cin >> a2;
    cout << "Podaj wsp b1:" << endl;
    cin >> b1;
    cout << "Podaj wsp b2:" << endl;
    cin >> b2;
    cout << "Podaj wsp c1:" << endl;
    cin >> c1;
    cout << "Podaj wsp c2:" << endl;
    cin >> c2;
    wg = a1*b2 - b1*a2; // Wzor na wyznacznik glowny
    wx = c1*b2 - b1*c2; // Wzory na wyznaczniki x i y
	wy = a1*c2 - c1*a2;
    if (wg==0){ // Sprwadza wyznacznik glowny
        if (wx==0 && wy==0){ // Jesli wszystkie wyznaczniki sa 0
            cout << "Tozsamosciowy" << endl;
        }
        else cout << "Sprzeczny" << endl; // Jesli glowny jest 0 i jakis z innych nie jest 0
    }
    else cout << "x = " << wx/wg << endl << "y = " << wy/wg << endl; // dzieli poszczegolne wyznaczniki przez wyznacznik glowny i wypisuje
    return 0;
}