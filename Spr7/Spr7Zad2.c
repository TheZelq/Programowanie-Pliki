#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int znajdujeSieW(char litera, char *tab);

int znajdujeSieW(char litera, char *tab) {
    int i=0, wynik=0;
    while (i<strlen(tab)) {
        if (*(tab+i)==litera) wynik=1;
        i++;
    }
    return wynik;
}

int main() {
    char znak;
    char string[MAX];
    char *pstring = string;
    puts("Napisz jakies zdanie.");
    fgets(pstring, 100, stdin);
    for (int i=0; i<strlen(string)-1; i++) {
        printf("Podaj litere do sprawdzenia. ");
        scanf("%c", &znak);
        getchar();
        if (znajdujeSieW(znak, pstring)) puts("Litera jest w danym zdaniu.");
        else puts("Litery nie ma w danym zdaniu.");
    }
    return 0;
}