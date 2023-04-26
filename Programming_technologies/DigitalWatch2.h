#pragma once
#include "Watch2.h"
class DigitalWatch2 : public Watch2
{
private:
	bool pedometer;
public:
	DigitalWatch2(string name, int price, string country, bool pedometer);
	~DigitalWatch2();
	bool is_pedometer();
};

