#include <stdio.h>

int main() {
    int n, liczba=1;
    printf("Wpisz wartosc N: ");
    scanf("%d", &n);
    getchar();
    printf("Liczby nieparzyste od 1 do N to: ");
    while (liczba<=n){
        if(liczba%2==1) printf("%d ", liczba);
        liczba++;
    }
    return 0;
}