#include <stdio.h>

int main(){
    const long double rok = 3.156E7;
    int liczba5, sekundy;
    printf("Podaj swoj wiek\n");
    scanf("%d", &liczba5);
    sekundy = liczba5*rok;
    printf("%d lat jest okolo %d sekund", liczba5, sekundy);
    getchar();
    return 0;
}