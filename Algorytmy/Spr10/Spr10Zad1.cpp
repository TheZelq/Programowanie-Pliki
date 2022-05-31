#include <iostream>
using namespace std;

struct elements{ // schemat struktury globalny
    int value;
    elements *next_elem;
    elements *prev_elem;
};

int main(){
    elements *start = NULL; // zmienne wskaznikowe
    elements *finish = NULL;
    elements *temp = NULL;
    int size = 0; // rozmiar stosu (na start jest rowna 0)
    char action;
    cout << "Podaj akcje, ktora wykonasz na stosie" << endl
        << "d - dodaj" << endl
        << "u - usun" << endl
        << "w - wyswietl" << endl
        << "x - zakoncz" << endl;
    bool loop = true;
    while (loop){
        cin >> action;
        switch(action){
            case 'd':
                temp = new elements; // tworzymy nowa strukture temp
                cout << "Podaj element:" << endl;
                cin >> (*temp).value;
                if (size == 0) { // oznacza to, że stos jest pusty
                    (*temp).prev_elem = NULL; // odpowiednio wyczyszcza adres poprzedniego elementu
                    finish = start = temp; // oraz odpowiedno adresujemy poczatek, koniec oraz cala strukture;
                }
                else {
                    (*temp).prev_elem = start; // ustawia adres poprzedniego elementu jako start
                    start = temp; // nadajemy wartosc ostatniego elementu kolejki
                }
                size++; // zwiekszamy rozmiar o 1
                cout << "Dodano pomyslnie" << endl;
                break;
            
            case 'u':
                if (size == 0) cout << "Stos jest pusty!" << endl; // zwraca jesli stos jest pusty
                else {
                    temp = start; // adres pierwszej zmiennej
                    if (size == 1) start = finish = NULL; // zeruje stos jesli jest tylko 1 element przed usunieciem
                    else start = (*start).prev_elem; // ustawia adres drugiego elementu jako poczatkowy
                    delete temp; // usuwanie pierwszej zmiennej
                    size--; // zmniejszamy rozmiar o 1
                    cout << "Usunieto pomyslnie." << endl;
                }
                break;
            
            case 'w':
                if (size == 0) cout << "Stos jest pusty!" << endl; // zwraca jesli stos jest pusty
                else {
                    cout << "Tak wyglada stos:" << endl;
                    temp = start;
                    int limit = size; // wykonuje petle while nie zmieniajac zmiennej size
                    while (limit != 0) {
                        cout << (*temp).value << " "; // korzystam ze wskaznikow do wskazania ktora wartosc z danego adresy wyprintowac
                        temp = (*temp).prev_elem; // oraz nadaje zmiennej temp nowy adres
                        limit--;
                    }
                    cout << endl;
                }
                break;
            
            case 'x':
                loop = false; // zamyka program
                break;
            
            default:
                cout << "Podaj akcje, ktora wykonasz na stosie" << endl
                    << "d - dodaj" << endl
                    << "u - usun" << endl
                    << "w - wyswietl" << endl
                    << "x - zakoncz" << endl;
                break;
        }
    }
    return 0;
}