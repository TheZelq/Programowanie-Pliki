#include <stdio.h>

void pobierz();
void zamien();
float tablica[5];

void pobierz() {
    for (int i=0; i<5; i++){
        scanf("%f", &tablica[i]);
    }
}

void zamien() {
    for (int i=4; i>=0; i--){
        printf("%f ", tablica[i]);
    }
}

int main() {
    printf("Podaj 5 liczb\n");
    pobierz();
    zamien();
    return 0;
}