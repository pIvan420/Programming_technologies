#include "DigitalWatch2.h"
#include "MechanicalWatch2.h"
int Watch2::count;
int get_random_price2();

void project_menu2() {
	DigitalWatch2* wws1 = new DigitalWatch2[6]{ DigitalWatch2("Casio G-SHOCK GA-900-4AER", get_random_price2(), "Япония", true), DigitalWatch2("Daniel Wellington DW00100510", get_random_price2(), "Швеция", true), DigitalWatch2("M2Z M2Z-200-001", get_random_price2(), "Италия", false),
		DigitalWatch2("Garmin 010-02157-11", get_random_price2(), "США", false), DigitalWatch2("Casio Baby-G BLX-565-3E", get_random_price2(), "Япония", true), DigitalWatch2("The Electricianz ZZ-A1A/04-CRW", get_random_price2(), "Швейцария", false) };
	MechanicalWatch2* wws2 = new MechanicalWatch2[6]{ MechanicalWatch2("Petite Coral Daniel Wellington DW00100515", get_random_price2(), "Швеция", "Кварцевый"), MechanicalWatch2("Continental 22001-GC156950", get_random_price2(), "Швейцария", "Кварцевый"),
		MechanicalWatch2("CIGA Design M051-TT01-W6B", get_random_price2(), "Китай", "Механический с автоподзаводом"), MechanicalWatch2("Carl von Zeyten CVZ0031WH", get_random_price2(), "Германия", "Механический с автоподзаводом"),
		MechanicalWatch2("Korloff 04WA1020033", get_random_price2(), "Франция", "Кварцевый"), MechanicalWatch2("Quadro Studio Daniel Wellington DW00100520", get_random_price2(), "Швеция", "Кварцевый") };
	int length = sizeof(*wws1) / sizeof(wws1[0]);
	Watch2* watchPointers1[6];
	for (int i = 0; i < length; i++) {
		watchPointers1[i] = &wws1[i];
	}
	Watch2* watchPointers2[6];
	for (int i = 0; i < length; i++) {
		watchPointers2[i] = &wws2[i];
	}
	bool flag = true;
	int answer;
	while (flag) {
		cout << "Что вы хотите сделать:\n1)Посмотеть элемент из массива электронных часов;\n2)Посмотреть элемент из массива механических часов;\n3)Посмотреть самый дорогой экземпляр электронных часов;\n" <<
			"4)Посмотреть самый дорогой экземпляр механических часов;\n5)Посмотреть самый дорогой экземпляр часов;\n6)Посмотреть количество часов;\n7)Выйти из программы\nВвод: ";
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
			cout << "Самый дорогой экземпляр электронных часов: " << get_most_expensive_watch(watchPointers1, length).get_name() << endl;
			break;
		}
		case 4: {
			cout << "Самый дорогой экземпляр механических часов: " << get_most_expensive_watch(watchPointers2, length).get_name() << endl;
			break;
		}
		case 5: {
			cout << "Самый дорогой экземпляр: " << get_most_expensive_watch(watchPointers1, watchPointers2, length).get_name() << endl;
			break;
		}
		case 6: {
			cout << "Количество часов: " << wws1[0].get_count() << endl;
			break;
		}
		case 7: {
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

int main() {
	setlocale(LC_ALL, "");
	project_menu2();
}


int get_random_price2() {
	int i = (10 + rand() % 100) * 1000;
	return i;
}