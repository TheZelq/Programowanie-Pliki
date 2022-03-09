#include <stdio.h>
#include <math.h>

void binarka(unsigned int a);
int pobierz();

int main(){
    int a = pobierz();
    binarka(a);
    return 0;
}

int pobierz(){
    int a;
    printf("Podaj liczbe do przekstzalcenia: \n");
    scanf("%d", &a);
    return a;
}

void binarka(unsigned int a) {
    short int j, tab[32];
    for(j=0; a>0; j++){
        tab[j] = a%2;
        a=a/2;
    }
    for (j-=1; j>=0; j--) printf("%d", tab[j]);
}