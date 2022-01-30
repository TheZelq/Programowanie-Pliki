#include <stdio.h>

int main() {
    float y;
    printf("Podaj dowolna liczbe\n");
    scanf("%f", &y);
    if (y<0) {
        printf("Nasze x rowna sie %f\n", -1*y);
    }
    else {
        printf("Nasze x rowna sie %f\n", y);
    }
    return 0;
}