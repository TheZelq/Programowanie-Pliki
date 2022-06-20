#include <iostream>
#include <string>
using namespace std;

string przestawianie(string haslo){ // funkcja na przestawianie
    string wynik;
    int a;
    if (haslo.length()%2!=0) a = haslo.length()-1; // (jesli dlugosc hasla jest nieparzysta to nie wykonujemy na ostatniej literze operacji)
    else a = haslo.length();
    for (int i=0; i<a; i++) {
        if (i%2==0){ // co pare przestawiamy litery miedzy soba
            int x = haslo[i];
            haslo[i] = haslo[i+1];
            haslo[i+1] = x;
        }
        wynik += haslo[i];
    }
    if (haslo.length()%2!=0) wynik += haslo[haslo.length()-1]; // odpowiednio dodajemy ostatnia litere jesli haslo ma nieparzysta dlugosc
    return wynik;
}

int main(){
    string haslo;
    cout << "Podaj haslo do zaszyfrowania/odszyfrowania: ";
    cin >> haslo;
    cout << "Oto haslo: "+przestawianie(haslo);
    return 0;
}