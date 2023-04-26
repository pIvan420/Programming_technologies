#include "MechanicalWatch2.h"
using namespace std;

MechanicalWatch2::MechanicalWatch2(string name, int price, string country, string mechanism_type) : Watch2(name, price, country) {
	this->mechanism_type = mechanism_type;
}

MechanicalWatch2:: ~MechanicalWatch2() {}

string MechanicalWatch2::get_mechanism_type() {
	return mechanism_type;
}