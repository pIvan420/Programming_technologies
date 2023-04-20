#include "MechanicalWatch.h"
using namespace std;

MechanicalWatch:: MechanicalWatch(string name, int price, string country, string mechanism_type) : Watch(name, price, country) {
	this->mechanism_type = mechanism_type;
}

MechanicalWatch:: ~MechanicalWatch(){}

string MechanicalWatch::get_mechanism_type() {
	return mechanism_type;
}