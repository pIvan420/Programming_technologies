#pragma once
#include "Watch.h"
class MechanicalWatch : private Watch
{
private:
	std::string mechanism_type;
public:
	MechanicalWatch(std::string name, int price, std::string country, std::string mechanism_type) : Watch(name, price, country) {
		this->mechanism_type = mechanism_type;
	}
	std::string get_mechanism_type();
};

