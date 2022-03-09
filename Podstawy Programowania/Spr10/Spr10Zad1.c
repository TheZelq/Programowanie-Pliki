#include <stdio.h>

int main(){
    int a;
    puts("Podaj liczbe calkowita\n");
    scanf("%d", &a);
    if(a & 16 && a & 128) printf("Wartosci 5 oraz 8 bitu to 1");
    else if (a & 16) printf("Wartosc 5 bitu wynosi 1, a 8 wynosi 0");
    else if (a & 128) printf("Wartosc 5 bitu wynosi 0, a 8 wynosi 1");
    else printf("Wartosci 5 oraz 8 bitu to 0");
    return 0;
}
