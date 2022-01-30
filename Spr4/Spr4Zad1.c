#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int licznik = 0, licznik_spacji = 1;
    printf("Napisz cokoliwek (slowo, zdanie) i zaknocz enterem. \n");
    ch = getchar();
    while (ch != '\n'){
        licznik++;
        if (isspace(ch)) licznik_spacji++;
        ch = getchar();
    }
    if (licznik==0) licznik_spacji = 0;
    printf("Powyzszy tekst zawiera %d znakow i %d slow", licznik, licznik_spacji);
    return 0;
}