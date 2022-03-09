#include <stdio.h>

int main(){
    int liczba2;
    printf("Podaj liczbe ASCII\n");
    scanf("%d", &liczba2);
    printf("%c", (char)liczba2);
    getchar();
    return 0;
}