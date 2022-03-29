#include <iostream>
using namespace std;

int rek(int a) {
    if (a==0 || a==1) return 1; //zwraca wartość fixed "1" dla a == 0 lub 1 (również po rekurencji)
    return rek(a-1)*a; // rekurencyjnie, czyli wywołuje samą siebie
}

int iter(int a) {
    int liczba = 1;
    for (int i = 1; i<=a; i++){
        liczba *= i;
    }
    return liczba; // iteracyjnie, czyli wykorzystuje dodatkową zmienną do wykonania pętli
}

int main() {
    int x;
    cout << "Podaj liczbe" << endl;
    cin >> x;
    cout << rek(x) << endl;
    cout << iter(x) << endl;
    return 0;
}