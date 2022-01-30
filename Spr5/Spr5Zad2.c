#include <stdio.h>

int pobierz();
int silnia(unsigned int a);

int silnia(unsigned int a){
    if (a==0 || a==1) return 1;
    int i=1, j=1;
    while (a>=1){
        j=j*i;
        i++;
        a--;
    };
    return j;
}

int pobierz(){
    int a;
    printf("Podaj liczbe: \n");
    scanf("%d", &a);
    return a;
}

int main(){
    int a = silnia(pobierz());
    printf("%d", a);
    return 0;
}