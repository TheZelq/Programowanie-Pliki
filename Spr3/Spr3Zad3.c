#include <stdio.h>

int main(){
    for (int i=32; i<255; i++){
        printf("%c ", i);
        if (i%32==0) printf("\n");
    }
    return 0;
}