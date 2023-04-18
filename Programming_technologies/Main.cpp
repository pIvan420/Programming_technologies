#include <iostream>
#include "DigitalWatch.h"
#include "MechanicalWatch.h"
using namespace std;

int main() {
	DigitalWatch wws[6] = { DigitalWatch("Casio G-SHOCK GA-900-4AER", 11990, "Япония", true), DigitalWatch("Daniel Wellington DW00100510", 9450, "Швеция", true), DigitalWatch("M2Z M2Z-200-001", 52000, "Италия", false),
		DigitalWatch("Garmin 010-02157-11", 115000, "США", false), DigitalWatch("Casio Baby-G BLX-565-3E", 9990, "Япония", true), DigitalWatch("The Electricianz ZZ-A1A/04-CRW", 25070, "Швейцария", false) };
	int length = sizeof(wws) / sizeof(wws[0]);
	cout << get_most_expensive_watch(wws, length).get_price();
}