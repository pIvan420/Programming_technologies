#include "Watch.h"
#include "DigitalWatch.h"

Watch:: Watch(string name, int price, string country) {
	this->name = name;
	this->price = price;
	this->country = country;
}

Watch:: ~Watch() {}

string Watch::get_name() {
	return name;
}

int Watch::get_price() {
	return price;
}

string Watch::get_country() {
	return country;
}

Watch get_most_expensive_watch(Watch** watches, int length) {
	Watch* curWatch = watches[0];
	for (int i = 1; i < length; i++) {
		if (curWatch->get_price() < watches[i]->get_price()) {
			curWatch = watches[i];
		}
	}
	return *curWatch;
}
