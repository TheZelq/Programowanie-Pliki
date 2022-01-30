#include <stdio.h>
#include <math.h>

double zamiana(double a);

int main() {
    double kat, radiany;
    int kat_d;
    printf("Witam! Podaj wartosc kata w stopniach.");
    scanf("%lf", &kat);
    getchar();
    radiany = zamiana(kat);
    kat_d = 90 + kat;
    if (kat_d%180==0) printf("Funkcje trygon. maja wartosc: sin = %lf \n cos = %lf \n tg = Tangens tego kata nie istnieje ", sin(radiany), cos(radiany), tan(radiany));
    else printf("Funkcje trygon. maja wartosc: sin = %lf \n cos = %lf \n tg = %lf ", sin(radiany), cos(radiany), tan(radiany));
}

double zamiana(double a) {
    return a*(M_PI/180);
}