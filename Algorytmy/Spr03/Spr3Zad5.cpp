#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string slowo; //deklaracja ciagu znakow
    int len, nie=0;
    cout << "Podaj ciag znakow" << endl;
    cin >> slowo;
    len = slowo.length(); // nadanie zmiennej len wartosci dlugosci tablicy
    char tablica[len]; // deklaracja tablicy
    strcpy(tablica, slowo.c_str()); // funkcja strcpy pozwala zamienic stringa na tablice
    for (int i = 0; i < len; i++) {
        if(tablica[i] != tablica[len-i-1]) nie++; // jesli sie roznia, to dodaje do wartosci nie, ktora determinuje efekt koncowy kodu
    }
    if (nie == 0){ // jesli nie bylo problemu i wartosci byly sobie rowne
        cout << "Palindrom" << endl;
    } else cout << "Nie-palindrom" << endl;
    return 0;
}
