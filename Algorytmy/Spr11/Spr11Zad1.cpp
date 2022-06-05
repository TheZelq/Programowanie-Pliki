#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
const int limit = 100;

void stos(){
    stack <int> stackA;
    int opcja, x;
    for (int i=0; i<5; i++){
        stackA.push(rand() % limit);
    }
    cout << "Oto menu stosu:\n"
            "Wybierz jedną z opcji:\n"
            "\t1. Dodaj element\n"
            "\t2. Usun element\n"
            "\t3. Wyswietl ostatni element\n"
            "\t4. Wyswietl rozmiar stosu\n"
            "\t5. Wyswietl status stosu (pusty czy nie)\n"
            "\t6. Zakoncz proces\n";
    while (true) {    
        cin >> opcja;
        switch(opcja) {
            case 1:
                cout << "Podaj element:" << endl;
                cin >> x;
                stackA.push(x);
            break;

            case 2:
                if(stackA.empty()) cout << "Stos jest juz pusty!" << endl;
                else {
                    cout << "Usuwamy ten element: " << stackA.top() << endl;
                    stackA.pop();
                }
            break;

            case 3:
                if(stackA.empty()) cout << "Stos jest pusty!" << endl;
                else cout << "Ostatni element: " << stackA.top() << endl;
            break;

            case 4:
                if(stackA.empty()) cout << "Stos jest pusty!" << endl;
                else cout << "Rozmiar stosu: " << stackA.size() << endl;
            break;

            case 5:
                if(stackA.empty()) cout << "Stos jest pusty!" << endl;
                else cout << "Stos nie jest pusty." << endl;
            break;

            case 6:
                return;
            break;

            default:
                cout << "Podano zla opcje." << endl;
            break;
        }
    }
}

void kolejka(){
    queue <int> queueA;
    int opcja, x;
    for (int i=0; i<5; i++){
        queueA.push(rand() % limit);
    }
    cout << "Oto menu kolejki:\n"
            "Wybierz jedną z opcji:\n"
            "\t1. Dodaj element\n"
            "\t2. Usun element\n"
            "\t3. Wyswietl pierwszy element\n"            
            "\t4. Wyswietl ostatni element\n"
            "\t5. Wyswietl rozmiar kolejki\n"
            "\t6. Wyswietl status kolejki (pusta czy nie)\n"
            "\t7. Zakoncz proces\n";
    while(true){    
        cin >> opcja;
        switch(opcja) {
            case 1:
                cout << "Podaj element:" << endl;
                cin >> x;
                queueA.push(x);
            break;

            case 2:
                if(queueA.empty()) cout << "Kolejka jest juz pusta!" << endl;
                else {
                    cout << "Usuwamy ten element: " << queueA.front() << endl;
                    queueA.pop();
                }
            break;

            case 3:
                if(queueA.empty()) cout << "Kolejka jest pusta!" << endl;
                else cout << "Pierwszy element: " << queueA.front() << endl;
            break;

            case 4:
                if(queueA.empty()) cout << "Kolejka jest pusta!" << endl;
                else cout << "Ostatni element: " << queueA.back() << endl;
            break;

            case 5:
                if(queueA.empty()) cout << "Kolejka jest pusta!" << endl;
                else cout << "Rozmiar kolejki: " << queueA.size() << endl;
            break;

            case 6:
                if(queueA.empty()) cout << "Kolejka jest pusta!" << endl;
                else cout << "Kolejka nie jest pusta." << endl;
            break;

            case 7:
                return;
            break;

            default:
                cout << "Podano zla opcje." << endl;
            break;
        }
    }
}

void wektor(){
    vector <int> vectorA;
    int opcja, x;
    for (int i=0; i<5; i++){
        vectorA.push_back(rand() % limit);
    }
    cout << "Oto menu wektora:\n"
            "Wybierz jedną z opcji:\n"
            "\t1. Dodaj element\n"
            "\t2. Usun element\n"
            "\t3. Wyswietl pierwszy element\n"            
            "\t4. Wyswietl ostatni element\n"
            "\t5. Wyswietl n-ty element\n"
            "\t6. Wyswietl, czy istnieje wartosc x w wektorze\n"
            "\t7. Wyswietl rozmiar wektora\n"
            "\t8. Wyswietl status wektora (pusty czy nie)\n"
            "\t9. Zakoncz proces\n";
    while (true){
        cin >> opcja;
        switch(opcja) {
            case 1:
                cout << "Podaj element:" << endl;
                cin >> x;
                vectorA.push_back(x);
            break;

            case 2:
                if(vectorA.empty()) cout << "Wektor jest juz pusty!" << endl;
                else {
                    cout << "Usuwamy ten element: " << vectorA.front() << endl;
                    vectorA.pop_back();
                }
            break;

            case 3:
                if(vectorA.empty()) cout << "Wektor jest pusty!" << endl;
                else cout << "Pierwszy element: " << vectorA.front() << endl;
            break;

            case 4:
                if(vectorA.empty()) cout << "Wektor jest pusty!" << endl;
                else cout << "Ostatni element: " << vectorA.back() << endl;
            break;

            case 5:
                if(vectorA.empty()) cout << "Wektor jest pusty!" << endl;
                else {
                    int n;
                    cout << "Podaj element n:" << endl;
                    cin >> n;
                    if(n>vectorA.size()) cout << "Wektor jest mniejszy niz 'n'!";
                    else cout << "Oto n-ty element wektora:" << vectorA[n-1] << endl;
                }
            break;

            case 6:
                if(vectorA.empty()) cout << "Wektor jest pusty!" << endl;
                else {
                    cout << "Podaj element x:" << endl;
                    cin >> x;
                    for(int i=0; i<vectorA.size(); i++) if (vectorA[i]==x) cout << "Podany element istnieje na " << i-1 << " miejscu." << endl;
                    else cout << "Podany element nie istnieje w wektorze" << endl;
                }
            break;

            case 7:
                if(vectorA.empty()) cout << "Wektor jest pusty!" << endl;
                else cout << "Rozmiar wektora: " << vectorA.size() << endl;
            break;

            case 8:
                if(vectorA.empty()) cout << "Wektor jest pusty!" << endl;
                else cout << "Wektor nie jest pusty." << endl;
            break;

            case 9:
                return;
            break;

            default:
                cout << "Podano zla opcje." << endl;
            break;
        }
    }
}

int main(){
    int opcja;
    cout << "Witam w menu!\n"
            "Wybierz jedną z opcji:\n"
            "\t1. Stos\n"
            "\t2. Kolejka\n"
            "\t3. Wektor\n";
    cin >> opcja;
    switch (opcja){
        case 1:
            stos();
        break;

        case 2:
            kolejka();
        break;

        case 3:
            wektor();
        break;   

        default:
            cout << "Nie podano poprawnej opcji.";
        break;
    };
    return 0;
}