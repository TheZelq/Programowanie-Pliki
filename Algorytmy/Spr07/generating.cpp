#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void generowanie(string rodzaj){
    srand(time(NULL));
    ofstream file;
    const int dlugosc = 50000; // to edytuje recznie (wielkosc zbioru)
    int tab[dlugosc];
    //tworzenie pliku
    file.open("/Users/szymw/OneDrive/Pulpit/Dane"+rodzaj+to_string(dlugosc)+".txt");
    //czesc optymistyczna
    if (rodzaj == "opt") {
        for (int j=0; j<dlugosc; j++){
            if (j <= dlugosc/2) tab[j] = j;
            else tab[j] = rand() % dlugosc;
            file << tab[j] << " ";
        }
    }
    //czesc losowa
    else if (rodzaj == "los"){
        for (int j=0; j<dlugosc; j++){
            tab[j] = rand() % dlugosc;
            file << tab[j] << " ";
        }
    }
    //czesc pesymistyczna
    else {
        for (int j = 0; j<dlugosc; j++){
            tab[j] = dlugosc - j - 1;
            file << tab[j] << " ";
        }
    }
    file.close();
}
int main(){
    generowanie("opt");
    generowanie("los");
    generowanie("pes");
    return 0;
}