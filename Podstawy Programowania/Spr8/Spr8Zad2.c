#include <stdio.h>
#include <math.h>

struct kolo {
    char nazwa[10];
    float x, y, r1;
};

int main() {
    struct kolo kola[3] = {
        {"koloNr1", 8, 12, 3},
        {"koloNr2", -3, -4, 8},
        {"koloNr3", 0.15, -2.60, 7},
    };
    float x, y;
    int wybor, licznik = 0;
    puts("Podaj wspolrzedna x punktu: ");
    scanf("%f", &x);
    puts("Podaj wspolrzedna y punktu: ");
    scanf("%f", &y);
    for (int i=0; i<3; i++) {
        float funkcja = sqrt(pow(x-kola[i].x, 2) + pow(y-kola[i].y, 2));
        if (funkcja <= kola[i].r1) {
            printf("Punkt nalezy do kola '%s'. Pole kola wynosi: %.2f\n", kola[i].nazwa, pow(kola[i].r1, 2)*M_PI);
            licznik++;
        } 
    }
    if (licznik==0) printf("Punkt nie nalezy do zadnego okregu.");
    return 0;
}