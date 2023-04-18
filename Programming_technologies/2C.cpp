#include <iostream>
using namespace std;


void firstTask();
void secondTask();


int main2() {
	setlocale(LC_ALL, "");

	firstTask();
	secondTask();
	return 0;
}


void firstTask() {
	unsigned long int firstNum;
	int secondNum;
	cout << "Введите первое число: ";
	cin >> firstNum; //ввод первого числа
	cout << "Введите второе число: ";
	cin >> secondNum; //ввод второго числа
	cout << "Размер отведенной памяти: " << sizeof(firstNum + secondNum) << "\n"; //вычисление суммы и отведенной памяти
	cout << (double)(firstNum + secondNum) << "\n"; //явное приведение суммы
}


void secondTask() {
	int minNum;
	int const arrLen = 5; //длина массива
	signed long int arr[arrLen];
	for (int i = 0; i < arrLen; i++) {
		cout << "Введите " << i + 1 << " число: ";
		cin >> arr[i]; //ввод числа в массив
	}
	minNum = arr[0]; //устанавливаем первый элемент массива, как минимальный, для сравнения с другими элементами
	for (int i = 1; i < arrLen; i++) {
		if (minNum > arr[i]) { //если минимальное число больше, чем элемент массива, то минимальное число становится этим элементом
			minNum = arr[i];
		}
	}
	cout << "Минимальное число: " << minNum; //вывод минимального числа
}
