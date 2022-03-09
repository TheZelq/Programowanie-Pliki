#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int a = 0;
    printf("Losowanko dopoki nie trafimy 6tki!\n");
    srand(time(0));
    do {
        a = rand()%6+1;
        printf("%d ", a);
    } while (a!=6);
    printf("\nWygrales!");
    return 0;
}