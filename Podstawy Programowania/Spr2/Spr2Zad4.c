#include <stdio.h>

int main() {
    float liczba1, liczba2;
    printf("Podaj pierwsza liczbe\n");
    scanf("%f", &liczba1);
    printf("Podaj druga liczbe\n");
    scanf("%f", &liczba2);
    printf("Podaj symbol dzialania, ktore chcesz wykonac na liczbach\n");
    char a = getchar();
    while (a=='\n') a = getchar();
    switch(a){
        case '+':
            printf("Wynikiem jest %f", liczba1+liczba2);
            break;

        case '-':
            printf("Wynikiem jest %f", liczba1-liczba2);
            break;

        case '*':
            printf("Wynikiem jest %f", liczba1*liczba2);
            break;

        case '/':
            printf("Wynikiem jest %f", liczba1/liczba2);
            break;

        default:
            printf("Znak nie oznacza podstawowego dzialania.");
            break;
    }
    getchar();
    return 0;
}