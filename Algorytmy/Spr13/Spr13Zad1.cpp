#include <iostream>
#include <string>
using namespace std;

string szyfrowanie(string haslo){ // proces szyfrowania
    string wynik;
    for (int i=0; i<haslo.length(); i++){ // dziala tyle razy jak dlugie jest haslo
        if (haslo[i]>='a' && haslo[i]<='z') wynik += (haslo[i]+3-'a') % 26 + 'a'; // dla malych liter (26 poniewaz jest tyle liter w alfabecie w kodzie ascii)
        else if (haslo[i]>='A' && haslo[i]<='Z') wynik += (haslo[i]+3-'A') % 26 + 'A'; // i dla duzych
        else wynik += haslo[i]; // dla znakow specjalnych i cyfr
    }
    return wynik;    
}

string deszyfrowanie(string haslo){ // proces odwrotny do szyfrowania
    string wynik;
    for (int i=0; i<haslo.length(); i++){
        if (haslo[i]>='a' && haslo[i]<='z'){
            int a = int(haslo[i]-3-'a');
            if (a<0) a+=26;
            wynik += char(a+'a');
        }
        else if (haslo[i]>='A' && haslo[i]<='Z'){
            int a = int(haslo[i]-3-'A');
            if (a<0) a+=26;
            wynik += char(a+'A');
        }
        else wynik += haslo[i];
    }
    return wynik;
}

int main(){
    string haslo;
    int opcja;
    cout << "Szyfrowanie Cezara\nCzy chcesz zaszyfrowac (1) czy odszyfrowac (2)? ";
    cin >> opcja;
    switch(opcja){
        case 1:
        cout << "Podaj haslo do zaszyfrowania: ";
        cin >> haslo;
        cout << "Oto zaszyfrowane haslo: "+szyfrowanie(haslo);
        break;

        case 2:
        cout << "Podaj haslo do odszyfrowania: ";
        cin >> haslo;
        cout << "Oto odszyfrowane haslo: "+deszyfrowanie(haslo);;
        break;

        default:
        cout << "Niepoprawna wartosc";
        break;
    }
    return 0;
}