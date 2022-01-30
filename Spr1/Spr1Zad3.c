#include <stdio.h>

int main(){
    int liczba3, liczba4, BMI;
    printf("Podaj wzrost w [cm]\n");
    scanf("%d", &liczba3);
    liczba3 /= 100;
    printf("Podaj wage w [kg]\n");
    scanf("%d", &liczba4);
    BMI = liczba4/(liczba3^2);
    printf("BMI wynosi: %d", BMI);
    getchar();
    return 0;
}