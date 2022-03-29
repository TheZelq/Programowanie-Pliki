#include <iostream>
using namespace std;

int main(){
    cout << "Liczby doskonale: przedzial <2,30>: " << endl;
    for (int i = 2;  i <= 30; i++) { // petla sprawdza po kolei liczby od 2 do 30
        int suma = 0;
        for (int j = 1; j < i; j++) { // petla ktora dziala tak dlugo az dojdzie do wartosci rownej liczbie
            if(i%j==0) suma += j; // dodaje do sumy wszystkie podzielniki danej liczby
        }
        if(suma == i){ // wypisuje dana liczbe jesli suma jest rowna liczbie
            cout << i << " "; // oddziela liczby doskonale spacja
        }
    }
    cout << endl;
    return 0;
}
