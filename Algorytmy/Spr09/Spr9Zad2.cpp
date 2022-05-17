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
    int size = 0; // rozmiar kolejki (na start jest rowna 0)
    int low = 0; // tworzenie zmiennych dla ilosci poszczegolnych poziomow priorytetowych (tylko dla mid i high)
    int mid = 0;
    string prio;
    char action;
    cout << "Podaj akcje, ktora wykonasz na kolejce" << endl
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
                cout << "Jaki stopien priorytetu?" << endl;
                cin >> prio;
                if (size == 0) { // oznacza to, że kolejka jest pusta
                    (*temp).next_elem = (*temp).prev_elem; // nadajemy te sama wartosc dla poczatku i konca
                    finish = start = temp; // oraz odpowiedno adresujemy poczatek, koniec oraz cala strukture;
                }
                else {
                    if (prio == "low") {
                        (*temp).next_elem = NULL; // ustawia adres kolejnego elementu na NULL
                        (*finish).next_elem = temp; // nadaje nowemu ostatniemu elementowi adres poprzedniego
                        (*temp).prev_elem; // do pamieci trafia adres ostatniego elementu
                        finish = temp; // nadajemy wartosc ostatniego elementu kolejki
                        low++;
                    }
                    else if (prio == "mid") {
                        (*temp).next_elem = NULL; // ustawia adres kolejnego elementu na NULL
                        for (int i=0; i<low; i++){
                            (*finish).next_elem = temp; // nadaje nowemu ostatniemu elementowi adres poprzedniego
                            (*temp).prev_elem; // do pamieci trafia adres ostatniego elementu
                            finish = temp; // nadajemy wartosc ostatniego elementu kolejki
                        }
                        mid++;
                    }
                    else if (prio == "high") {
                        (*temp).next_elem = NULL; // ustawia adres kolejnego elementu na NULL
                        for (int i=0; i<low+mid; i++){
                            (*finish).next_elem = temp; // nadaje nowemu ostatniemu elementowi adres poprzedniego
                            (*temp).prev_elem; // do pamieci trafia adres ostatniego elementu
                            finish = temp; // nadajemy wartosc ostatniego elementu kolejki
                        }
                    }
                    else "Nie podano poprawnego elementu";
                }
                size++; // zwiekszamy rozmiar o 1
                cout << "Dodano pomyslnie" << endl;
                break;
            
            case 'u':
                if (size == 0) cout << "Kolejka jest pusta!" << endl; // zwraca jesli kolejka jest pusta
                else {
                    temp = start; // adres pierwszej zmiennej
                    if (size == 1) start = finish = NULL; // zeruje kolejke jesli jest tylko 1 element przed usunieciem
                    else start = (*start).next_elem; // ustawia adres drugiego elementu jako poczatkowy
                    delete temp; // usuwanie pierwszej zmiennej
                    size--; // zmniejszamy rozmiar o 1
                    cout << "Usunieto pomyslnie." << endl;
                }
                break;
            
            case 'w':
                if (size == 0) cout << "Kolejka jest pusta!" << endl; // zwraca jesli kolejka jest pusta
                else {
                    cout << "Tak wyglada kolejka:" << endl;
                    temp = start;
                    int limit = size; // wykonuje petle while nie zmieniajac zmiennej size
                    while (limit != 0) {
                        cout << (*temp).value << " "; // korzystam ze wskaznikow do wskazania ktora wartosc z danego adresy wyprintowac
                        temp = (*temp).next_elem; // oraz nadaje zmiennej temp nowy adres
                        limit--;
                    }
                    cout << endl;
                }
                break;
            
            case 'x':
                loop = false; // zamyka program
                break;
            
            default:
                cout << "Podaj akcje, ktora wykonasz na kolejce" << endl
                    << "d - dodaj" << endl
                    << "u - usun" << endl
                    << "w - wyswietl" << endl
                    << "x - zakoncz" << endl;
                break;
        }
    }
    return 0;
}
