#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct elements{ // schemat struktury globalny
    int value;
    elements *prev_elem;
};

elements *start = NULL; // zmienne wskaznikowe
elements *finish = NULL;
elements *temp = NULL;

void push(elements **start, elements **finish, int size, int inp) // dodawanie elementow do stosu
{
	elements *temp = new elements;
	(*temp).value = inp;
	if (finish == NULL) {
		(*temp).prev_elem = NULL;
		*start = *finish = temp;
	}
	else {
		(*temp).prev_elem = *start;
		*start = temp;
	}
		size++;
	for (int i = size; i > 0; i--, temp = (*temp).prev_elem)
		cout << (*temp).value << " ";
}
void pop(elements **start, elements **finish, int *size) // usuwanie elementow stosu
{
	while (*start != NULL) { // wykonuj az nie bedzie elementow w stosie
		elements *temp = *start; // pierwszy elements stosu jest brany do zmiennej pomocniczej
		if (start == finish) 
			*start = *finish = NULL; 
		else *start = (*start)->prev_elem; // przesuwamy ostatni element o 1
		delete temp; // czyszczenie cache
	}
	*size = 0; // zerowany rozmiar
}


int main(){
    int size = 0; // rozmiar stosu (na start jest rowna 0)
	cout << "Wprowadz liczby, a potem pojedynczy znak: " << endl;

	while (true) {
		string input; // zmienna string od pobierania liczb
		int wynik = 0, numer; // zmienna wynikowa oraz zmienna, w której zapisywane są liczby ze stringa
		cin >> input; // wprowadzanie elementu
		if (istringstream(input) >> numer) // wprowadzanie elementow
		{
			push(&start, &finish, size, numer); // za wprowadzanie odpowiada funkcja
			size++; // zwiekszamy rozmiar o 1
			cout << endl;
		}
		else // wykrywanie operatorów
		{ 
			switch (input[0]) 
			{
			case '+':
				temp = start; //
				wynik = (*temp).value; // utworzenie wyniku, do ktorego beda dodawane kolejne elementy
				for (int i = size; (*temp).prev_elem != NULL; i--, temp = (*temp).prev_elem)
					wynik = wynik + (*temp).prev_elem->value; // iteracja abysmy mogli wykonywac wiecej dzialan przy wiekszym stosie

				cout << "Wynik: " << wynik << endl; // wyswietla wynik
				break;

			case '-':
				temp = start;
				wynik = (*temp).value;
				for (int i = size; (*temp).prev_elem != NULL; i--, temp = (*temp).prev_elem) 
					wynik = (*temp).prev_elem->value - wynik;

				temp = start;
				cout << "Wynik: " << wynik << endl;
				break;

			case '*':
				temp = start;
				wynik = (*temp).value;
				for (int i = size; (*temp).prev_elem != NULL; i--, temp = (*temp).prev_elem) 
					wynik = wynik * (*temp).prev_elem->value;

				temp = start;
				cout << "Wynik: " << wynik << endl;
				break;

			case '/':
				temp = start;
				wynik = temp->value;
				for (int i = size; (*temp).prev_elem != NULL; i--, temp = (*temp).prev_elem) 
					wynik = ((*temp).prev_elem->value / wynik);

				temp = start;
				cout << "Wynik: " << wynik << endl;
				break;

			case 'q':
				cout << "Finished!";
				return 0;
				break;
			
			default:
				cout << "Error!!! " << endl;
				break;
			}
		}
	}
}
