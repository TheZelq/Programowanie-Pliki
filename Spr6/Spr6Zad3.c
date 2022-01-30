#include <stdio.h>

void pobierz();
int policz(int *tab);
void wypisz();
int tab[2];

void pobierz() {
    for (int i=0; i<2; i++) scanf("%d", &tab[i]);
}

int policz(int *tab) {
    return *tab + *++tab;
}

void wypisz() {
    printf("%d", policz(tab));
}

int main() {
    printf("Podaj dwie liczby: \n");
    pobierz();
    wypisz();
    return 0;
}