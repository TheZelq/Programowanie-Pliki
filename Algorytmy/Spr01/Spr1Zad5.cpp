#include <iostream>
using namespace std;

int suma(int x) {
    int a=0;
    do {
        a = a+x%10; //do obliczenia cyfry z danej pozycji uzywamy modulo
        x=x/10; //i dzielimy przez 10
    } while(x>0);
    return a;
}

int main() {
    int x;
    do {
        cout << "Podaj liczbe ponad 4cyfrowa" << endl; // bedzie pytal użytkownika do momentu podania poprawnej liczby
        cin >> x;
    } while (x<1000);
    cout << suma(x) << endl;
    return 0;
}