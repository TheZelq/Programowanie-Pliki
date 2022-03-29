#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, z;
    cout << "Podaj liczbe x" << endl;
    cin >> x;
    cout << "Podaj liczbe y" << endl;
    cin >> y;
    cout << "Podaj liczbe z" << endl;
    cin >> z;
    cout << -y/x << endl; // liczy rozwiazanie rownania liniowego
    int delta = y*y -(4*x*z);
    if (delta < 0) {
        cout << "Brak rozw" << endl; // wypisuje brak rozwiazan jesli delta < 0
        return 0;
    }
    if (delta == 0) {
        cout << "x =" << -y/(2*x) << endl; // rozwiazanie dla delty == 0
        return 0;
    }
    else {
        cout << "x_1 =" << -y-sqrt(delta)/(2*x) << endl;
        cout << "x_1 =" << -y+sqrt(delta)/(2*x) << endl; // rozwiazania dla delty > 0
    }
    return 0;
}