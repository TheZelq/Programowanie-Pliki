#include <stdio.h>
#include <string.h>
#define MAX 100

struct zbiorka {
    char imie[MAX];
    char grupa[MAX];
    char kwota[10];
};

int main() {
    struct zbiorka dane [50];
    int liczba;
    puts("Podaj liczbe osob chetnych do zbiorki: ");
    scanf("%d", &liczba);
    for (int i=0; i<liczba; i++) {
        printf("Podaj imie: ");
        scanf("%s", &dane[i].imie[0]);
        printf("Podaj grupe: ");
        scanf("%s", &dane[i].grupa[0]);
        printf("Podaj kwote: ");
        scanf("%s", &dane[i].kwota[0]);
    }
    for (int j=0; j<liczba; j++) printf("Imie: %s, Grupa: %s, Kwota: %s\n", &dane[j].imie, &dane[j].grupa, &dane[j].kwota);
    return 0;
}