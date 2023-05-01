#include <iostream>
#include <string>
#include "Watch7A.cpp"
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	const int len = 5;
	Watch7A<double> watches[len] = { Watch7A<double>("Casio G-SHOCK GA-900-4AER", 11990, "������"),  Watch7A<double>("Daniel Wellington DW00100510", 9450, "������"), Watch7A<double>("M2Z M2Z-200-001", 52000, "������"),
		Watch7A<double>("Garmin 010-02157-11", 115000, "���"), Watch7A<double>("Casio Baby-G BLX-565-3E", 9990, "������")};
	//���������� ������� ������ ��� ���� double
	//����� ������� ���������
	Watch7A<double>* curwatch = &watches[0];
	for (int i = 1; i < len; i++) { 
		if (watches[i].get_price() > curwatch->get_price()) {
			curwatch = &watches[i];
		}
	}
	cout << "����� ������� ���������: " << curwatch->get_name() << endl;
	//���������� ����� ������������� �������������
	string country;
	int count = 0;
	cout << "������� �������������: ";
	cin >> country;
	for (int i = 0; i < len; i++) {
		if (watches[i].get_manufacturer() == country) {
			count++;
		}
	}
	cout << "���������� ����� �������������: " << count;
}