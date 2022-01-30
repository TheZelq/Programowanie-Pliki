#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

void skracaj(char *wskaznik, int rozmiar);

void skracaj(char *wskaznik, int rozmiar) {
    for (int i=rozmiar; i<strlen(wskaznik)-1; i++) wskaznik[i] = 0;
}

int main() {
    char rozmiar[2];
    char *prozmiar = rozmiar;
    char string[MAX];
    puts("Podaj string:");
    fgets(string, 100, stdin);
    puts("Do ilu znakow chcesz skrocic string? ");
    fgets(prozmiar, 2, stdin);
    int liczba = atoi(prozmiar);
    skracaj(string, liczba);
    puts("Oto string po skroceniu");
    puts(string);
    return 0;
}