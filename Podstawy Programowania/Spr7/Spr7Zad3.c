#include <stdio.h>
#include <string.h>
#define MAX 100

void sklej(char *a, char *b);

void sklej(char *a, char *b) {
    int j=0;
    for (int i=0; i<(strlen(a)+strlen(b)-1); i++) {
        if (*(a+i)==0) {
            *(a+i)=*(b+j);
            j++;
        }
    }
}

int main() {
    char a[MAX];
    char b[MAX];
    char *wska = a;
    char *wskb = b;
    puts("String nr 1: ");
    fgets(wska, 100, stdin);
    puts("String nr 2: ");
    fgets(wskb, 100, stdin);
    sklej(wska, wskb);
    printf("%s\n", wska);
    return 0;
}