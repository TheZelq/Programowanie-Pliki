#include <stdio.h>

void posortuj(int *tab);
void wypisz();
int tab[10] = {51, 23, 77, 85, 32, 12, 56, 23, 66, 98};

void posortuj(int *tab) {
    int licznik, pomoc;
    for (int i=0; i<9; i++) {
        licznik = 0;
        for (int j=0; j<9-i; j++) {
            if (tab[j] > tab[j+1]) {
                pomoc = tab[j+1];
                tab[j+1] = tab[j];
                tab[j] = pomoc;
                licznik++;
            }
        }
        if (licznik == 0) return;
    }
}

void wypisz() {
    for (int i=0; i<10; i++) printf("%d ", tab[i]);
}

int main() {
    printf("Przed sortowaniem: \n");
    wypisz();
    printf("\nPo sortowaniu: \n");
    posortuj(tab);
    wypisz();
    return 0;
}