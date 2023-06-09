#include <iostream>
#include <vector>
#include "DigitalWatch.h"
using namespace std;

int get_random_price3() {
	int i = (10 + rand() % 100) * 1000;
	return i;
}

int main8() {
	setlocale(LC_ALL, "ru");
	//Задание 1
	int count = 1000;
	vector<DigitalWatch> watches1; //создание первого вектора 
	cout << "Создаем первый вектор" << endl;
	for (int i = 0; i < count; i++) { //заполнение первого вектора 1000 объектов
		watches1.push_back(DigitalWatch(to_string(i), get_random_price3(), "", i % 2 == 0));
	}
	cout << "Заполнили первый вектор " << watches1.size() << " элементов" << endl;
	vector<DigitalWatch> watches2; //создание второго вектора
	cout << "Создаем второй вектор" << endl;
	for (int i = count - 1; i >= 0; i--) { //заполнение второго вектора элементами первого вектора в обратном порядке
		watches2.push_back(watches1[i]);
	}
	cout << "Заполнили второй вектор элементами первого в обратном порядке" << endl;
	cout << "Длина второго вектора: " << watches2.size() << " элементов" << endl;
	DigitalWatch *curWatch1 = &watches1[0]; 
	for (int i = 1; i < count; i++) { //поиск самого дорогого экземпляра
		if (curWatch1->get_price() < watches1[i].get_price()) {
			curWatch1 = &watches1[i];
		}
	}
	cout << "Самый дорогой экземпляр: №" << curWatch1->get_name() << endl;
	//Задание 2
	int count2 = 500;
	cout << "Добавляем в середину первого вектора " << count2 << " элементов" << endl;
	for (int i = count; i < count + count2; i++) {
		//cout << i << endl;
		watches1.insert(watches1.begin() + count2, DigitalWatch(to_string(i), get_random_price3(), "", i % 2 == 0));
	}
	cout << "Длина полученного вектора: " << watches1.size() << " элементов" << endl;
	DigitalWatch* curWatch2 = &watches1[0];
	for (int i = 1; i < watches1.size(); i++) { //поиск самого дорогого экземпляра
		if (curWatch2->get_price() < watches1[i].get_price()) {
			curWatch2 = &watches1[i];
		}
	}
	cout << "Самый дорогой экземпляр: №" << curWatch2->get_name() << endl;
	cout << "Очищаем первый вектор" << endl;
	watches1.clear();
	cout << "Длина первого вектора: " << watches1.size() << " элементов" << endl;
	return 0;
}

