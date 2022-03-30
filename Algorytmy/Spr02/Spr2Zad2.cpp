#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int macierzA[2][2] {{2, 4}, {3, 1}}, macierzB[2][2] {{1, 6}, {4, 5}}; // ustalone wczesniej macierze
    int wyznacznikA = macierzA[0][0] * macierzA[1][1] - macierzA[1][0] * macierzA[0][1]; // liczenie wyznacznika macierzy
    int wyznacznikB = macierzB[0][0] * macierzB[1][1] - macierzB[1][0] * macierzB[0][1];
    cout << "Wyz A " << wyznacznikA << endl;
    cout << "Wyz B " << wyznacznikB << endl; // wyswietlenie wyznacznikow
    // obliczenie mnozenia macierzy poprzez tworzenie nowej macierzy C, ktorej elementy sa liczone odpowiednio ze wzoru
    int macierzC[2][2];
    cout << "Macierz C" << endl;
    macierzC[0][0] = macierzA[0][0]*macierzB[0][0] + macierzA[0][1]*macierzB[1][0];
    macierzC[1][0] = macierzA[1][0]*macierzB[0][0] + macierzA[1][1]*macierzB[1][0];
    macierzC[0][1] = macierzA[0][0]*macierzB[0][1] + macierzA[0][1]*macierzB[1][1];
    macierzC[1][1] = macierzA[1][0]*macierzB[0][1] + macierzA[1][1]*macierzB[1][1];
    // wypisanie macierzy poprzez petle
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){    
            cout << macierzC[i][j] << " ";
        }
        cout << endl;
    }
    // transpozycja - program robi transpozycje macierzy A na nowej macierzy, macierzy D
    int macierzD[2][2];
    cout << "Transpozycja macierzy A" << endl;
    macierzD[0][0] = macierzA[0][0];
    macierzD[1][0] = macierzA[0][1];
    macierzD[0][1] = macierzA[1][0];
    macierzD[1][1] = macierzA[1][1];
    // ponowne wypisanie macierzy poprzez petle
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            cout << macierzD[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}