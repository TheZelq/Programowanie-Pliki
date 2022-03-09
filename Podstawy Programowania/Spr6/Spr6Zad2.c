#include <stdio.h>

void pobierz();
void wypisz();
float macierz[3][3];

void pobierz() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            scanf("%f", &macierz[i][j]);
        }
    }
}

void wypisz() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%f ", macierz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Podaj elementy macierzy\n");
    pobierz();
    wypisz();
    return 0;
}