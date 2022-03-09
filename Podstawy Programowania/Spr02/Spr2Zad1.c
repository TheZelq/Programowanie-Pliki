#include <stdio.h>

int main() {
    int i=0, dod=0, ujem=0;
    float liczba;
    do {
        printf("Podaj dowolna liczbe \n");
        scanf("%f", &liczba);
        if(liczba>=0){
            ++dod;
        }
        else {
            ++ujem;
        }
        ++i;
    } while (i<4);
    if(dod>ujem) {
        printf("Jest wiecej liczb dodatnich. \n");
    }
    else if(ujem>dod) {
        printf("Jest wiecej liczb ujemnych. \n");
    }
    else {
        printf("Jest tyle samo liczb dodatnich i ujemnych. \n");
    }
    getchar();
    return 0;
}