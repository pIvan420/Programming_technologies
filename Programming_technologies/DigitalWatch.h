#pragma once
#include "Watch.h"
class DigitalWatch : public Watch
{
private:
	bool pedometer;
public:
	DigitalWatch(std::string name, int price, std::string country, bool pedometer) : Watch(name, price, country){
		this->pedometer = pedometer;
	}
	~DigitalWatch(){}
	bool is_pedometer();
};

