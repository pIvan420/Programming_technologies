#include "DigitalWatch2.h"
using namespace std;

DigitalWatch2::DigitalWatch2(string name, int price, string country, bool pedometer) : Watch2(name, price, country) {
	this->pedometer = pedometer;
}

DigitalWatch2:: ~DigitalWatch2() {}

bool DigitalWatch2::is_pedometer() {
	return pedometer;
}