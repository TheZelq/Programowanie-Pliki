#include <iostream>
#include <string>
using namespace std;

string szyfrowanie(string haslo, string klucz){
    string wynik;
    char znaki[32]={'a','¥','b','c','†','d','e','©','f','g','h','i','j','k','l','ˆ','m','n','ä','o','¢','p','r','s','˜','t','u','w','y','z','«','¾'};
    int kluczliczby[100];
    for (int i=0; i<klucz.length(); i++){
        for (int j=0; j<32; j++){
            if (klucz[i]==znaki[j]) kluczliczby[i]=j;
        }
    }
    for (int i=0; i<haslo.length(); i++){
        for (int j=0; j<32; j++){
            if (haslo[i]==znaki[j]) wynik += znaki[j^kluczliczby[i%klucz.length()]];
        }
    }
    return wynik;
}

int main(){
    string haslo, klucz;
    cout << "Podaj haslo do zaszyfrowania: ";
    cin >> haslo;
    cout << "Podaj klucz: ";
    cin >> klucz;
    cout << "Oto haslo: "+szyfrowanie(haslo, klucz);    
    return 0;
}