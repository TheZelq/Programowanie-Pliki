#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumujInt(int *tab);
float sumujFloat(float *tab);
int minInt(int a, int b);
float minFloat(float a, float b);
int maxInt(int a, int b);
float maxFloat(float a, float b);
void wypisz();
void losuj();
void wypiszTab1();
void wypiszTab2();

int tab1[10], *wsk1 = &tab1[0];
float tab2[10], *wsk2 = &tab2[0];

int sumujInt(int *tab) {
    int suma = 0;
    for (int i=0; i<10; i++) suma += tab[i];
    return suma;
}

float sumujFloat(float *tab) {
    float suma = 0;
    for (int i=0; i<10; i++) suma += tab[i];
    return suma;
}

void wypiszTab1() {
    for (int i=0; i<10; i++) printf("%d ", tab1[i]);
}

void wypiszTab2() {
    for (int i=0; i<10; i++) printf("%d ", tab2[i]);
}

void losuj() {
    srand(time(NULL));
    for (int i=0; i<10; i++) tab1[i] = rand() % 101;
    for (int i=0; i<10; i++) tab2[i] = rand() % 101 * 0.01;
}

int minInt(int a, int b) {
    if (a>b) return b;
    else return a;
}

int maxInt(int a, int b) {
    if (a>b) return a;
    else return b;
}

float minFloat(float a, float b) {
    if (a>b) return b;
    else return a;
}

float maxFloat(float a, float b) {
    if (a>b) return a;
    else return b;
}

int main() {
    losuj();
    printf("Pierwsza tablica: \n");
    wypiszTab1();
    printf("\nDruga tablica: \n");
    wypiszTab2();
    printf("\nSuma tablicy z int: %d; suma tablicy z float: %f\n", sumujInt(tab1), sumujFloat(tab2));
    printf("A oto 5 i 10 element tablicy int: %d; %d; oraz tablicy float: %f; %f\n", *(wsk1+4), *(wsk1+9), *(wsk2+4), *(wsk2+9));
    printf("Min dla int: %d, a max: %d; dla float min: %f, a max: %f\n", minInt(*(wsk1+4), *(wsk1+9)), maxInt(*(wsk1+4), *(wsk1+9)), minFloat(*(wsk2+4), *(wsk2+9)), maxFloat(*(wsk2+4), *(wsk2+9)));
    return 0;
}