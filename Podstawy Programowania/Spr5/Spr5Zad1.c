#include <stdio.h>

double min(double a, double b);

int main(){
    double a, b;
    printf("Podaj pierwsza liczbe: \n");
    scanf("%lf", &a);
    getchar();
    printf("Podaj druga liczbe: \n");
    scanf("%lf", &b);
    printf("Liczba mniejsza z powyzszych jest: %lf", min(a,b));
    return 0;
}

double min(double a, double b){
    if(a>b) return b;
    else return a;
}