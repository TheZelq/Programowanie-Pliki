#include <stdio.h>
#include <math.h>

int main() {
    float bok, bok2, bok3, pole, wysokosc;
    printf("Chcesz obliczyc szybko pole figury? Jesli tak to wcisnij:\n");
    printf("T - pole trojkata\n");
    printf("K - pole kwadratu\n");
    printf("P - pole prostokata\n");
    char a = getchar();
    while (a=='\n') a = getchar();
    switch(a){
        case 'T': case 't':
        printf("Czy znacz wysokosc trojkata i bok do niego prostopadly? Jesli tak to wcisnij 'y' lub 'Y' ");
        char b = getchar();
        while (b=='\n') b = getchar();
        switch(b){
            case 'Y': case 'y':
                printf("Podaj dlugosc boku:\n");
                scanf("%f", &bok);
                printf("Podaj dlugosc wysokosci:\n");
                scanf("%f", &wysokosc);
                pole = (bok*wysokosc)/2;
                printf("Pole danego trojkata wynosi: %f", pole);
                break;

            default:
                printf("Podaj dlugosc boku:\n");
                scanf("%f", &bok);
                printf("Podaj dlugosc 2. boku:\n");
                scanf("%f", &bok2);
                printf("Podaj dlugosc 3. boku:\n");
                scanf("%f", &bok3);
                float polobwod = (bok+bok2+bok3)/2;
                pole = sqrt(polobwod*(polobwod-bok)*(polobwod-bok2)*(polobwod-bok3));
                if(bok2+bok3 <= bok || bok+bok3 <= bok2 || bok+bok2 <= bok3) {
                    printf("Z podanymi bokami nie da sie utworzyc trojkata");
                }
                else printf("Pole danego trojkata wynosi: %f", pole);
                break;
        }

        case 'K': case 'k':
            printf("Podaj dlugosc boku kwadratu:\n");
            scanf("%f", &bok);
            pole = bok*bok;
            printf("Pole danego kwadratu wynosi: %f", pole);
            break;
        
        case 'P': case 'p':
            printf("Podaj dlugosc boku prostokata:\n");
            scanf("%f", &bok);
            printf("Podaj dlugosc 2. boku prostokata:\n");
            scanf("%f", &bok2);
            pole = bok*bok2;
            printf("Pole danego prostokata wynosi: %f", pole);
            break;
        
        default:
            printf("Nie wprowadzono odpowiedniego znaku.");
            break;
    }
    getchar();
    return 0;    
}