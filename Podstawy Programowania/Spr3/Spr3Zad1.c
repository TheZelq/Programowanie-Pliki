#include <stdio.h>

int main() {
    int liczba, wiersz=1, licznik=0, a=1;
    printf("Podaj liczbe wierszy do wyswietlenia. \n");
    scanf("%d", &liczba);
    getchar();
    for (int i=1; i<=liczba; i++){
        do {
            printf("%d ", a);
            a++;
            licznik++;
        } while(wiersz>licznik);
        printf("\n");
        wiersz++;
        licznik=0;
    }
    return 0;
}