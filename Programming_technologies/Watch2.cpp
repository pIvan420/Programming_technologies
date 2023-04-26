#include "Watch2.h"
using namespace WatchNameSpace;

Watch2::Watch2(string name, int price, string country) {
	this->name = name;
	this->price = price;
	this->country = country;
	count++;
}

Watch2:: ~Watch2() {}

string Watch2::get_name() {
	return name;
}

int Watch2::get_price() {
	return price;
}

string Watch2::get_country() {
	return country;
}

int Watch2::get_count() {
	return count;
}

bool Watch2::operator<(Watch2 ww2) {
	if (price < ww2.price) {
		return true;
	}
	else{
		return false;
	}
}

