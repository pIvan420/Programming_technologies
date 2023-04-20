#include "DigitalWatch.h"
using namespace std;

DigitalWatch:: DigitalWatch(string name, int price, string country, bool pedometer) : Watch(name, price, country) {
	this->pedometer = pedometer;
}

DigitalWatch:: ~DigitalWatch(){}

bool DigitalWatch::is_pedometer() {
	return pedometer;
}