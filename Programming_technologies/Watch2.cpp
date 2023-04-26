#include "Watch2.h"
#include "DigitalWatch.h"

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

Watch2 get_most_expensive_watch(Watch2** watches, int length) {
	Watch2* curWatch = watches[0];
	for (int i = 1; i < length; i++) {
		if (curWatch < watches[i]) {
			curWatch = watches[i];
		}
	}
	return *curWatch;
}

Watch2 get_most_expensive_watch(Watch2** watches1, Watch2** watches2, int length) {
	Watch2* curWatch = watches1[0];
	for (int i = 1; i < length; i++) {
		if (curWatch < watches1[i]) {
			curWatch = watches1[i];
		}
	}
	for (int i = 0; i < length; i++) {
		if (curWatch < watches2[i]) {
			curWatch = watches2[i];
		}
	}
	return *curWatch;
}

