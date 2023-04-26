#include "DigitalWatch.h"
#include "MechanicalWatch.h"

int get_random_price();

void project_menu() {
	DigitalWatch* wws1 = new DigitalWatch[6]{ DigitalWatch("Casio G-SHOCK GA-900-4AER", get_random_price(), "Япония", true), DigitalWatch("Daniel Wellington DW00100510", get_random_price(), "Швеция", true), DigitalWatch("M2Z M2Z-200-001", get_random_price(), "Италия", false),
		DigitalWatch("Garmin 010-02157-11", get_random_price(), "США", false), DigitalWatch("Casio Baby-G BLX-565-3E", get_random_price(), "Япония", true), DigitalWatch("The Electricianz ZZ-A1A/04-CRW", get_random_price(), "Швейцария", false) };
	MechanicalWatch* wws2 = new MechanicalWatch[6]{ MechanicalWatch("Petite Coral Daniel Wellington DW00100515", get_random_price(), "Швеция", "Кварцевый"), MechanicalWatch("Continental 22001-GC156950", get_random_price(), "Швейцария", "Кварцевый"),
		MechanicalWatch("CIGA Design M051-TT01-W6B", get_random_price(), "Китай", "Механический с автоподзаводом"), MechanicalWatch("Carl von Zeyten CVZ0031WH", get_random_price(), "Германия", "Механический с автоподзаводом"),
		MechanicalWatch("Korloff 04WA1020033", get_random_price(), "Франция", "Кварцевый"), MechanicalWatch("Quadro Studio Daniel Wellington DW00100520", get_random_price(), "Швеция", "Кварцевый") };
	int length = sizeof(*wws1) / sizeof(wws1[0]);
	Watch* watchPointers1[6];
	for (int i = 0; i < length; i++) {
		watchPointers1[i] = &wws1[i];
	}
	Watch* watchPointers2[6];
	for (int i = 0; i < length; i++) {
		watchPointers2[i] = &wws2[i];
	}
	bool flag = true;
	int answer;
	while(flag) {
		cout << "Что вы хотите сделать:\n1)Посмотеть элемент из массива электронных часов;\n2)Посмотреть элемент из массива механических часов;\n3)Посмотреть самый дорогой экземпляр электронных часов;\n" <<
			"4)Посмотреть самый дорогой экземпляр механических часов;\n5)Выйти из программы\nВвод: ";
		cin >> answer;
		switch (answer) {
		case 1: { 
			int elem;
			while (true) {
				cout << "Какой экземпляр хотите (от 1 до 6): ";
				cin >> elem;
				if (elem <= 6 && elem >= 1) {
					cout << "Название: " << wws1[elem].get_name() << endl;
					cout << "Цена: " << wws1[elem].get_price() << endl;
					cout << "Страна производства: " << wws1[elem].get_country() << endl;
					cout << "Есть ли шагометр: ";
					if (wws1[elem].is_pedometer()) {
						cout << "да" << endl;
					}
					else {
						cout << "нет" << endl;	
					}
					break;
				}
				else {
					cout << "Я не понял, что вы хотите. Введите еще раз.\n";
				}
			}
			break; 
		}
		case 2: {
			int elem;
			while (true) {
				cout << "Какой экземпляр хотите (от 1 до 6): ";
				cin >> elem;
				if (elem <= 6 && elem >= 1) {
					cout << "Название: " << wws2[elem].get_name() << endl;
					cout << "Цена: " << wws2[elem].get_price() << endl;
					cout << "Страна производства: " << wws2[elem].get_country() << endl;
					cout << "Тип механизма: " << wws2[elem].get_mechanism_type() << endl;
					break;
				}
				else {
					cout << "Я не понял, что вы хотите. Введите еще раз.\n";
				}
			}
			break;
		}
		case 3: {
			cout << "Самый дорогой экземпляр: " << get_most_expensive_watch(watchPointers1, length).get_name() << endl;
			break;
		}
		case 4: {
			cout << "Самый дорогой экземпляр: " << get_most_expensive_watch(watchPointers2, length).get_name() << endl;
			break;
		}
		case 5: {
			cout << "Удачи!";
			flag = false;
			break;
		}
		default: {
			cout << "Я не понял, что вы ввели. Повторите ввод (от 1 до 5)\n";
			break;
		}
		}
	}
}

int main5() {
	setlocale(LC_ALL, "");
	project_menu();
	return 0;
}


int get_random_price() {
	int i = (10 + rand() % 100) * 1000;
	return i;
}