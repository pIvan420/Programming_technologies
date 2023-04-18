#include <iostream>
#include <cstdlib> // библиотека с математикой
#include <string>
using namespace std;


class point //класс координаты на плоскости
{
private:
	double x, y;

public:
	double get_x() {
		return x;
	}
	double get_y() {
		return y;
	}
	point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	~point() {}

	friend double get_area(point* points);
};

double get_side(double x1, double x2) { //сторона прямоугольника
	double side;
	if ((x1 <= 0) == (x2 <= 0)) {
		side = abs(x1 - x2);
	}
	else {
		side = abs(x1) + abs(x2);
	}
	return side;
}

double get_hypotenuse(double x1, double x2, double y1, double y2) { //гипотенуза
	double hypotenuse = sqrt(pow(get_side(x1, x2), 2) + pow(get_side(y1, y2), 2));
	return hypotenuse;
}

double get_area(point* points) { //функция для поиска ширины
	double x1, x2, y1, y2;
	x1 = points[0].x;
	y1 = points[0].y;
	for (int i = 1; i < 4; i++) {
		if (points[i].x != x1) {
			x2 = points[i].x;
			break;
		}
	}
	for (int i = 1; i < 4; i++) {
		if (points[i].y != y1) {
			y2 = points[i].y;
			break;
		}
	}
	return get_side(x1, x2) * get_side(y1, y2);
}

class wristwatch { //класс часов
private:
	string name;
	int price;
	string country;
public:
	wristwatch(string name, int price, string country) { //задаю название, цену и страну производства
		this->name = name;
		this->price = price;
		this->country = country;
	}

	string get_name() {
		return name;
	}

	int get_price() {
		return price;
	}

	string get_country() {
		return country;
	}
};

int main4() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	point* points;
	points = new point[4]{ point(-4, 0), point(-4, 3), point(4, 3), point(4, 0) };
	cout << "Площадь прямоугольника: " << get_area(points) << "\n";
	wristwatch wws[6] = { wristwatch("Casio G-SHOCK GA-900-4AER", 11990, "Япония"), wristwatch("Daniel Wellington DW00100510", 9450, "Швеция"), wristwatch("M2Z M2Z-200-001", 52000, "Италия"),
		wristwatch("Garmin 010-02157-11", 115000, "США"), wristwatch("Casio Baby-G BLX-565-3E", 9990, "Япония"), wristwatch("The Electricianz ZZ-A1A/04-CRW", 25070, "Швейцария") };
	int maxprice = 0;
	for (int i = 0; i < 6; i++) {//поиск самых дорогих часов
		if (maxprice < wws[i].get_price()) {
			maxprice = wws[i].get_price();
		}
	}
	cout << "Масимальная цена часов: " << maxprice;
	return 0;
}
