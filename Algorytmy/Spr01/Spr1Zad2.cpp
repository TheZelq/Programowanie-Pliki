#include <iostream>
using namespace std;

int nwd(int a, int b) {
    int pomoc; //wyliczam nwd wspomagając się dodatkową zmienną pomocniczą
    while(b!=0) { //i wykorzystującą modulo między liczbami
        pomoc = b;
        b = a%b;
        a = pomoc;
    }
    return a;
}

int nww(int a, int b) {
    return a/nwd(a, b)*b; //wykorzystuję wzór na wyliczenie nww znając nwd
}

int main() {
    int x, y;
    cout << "Podaj pierwsza liczbe" << endl;
    cin >> x;
    cout << "Podaj druga liczbe" << endl;
    cin >> y;
    cout << nww(x, y) << endl;
    cout << nwd(x, y) << endl;
    return 0;
}