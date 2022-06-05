#include <iostream>
#include <stack>
using namespace std;

void print(stack <int> stackA){
    stack <int> stackB;
    while(!stackA.empty()){
        stackB.push(stackA.top());
        stackA.pop();
    }
    while(!stackB.empty()){
        cout << stackB.top() << " ";
        stackB.pop();
    }
    cout << endl;
}

int main(){
    stack <int> stackA[3];
    bool czyPoprawnie = true;
    int a, b, n;
    cout << "Jak wielka ma byc wieza Hanoi? ";
    cin >> n;
    for (int i=n; i>0; i--) stackA[0].push(i);
    while (true){
        cout << "Stos 1: " << endl;
        print(stackA[0]);
        cout << "Stos 2: " << endl;
        print(stackA[1]);
        cout << "Stos 3: " << endl;
        print(stackA[2]);
        cout << "Z ktorego stosu chcesz przeniesc element? ";
        cin >> a;
        cout << endl << "Do ktorego stosu chcesz przeniesc element? ";
        cin >> b;
        cout << endl;
        if(a==b || stackA[a-1].empty()) czyPoprawnie = false; // sprawdza, czy przesuwamy na ten sam stos i czy stos A jest pusty
        else if (!stackA[b-1].empty() && stackA[a-1].top()>stackA[b-1].top()) czyPoprawnie = false; // sprawdza, czy element ze stosu A nie jest wiekszy niz ze stosu B
        else if (czyPoprawnie) {
            stackA[b-1].push(stackA[a-1].top()); // przesuwa element miedzy stosami
            stackA[a-1].pop();
        }
        if (czyPoprawnie == false) cout << "Zla operacja, sprobuj ponownie!" << endl;
        czyPoprawnie = true;
        if(stackA[0].empty() && stackA[2].empty()) {
            cout << "Zadanie ukonczone pomyslnie!";
            return 0;
        }
    }
}