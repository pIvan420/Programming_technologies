#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <Windows.h>
using namespace std;

void task1();
void task2(string* str);
void task3();
void task4();
void readFile();

int main3()
{
	setlocale(LC_ALL, "");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	task4();
	return 0;
}

void task1() {
	for (int i = 2; i < 8; i++) { //числа в матрице идут от 2 до 7
		cout << setfill('?') << setw(3) << i << setfill('?') << setw(5) << "" << endl; /*заполняю пустоту знаками "?" при ширине поля равной 3 и в конец ставлю число i
																						после заполняю остаток знаками "?" при ширине поля равной 5*/
	}
}

void task2(string* str) {
	string str1 = *str;
	int count = 0;
	int pos = 0;
	pos = str1.find("o", pos); //нахожу первое вхождение символа в строке
	while (pos < str1.length()) { //проверяю, что позиция символа меньше длины строки
		count++; //если да, то увеличиваю счетчик
		pos = str1.find("o", pos) + 1; //и ищу вновь
	}
	cout << "Количество букв \"o\": " << count << "\n";
}

struct wristwatch { //структура наручных часов
	string name;
	int price;
} ww1, ww2, ww3, ww4, ww5;

void task3() {
	ww1 = { "Casio G-SHOCK GA-900-4AER", 11990 };
	ww2 = { "Stuhrling 3917.1", 18990 };
	ww3 = { "Seiko SNK371K1", 15640 };
	ww4 = { "Daniel Wellington DW00100510", 9450 };
	ww5 = { "M2Z M2Z-200-001", 52000 };

	ofstream tofile;
	tofile.open("Y:\\Students\\ИСТ-222\\Торсунов Иван\\wristwatch.txt"); //старт потока
	if (!tofile) { //срабатывание в случае недоступа к файлу
		cout << "Error of file opening";
	}
	else //заполнение файла искомым образом
	{
		tofile << left << setfill(' ') << setw(32) << ww1.name;
		tofile << setfill(' ') << setw(32) << ww2.name;
		tofile << setfill(' ') << setw(32) << ww3.name;
		tofile << setfill(' ') << setw(32) << ww4.name;
		tofile << ww5.name << endl;
		tofile << setfill(' ') << setw(32) << ww1.price;
		tofile << setfill(' ') << setw(32) << ww2.price;
		tofile << setfill(' ') << setw(32) << ww3.price;
		tofile << setfill(' ') << setw(32) << ww4.price;
		tofile << ww5.price << endl;
		tofile.close(); //прекращение потока
	}

	wristwatch* curww = &ww1; //искомая переменная с вычисляемым показателем(самый дорогой экземпляр)

	wristwatch wws[] = { ww1, ww2, ww3, ww4, ww5 };
	for (int i = 1; i < 5; i++) {
		if (wws[i].price > curww->price) { //если цена часов из списка больше, чем curww, то заменяем
			curww = &wws[i];
		}
	}
	cout << "Самые дорогие часы: " << curww->name << "\n";
}

void task4() { //пользовательский интерфейс
	string task;
	bool flag = true;
	while (flag) {
		cout << "Какое задание вы хотите выбрать? (1,2,3)\n";
		cin >> task;
		if (task == "1") {
			task1();
		}
		else if (task == "2") {
			string* str = new string("One Five Zero");
			task2(str);
		}
		else if (task == "3") {
			task3();
			string answer;
			while (true) {
				cout << "Хотите ли прочитать данные из файла?\n";
				cin >> answer;
				if (answer == "да") {
					readFile();
					break;
				}
				else if (answer == "нет") {
					cout << "Продолжаем!\n";
					break;
				}
				else {
					cout << "Извините, я не понял ваш ответ, повторите ввод\n";
				}
			}
		}
		else {
			cout << "Извините, я не понял, какое задание вам нужно, повторите ввод\n";
			continue;
		}

		while (true) {
			string answer;
			cout << "Хотите ли вы выйти? (да, нет)\n";
			cin >> answer;
			if (answer == "да") {
				flag = false;
				cout << "Удачи!\n";
				break;
			}
			else if (answer == "нет") {
				cout << "Продолжаем!\n";
				break;
			}
			else {
				cout << "Извините, я не понял ваш ответ, повторите ввод\n";
			}
		}
	}

}

void readFile() { //чтение файла
	string names[5];
	string prices[5];
	ifstream fromfile;
	fromfile.open("Y:\\Students\\ИСТ-222\\Торсунов Иван\\wristwatch.txt"); // старт потока
	if (!fromfile) { //срабатывает в случае недоступа к файлу
		cout << "Error of file opening";
	}
	else {
		string strnames;
		string strprices;
		int pos = 0;
		getline(fromfile, strnames); //считываю строку с названиями часов
		getline(fromfile, strprices); //считываю сроку с ценами часов
		fromfile.close(); //закрытие потока
		for (int i = 0; i < 5; i++) { // собираю в массивы данные о часах
			names[i] = strnames.substr(pos, 32); //разбиваю строку по 32 символа
			prices[i] = strprices.substr(pos, 32);
			pos += 32; //изменяю начальную позицию
		}
		bool flag = true;
		while (flag) {
			int wwnumber;
			string answer;
			cout << "Какие часы вы хотите посмотреть? (введите число от 1 до 5)\n";
			cin >> wwnumber;
			if (wwnumber >= 1 && wwnumber <= 5) {
				cout << "Название: " << names[wwnumber - 1] << "\n";
				cout << "Цена: " << prices[wwnumber - 1] << "\n";
				while (true) {
					cout << "Хотите посмотреть еще?\n";
					cin >> answer;
					if (answer == "да") {
						break;
					}
					else if (answer == "нет") {
						flag = false;
						break;
					}
					else {
						cout << "Извините, я не понял ваш ответ, повторите ввод\n";
					}
				}
			}
		}
	}
}
