#pragma once
#include <string>
class Watch
{
private:
	std::string name;
	int price;
	std::string country;
public:
	Watch(std::string name, int price, std::string country) {
		this->name = name;
		this->price = price;
		this->country = country;
	}
	~Watch(){}
	std::string get_name();
	int get_price();
	std::string get_country();
	friend Watch get_most_expensive_watch(Watch watches[], int length);
};

Watch get_most_expensive_watch(Watch watches[], int length) {
	Watch curWatch = watches[0];
	for (int i = 1; i < length; i++) {
		if (curWatch.price < watches[i].price) {
			curWatch = watches[i];
		}
	}
	return curWatch;
}


