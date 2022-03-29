#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cout << "Podaj bok a:" << endl;
    cin >> a;
    cout << "Podaj bok b:" << endl;
    cin >> b;
    cout << "Podaj bok c:" << endl;
    cin >> c;
    if (a+b>c && b+c>a && a+c>b){ // sprawdzamy czy mozna utworzyc trojkat (zaden bok nie moze byc dluzszy niz pozostale 2)
        double pole, ob; // tworzymy nowe zmienne do wyliczenia pola/obwodu
        ob = a+b+c; // wzor na pole trojkata
        pole = sqrt((ob/2)*(ob/2-a)*(ob/2-b)*(ob/2-c)); // obliczamy pole ze wzoru bazujacego na obwodzie
        cout << "Pole: " << pole << endl;
        cout << "Obwod: " << ob << endl;
    }
    else cout << "Nie da sie utworzyc takiego trojkata." << endl; // wiadomosc zwrotna jesli nie da sie wyliczyc trojkata
    return 0;
}