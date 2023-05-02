#include <iostream>
#include <string>
#include "Watch7A.cpp"
#include <Windows.h>
using namespace std;

int main7() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	const int len = 5;
	Watch7A<double> watches[len] = { Watch7A<double>("Casio G-SHOCK GA-900-4AER", 11990, "Япония"),  Watch7A<double>("Daniel Wellington DW00100510", 9450, "Швеция"), Watch7A<double>("M2Z M2Z-200-001", 52000, "Италия"),
		Watch7A<double>("Garmin 010-02157-11", 115000, "США"), Watch7A<double>("Casio Baby-G BLX-565-3E", 9990, "Япония")};
	//Реализация шаблона класса дял типа double
	//самый дорогой экземпляр
	Watch7A<double>* curwatch = &watches[0];
	for (int i = 1; i < len; i++) { 
		if (watches[i].get_price() > curwatch->get_price()) {
			curwatch = &watches[i];
		}
	}
	cout << "Самый дорогой экземпляр: " << curwatch->get_name() << endl;
	//количество часов определенного производителя
	string country;
	int count = 0;
	cout << "Введите производителя: ";
	cin >> country;
	for (int i = 0; i < len; i++) {
		if (watches[i].get_manufacturer() == country) {
			count++;
		}
	}
	cout << "Количество часов производителя: " << count;
	return 0;
}