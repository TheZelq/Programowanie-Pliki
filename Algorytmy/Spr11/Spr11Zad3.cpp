#include <iostream>
#include <stack>
using namespace std;

int main(){
    string sign = "", result;
    stack <string> stackA;
    cout << "Podaj znaki oddzielone spacja, zakoncz proces litera 'F'" << endl;
    while (sign != "F"){ // bedzie prosil o kolejne znaki do momentu trafienia na F
        cin >> sign;
        if (sign == "+" || sign == "-"){
            while (!stackA.empty() && stackA.top()!="("){ // odpowiednio przenosi liczby (i spacje) jesli trzeba
                result += stackA.top() + " ";
                stackA.pop();
            };
            stackA.push(sign);
        } else if (sign == "/" || sign == "*"){ // odpowiednio przenosi liczby (i spacje) jesli trzeba
            while (stackA.top()=="/" || stackA.top()=="*"){
                result += stackA.top() + " ";
                stackA.pop();  
            }
            stackA.push(sign);
        } else if (sign == "("){
            stackA.push(sign); // dodaje (chwilowo) poczatek nawiasu
        } else if (sign == ")"){
            while (stackA.top()!="("){
                result += stackA.top() + " ";
                stackA.pop();
            };
            if (stackA.top()=="(") stackA.pop(); // usuwa wczesniej dodany nawias
        } else if (sign != "F") result += sign + " ";
    }
    while (!stackA.empty()){
        result += stackA.top() + " ";
        stackA.pop();
    }
    cout << result;
    return 0;
}