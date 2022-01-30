#include <stdio.h>

int main() {
    int n;
    printf("Podaj dowolna liczbe\n");
    scanf("%d", &n);
    if (n>=0) {
        printf("Liczba bezwzgledna od %d to %d\n", n, n);
    }
    else {
        printf("Liczba bezwzgledna od %d to %d\n", n, -1*n);
    }
    return 0;
}