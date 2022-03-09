#include <stdio.h>
#define RATA_A 40
#define RATA_B 60
#define POD_A 0.15
#define POD_B 0.2
#define POD_C 0.25

int main() {
    int godziny, wyn_n, podatek, wyn_b;
    printf("Podaj liczbe godzin pracy\n");
    scanf("%d", &godziny);
    wyn_n = godziny*RATA_A;
    if (godziny>40) wyn_n += (godziny-40)*(RATA_B-RATA_A);
    if (wyn_n<=1200) podatek=wyn_n*POD_A;
    else {
        podatek=1200*POD_A;
        if(wyn_n<=1800) podatek+=(wyn_n-1200)*POD_B;
        else {
            podatek+=600*POD_B;
            podatek+=(wyn_n-1800)*POD_C;
        }
    }
    wyn_b = wyn_n+podatek;
    printf("%d godzin przyniesie pracownikowi %d zl netto i %d zl brutto.", godziny, wyn_n, wyn_b);
    return 0;
}